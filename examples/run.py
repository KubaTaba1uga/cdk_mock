#!/usr/bin/env python3
import os
import subprocess
from pathlib import Path


def run_script(script_path):
    script_path = script_path.resolve()
    print(f"\n🔧 Compiling in: {script_path.parent}")
    try:
        subprocess.run(
            ["bash", str(script_path)], check=True, cwd=str(script_path.parent)
        )
        print("✅ Compile succeeded.")
        return True
    except subprocess.CalledProcessError as e:
        print(f"❌ Compile failed with exit code {e.returncode}")
        return False


def test_binaries(build_dir):
    build_dir = build_dir.resolve()
    passed = True
    found_binary = False
    for bin_file in build_dir.glob("*"):
        if (
            bin_file.is_file()
            and os.access(bin_file, os.X_OK)
            and "compile.sh" not in str(bin_file)
        ):
            found_binary = True
            print(f"\n🚀 Running binary: {bin_file}")
            try:
                subprocess.run([str(bin_file)], check=True)
                print("✅ Run succeeded.")
            except subprocess.CalledProcessError as e:
                print(f"❌ Runtime error (exit code {e.returncode}) in {bin_file}")
                passed = False
    if not found_binary:
        print("⚠️  No binaries found in build directory.")
    return passed and found_binary


def main():
    root = Path(__file__).resolve().parent
    example_scripts = sorted(root.glob("*/compile.sh"))

    if not example_scripts:
        print("❌ No compile.sh scripts found.")
        return

    overall_pass = True
    for script in example_scripts:
        script_dir = script.parent.resolve()
        build_dir = script_dir / "build"

        if not build_dir.exists():
            build_dir = script_dir

        if run_script(script):
            if not test_binaries(build_dir):
                overall_pass = False
        else:
            overall_pass = False

    print("\n====================================")
    if overall_pass:
        print("✅ All examples compiled and ran successfully.")
    else:
        print("❌ Some examples failed. Check logs above.")
    print("====================================")


if __name__ == "__main__":
    main()
