#!/bin/bash
for file in *.c
do 
    vi +':w ++ff=unix' +':q' "$file"
done
