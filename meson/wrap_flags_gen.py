#!/usr/bin/env python3
import sys

# Usage: ./wrap_flag_gen.py malloc free
funcs = sys.argv[1:]
print(" ".join(f"-Wl,--wrap={f}" for f in funcs))
