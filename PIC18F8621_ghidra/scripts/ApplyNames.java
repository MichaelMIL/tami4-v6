// Apply names from a TSV file: kind<TAB>address<TAB>name[<TAB>comment]
// kind = func (CODE space function), rom (CODE space data label) or var (DATA space label).
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.nio.file.*;

public class ApplyNames extends GhidraScript {
    @Override
    public void run() throws Exception {
        AddressFactory af = currentProgram.getAddressFactory();
        SymbolTable st = currentProgram.getSymbolTable();
        int ok = 0, bad = 0;
        for (String line : Files.readAllLines(Paths.get(getScriptArgs()[0]))) {
            if (line.isBlank() || line.startsWith("#")) continue;
            String[] p = line.split("\t");
            boolean func = p[0].equals("func"); boolean rom = p[0].equals("rom");
            Address a = af.getAddressSpace((func || rom) ? "CODE" : "DATA").getAddress(Long.decode(p[1]));
            String comment = p.length > 3 ? p[3] : null;
            try {
                if (func) {
                    Function f = getFunctionAt(a);
                    if (f == null) { println("no function at " + a); bad++; continue; }
                    f.setName(p[2], SourceType.USER_DEFINED);
                    if (comment != null) f.setComment(comment);
                } else {
                    Symbol s = st.getPrimarySymbol(a);
                    if (s != null && s.getSource() != SourceType.DEFAULT) s.setName(p[2], SourceType.USER_DEFINED);
                    else st.createLabel(a, p[2], SourceType.USER_DEFINED).setPrimary();
                    if (comment != null) currentProgram.getListing().setComment(a, CodeUnit.PLATE_COMMENT, comment);
                }
                ok++;
            } catch (Exception e) { println("failed " + line + ": " + e.getMessage()); bad++; }
        }
        println("applied " + ok + ", failed " + bad);
    }
}
