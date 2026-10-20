#!/usr/bin/env python3
"""Reversible tests of the serial write commands on the PIC18F8621 dispenser.

Every test writes a test value, reads it back, restores the original value and verifies the restore.
Default run (single-item commands only):   python3 run_write_tests.py
Also test the bulk commands RPL and RCL:  python3 run_write_tests.py --bulk
  (RPL resets ALL parameters to factory defaults; RCL clears ALL usage counters. Both are restored afterwards
   from the baseline with SP / g. Keep PIC18F8621.hex as a last-resort backup: it contains the EEPROM.)
Log: write_test_log.txt (every command and reply).
"""
import sys, ser

ok = lambda b: "PASS" if b else "FAIL"
results = []

def gp(i): return ser.cmd(f"GP {i}")[0]
def gc(i): return ser.cmd(f"GC {i}")[0]
def gpl_row(i):
    for l in ser.cmd("GPL"):
        if l.startswith(f"{i},"): return l.split(",")
def check(name, cond, detail=""):
    results.append((name, ok(cond), detail)); print(f"{ok(cond)}  {name}  {detail}")

# baseline
base_p = {int(l.split(",")[0]): l.split(",") for l in open("baseline_GPL.txt").read().split("\n")[1:] if "," in l}
base_c = {int(l.split(",")[0]): l.split(",") for l in open("baseline_GCL.txt").read().split("\n")[1:] if "," in l}

# 1. SP / RP on WKUPMINUTE1 (index 55, value 0, default 0, range 0-59; wake-up timers are disabled on this unit)
orig = gp(55)
ser.cmd("SP 55,7");   v = gp(55); check("SP 55,7 sets value", v == "7", f"read {v}")
ser.cmd("RP 55");     v = gp(55); check("RP 55 restores default", v == base_p[55][5], f"read {v}")
if gp(55) != orig: ser.cmd(f"SP 55,{orig}")
check("WKUPMINUTE1 back to original", gp(55) == orig)

# 2. SMN / SMX on TMMIUPDATERATE (index 36, value 10, range 1-100)
mn, mx = base_p[36][2], base_p[36][3]
ser.cmd("SMN 36,2");  r = gpl_row(36); check("SMN 36,2 sets minimum", r[2] == "2", f"row {r}")
ser.cmd(f"SMN 36,{mn}"); r = gpl_row(36); check("minimum restored", r[2] == mn, f"row {r}")
ser.cmd("SMX 36,99"); r = gpl_row(36); check("SMX 36,99 sets maximum", r[3] == "99", f"row {r}")
ser.cmd(f"SMX 36,{mx}"); r = gpl_row(36); check("maximum restored", r[3] == mx, f"row {r}")

# 3. RC / g on counter FM (index 6, a minute counter)
before = int(gc(6))
ser.cmd("RC 6");      v = int(gc(6)); check("RC 6 clears counter", v <= 1, f"read {v}")
ser.cmd(f"g06 {before}"); v = int(gc(6)); check("g06 <value> restores counter", abs(v - before) <= 1, f"read {v}, wanted {before}")

# 4. XC with a read-only target (entry 4 = ST)
r = ser.cmd("XC 4"); check("XC 4 executes ST", any("HEATER" in l for l in r), " / ".join(r[:3]))

if "--bulk" in sys.argv:
    # 5. RPL then restore every parameter value from baseline
    ser.cmd("RPL")
    after = {int(l.split(",")[0]): l.split(",") for l in ser.cmd("GPL")[1:] if "," in l}
    check("RPL resets values to defaults", all(after[i][4] == after[i][5] for i in after if i != 0))
    for i, row in base_p.items():
        if i and after[i][4] != row[4]: ser.cmd(f"SP {i},{int(row[4]) & 0xFF}")
    final = {int(l.split(",")[0]): l.split(",") for l in ser.cmd("GPL")[1:] if "," in l}
    diff = [i for i in base_p if final[i][4] != base_p[i][4]]
    check("all parameters restored after RPL", not diff, f"differences at {diff}")
    # 6. RCL then restore every counter with g
    ser.cmd("RCL")
    z = {int(l.split(",")[0]): l.split(",") for l in ser.cmd("GCL")[1:] if "," in l}
    check("RCL clears counters", all(int(z[i][2]) <= 1 for i in z))
    for i, row in base_c.items(): ser.cmd(f"g{i:02d} {row[2]}")
    final = {int(l.split(",")[0]): l.split(",") for l in ser.cmd("GCL")[1:] if "," in l}
    diff = [i for i in base_c if abs(int(final[i][2]) - int(base_c[i][2])) > 3]
    check("all counters restored after RCL", not diff, f"differences at {diff}")

print("\nSummary:"); [print(f"  {r}  {n}") for n, r, d in results]
