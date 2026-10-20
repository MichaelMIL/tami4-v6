// Decompile every function to <outdir>/<addr>.c and write <outdir>/index.tsv
// (address, name, size, callers, callees).
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.listing.*;
import java.io.*;
import java.util.*;

public class DecompileAll extends GhidraScript {
    @Override
    public void run() throws Exception {
        File dir = new File(getScriptArgs()[0]);
        dir.mkdirs();
        DecompInterface di = new DecompInterface();
        di.openProgram(currentProgram);
        try (PrintWriter idx = new PrintWriter(new FileWriter(new File(dir, "index.tsv")))) {
            for (Function f : currentProgram.getFunctionManager().getFunctions(true)) {
                if (monitor.isCancelled()) break;
                String addr = String.format("%06x", f.getEntryPoint().getOffset());
                DecompileResults r = di.decompileFunction(f, 60, monitor);
                String c = r.decompileCompleted() ? r.getDecompiledFunction().getC() : "/* decompile failed: " + r.getErrorMessage() + " */\n";
                try (PrintWriter pw = new PrintWriter(new FileWriter(new File(dir, addr + ".c")))) {
                    pw.print("// address 0x" + addr + "\n" + c);
                }
                StringBuilder callers = new StringBuilder(), callees = new StringBuilder();
                for (Function g : f.getCallingFunctions(monitor)) callers.append(String.format("%06x,", g.getEntryPoint().getOffset()));
                for (Function g : f.getCalledFunctions(monitor)) callees.append(String.format("%06x,", g.getEntryPoint().getOffset()));
                idx.printf("%s\t%s\t%d\t%s\t%s%n", addr, f.getName(), f.getBody().getNumAddresses(), callers, callees);
            }
        }
        di.dispose();
    }
}
