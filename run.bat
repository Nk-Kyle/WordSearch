@echo off
cd src
gcc main.c color.c filereads.c solver.c words.c -o ../bin/main
cd ../bin
main
cd ..