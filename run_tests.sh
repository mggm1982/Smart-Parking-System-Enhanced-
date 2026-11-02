#!/bin/bash
# Usage: ./run_tests.sh path/to/your_program_executable
# Feeds every .in file to the program and compares with the saved .out file.
EXE=${1:-./parking}; pass=0; fail=0
for f in training_data/*.in testing_data/*.in; do
  if diff -q <("$EXE" < "$f") "${f%.in}.out" >/dev/null; then pass=$((pass+1)); else fail=$((fail+1)); echo "DIFF: $f"; fi
done
echo "Matched: $pass   Different: $fail"
