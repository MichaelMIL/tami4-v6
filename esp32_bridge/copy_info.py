# Pre-build: embed the master parameter_info.json (kept with the RE outputs) into the firmware.
Import("env")  # noqa: F821 (PlatformIO SCons)
import os, shutil

src = os.path.join(env["PROJECT_DIR"], "..", "PIC18F8621_decompiled", "parameter_info.json")  # noqa: F821
dst = os.path.join(env["PROJECT_DIR"], "embed", "param_info.json")  # noqa: F821
if os.path.exists(src) and (not os.path.exists(dst) or os.path.getmtime(src) > os.path.getmtime(dst)):
    shutil.copyfile(src, dst)
    print("copy_info: updated embed/param_info.json")
