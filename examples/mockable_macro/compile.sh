#!/bin/bash

set -xeu

gcc -DDEBUG example_1.c test_example_1.c -o test_example_1
gcc -DDEBUG example_2.c test_example_2.c -o test_example_2
