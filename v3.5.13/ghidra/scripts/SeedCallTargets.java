// Disassemble and create functions at every CALL target found by a linear sweep
// (file: address<TAB>count per line), then report Ghidra error bookmarks.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import java.nio.file.*;

public class SeedCallTargets extends GhidraScript {
    @Override
    public void run() throws Exception {
        AddressSpace code = currentProgram.getAddressFactory().getAddressSpace("CODE");
        int made = 0;
        for (String line : Files.readAllLines(Paths.get(getScriptArgs()[0]))) {
            Address a = code.getAddress(Long.decode(line.split("\t")[0]));
            if (getInstructionAt(a) == null) disassemble(a);
            if (getFunctionAt(a) == null && getInstructionAt(a) != null && createFunction(a, null) != null) made++;
        }
        println("functions created: " + made + ", total: " + currentProgram.getFunctionManager().getFunctionCount());
        var bm = currentProgram.getBookmarkManager();
        var it = bm.getBookmarksIterator("Error");
        int n = 0;
        while (it.hasNext() && n < 40) { var b = it.next(); println("ERR " + b.getAddress() + " " + b.getCategory() + ": " + b.getComment()); n++; }
    }
}
