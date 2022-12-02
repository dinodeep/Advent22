#!/bin/bash

if [ -d $1 ]; then
    echo Directory exists
else 
    echo Constructing directory and files for $1

    mkdir $1
    cd $1
    touch easyinput.txt hardinput.txt part1.cpp part2.cpp

    echo Done creating files
fi
