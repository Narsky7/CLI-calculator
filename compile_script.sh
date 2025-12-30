#!/bin/bash
if [ -z "$1" ]; then
    echo "Usage: $0 code.c"
    exit 1
fi
gcc "$1" -o "${1%.*}" && ./"${1%.*}"
#Remember to change CRLF to LF