#!/bin/bash

# Usage: ./compare_logs.sh file1.log file2.log

if [ "$#" -ne 2 ]; then
  echo "Usage: $0 file1.log file2.log"
  exit 1
fi

# Strip timestamps and compare
if diff <(sed 's/^\[[^]]*\] //' "$1") <(sed 's/^\[[^]]*\] //' "$2") >/dev/null; then
  echo "identical!"
else
  echo "different!"
fi



