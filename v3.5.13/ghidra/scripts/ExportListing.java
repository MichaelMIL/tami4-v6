// Export full disassembly listing (with function headers) to a text file.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;
import ghidra.program.model.address.*;
import java.io.*;

public class ExportListing extends GhidraScript {
    @Override
    public void run() throws Exception {
        String out = getScriptArgs()[0];
        try (PrintWriter pw = new PrintWriter(new FileWriter(out))) {
            Listing l = currentProgram.getListing();
            FunctionManager fm = currentProgram.getFunctionManager();
            pw.println("# functions: " + fm.getFunctionCount());
            for (CodeUnit cu : l.getCodeUnits(currentProgram.getMemory(), true)) {
                Address a = cu.getAddress();
                if (!a.getAddressSpace().getName().equals("CODE")) continue;
                Function f = fm.getFunctionAt(a);
                if (f != null) pw.println("\n;=== FUNCTION " + f.getName() + " @" + a);
                if (cu instanceof Instruction) {
                    pw.printf("%s  %s%n", a.toString(false), cu.toString());
                } else if (cu instanceof Data && ((Data) cu).isDefined()) {
                    pw.printf("%s  .data %s%n", a.toString(false), cu.toString());
                }
            }
        }
    }
}
