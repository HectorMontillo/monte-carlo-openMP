#!/bin/bash
echo "Bash version ${BASH_VERSION}..."
gcc $1.c -o $1 
echo "Excuted: gcc $1.c -o $1 "