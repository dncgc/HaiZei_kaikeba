#!/bin/bash
read N

declare -a Prime
Prime[0]=0
for (( i=2; i<100000; i++ ));do
    if [[ ${Prime[i]}x == x ]];then
        Prime[0]=$[ ${Prime[0]} + 1 ]
        Prime[${Prime[0]}]=$i
    fi
    if [[ ${Prime[0]} -eq $N ]];then
        echo ${Prime[${Prime[0]}]}
        break
    fi
    for (( j=1; j<=${Prime[0]}; j++));do
        temp=$[ $i * ${Prime[$j]} ] 
        if [[ ${temp} -gt 100000 ]];then
            break
        fi
        Prime[${temp}]=1
        if [[ $[ $i % ${Prime[$j]} ] -eq 0 ]];then
            break
        fi
    done
done

