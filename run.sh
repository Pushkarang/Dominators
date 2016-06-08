#!/bin/bash
python dom.py >out.txt
if [ $? -eq 0 ]
then
dot -Tps out.txt -o DominatorTree.ps
if [ $? -eq 0 ]
then
evince DominatorTree.ps
fi
fi