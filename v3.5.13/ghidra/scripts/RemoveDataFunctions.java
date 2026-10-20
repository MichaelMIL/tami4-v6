// Remove functions (and their disassembly) that were created on data. Args: hex addresses.
import ghidra.app.script.GhidraScript;
public class RemoveDataFunctions extends GhidraScript {
    @Override
    public void run() throws Exception {
        var code = currentProgram.getAddressFactory().getAddressSpace("CODE");
        for (String s : getScriptArgs()) {
            var a = code.getAddress(Long.decode(s));
            var f = getFunctionAt(a);
            if (f == null) { println("none at " + s); continue; }
            var body = f.getBody();
            removeFunction(f);
            clearListing(body);
            println("removed " + s);
        }
    }
}
