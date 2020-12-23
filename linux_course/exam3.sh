#!/bin/bash
str=""
read str
echo ${str} | tr -s -c "a-zA-Z" "\n" | sort | uniq -c | sort -n -r | head -n 3
