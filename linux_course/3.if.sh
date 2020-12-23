#!/bin/bash
#read a
#if [[ ${a} -gt 10 ]];then
#    echo "$a > 10"
#elif [[ ${a} -eq 10 ]];then
#    echo "$a = 10"
#else
#    echo "${a} < 10"
#fi
TargetFile="a.c"
if [[ -r ${TargetFile} ]];then
    gcc a.c -o a
    ./a
else
    echo "${TargetFile} not Found!"
fi
