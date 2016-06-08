#!bin/bash
gcc dom.c
./a.out > cout.txt
python afterc.py>out.txt
dot -Tps out.txt -o DTREE.ps
evince DTREE.ps