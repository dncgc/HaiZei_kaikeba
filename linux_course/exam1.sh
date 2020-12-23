#!/bin/bash
read L M
sum=0
declare -a region

function is_overlap() {
    local start=$1
    local end=$2
    local i
    for i in ${!region[*]};do
        if [[ ${i}x == x ]];then
            region+=(${start} ${end})
            return
        fi
        if [[ $[ $i % 2 ] -eq 0 ]];then
            temp1=${region[$i]}
        else
            if [[ ${start} -ge ${temp1} ]];then
                if [[ ${end} -le ${region[$i]} ]];then
                    return
                fi
            fi
            if [[ ${start} -lt ${temp1} ]];then
                if [[ ${end} -gt ${region[i]} ]];then
                    region[$[$i-1]]=${start}
                    region[$i]=${end}
                    return
                elif [[ ${end} -ge ${temp1} ]];then
                    region[$[$i-1]]=${start}
                    return
                fi
            elif [[ ${start} -le ${region[$i]} ]];then
                if [[ ${end} -gt ${region[$i]} ]];then
                    region[$i]=${end}
                    return
                fi
            fi
        fi
    done
    region+=(${start} ${end})
    return
}

for (( i=0; i<M; i++));do
    read start end
    if [[ ${start} -lt 0 ]];then
        start=0
    fi
    if [[ ${end} -gt $L ]];then
        end=$L
    fi
    is_overlap ${start} ${end}
done

echo ${region[*]}
for i in ${!region[*]};do
    if [[ $[ $i % 2 ] -eq 0 ]];then
        temp=${region[$i]}
    else
        sum=$[ $sum + ${region[$i]} - ${temp} + 1 ]
    fi
done

echo $[ $L - $sum + 1 ]
