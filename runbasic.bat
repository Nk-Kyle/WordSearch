@echo off
cd src
gcc main.c color.c filereads.c solver_basic.c words.c -o ../bin/mainbasic
cd ..
bin\mainbasic