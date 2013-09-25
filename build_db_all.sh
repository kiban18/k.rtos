#!/bin/bash

ctags -R

rm -rf ./cscope.files ./cscope.out
find . \( -name '*.c' -o -name '*.cpp' -o -name '*.cc' -o -name '*.h' -o -name '*.s' -o -name '*.S' \) -print > cscope.files
cscope -b -i cscope.files

gtags
