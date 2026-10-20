// Create functions at the PIC18 reset and interrupt vectors before analysis.
import ghidra.app.script.GhidraScript;
public class SeedEntries extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[][] v = {{"0x0","reset_vector"},{"0x8","high_isr_vector"},{"0x18","low_isr_vector"}};
        for (String[] e : v) {
            var a = currentProgram.getAddressFactory().getAddressSpace("CODE").getAddress(Long.decode(e[0]));
            disassemble(a);
            createFunction(a, e[1]);
        }
    }
}
