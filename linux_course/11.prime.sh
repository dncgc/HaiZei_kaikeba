#!/bin/bash

if [[ $# -ne 2 ]];then
    echo "Usage: $0 start end"
    exit
fi
Start=$1
End=$2

declare -a prime
sum=0
for (( i=2; i<=${End}; i++ ));do
    if [[ ${prime[$i]}x == x ]];then
        prime[0]=$[ ${prime[0]} + 1 ]
        prime[${prime[0]}]=$i
    fi
    for (( j=1; j<=${prime[0]}; j++ ));do
        num=$[ $i * ${prime[$j]} ]
        if [[ $num -gt ${End} ]];then
            break
        fi
        prime[$num]=1
        if [[ $[ $i % ${prime[$j]} ] -eq 0 ]];then
            break
        fi
    done
done

for (( i=1; i<=${prime[0]}; i++ ));do
    sum=$[ ${sum} + ${prime[$i]} ]
done

echo $sum
