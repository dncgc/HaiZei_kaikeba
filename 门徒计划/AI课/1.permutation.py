#!/usr/bin/env python
# coding=utf-8

def permutation(elements):
    if len(elements) == 0: return [[]]
    head = elements[0]
    remain_parts_result = permutation(elements[1:])
    return [r[:i] + [head] + r[i:] for i in range(len(elements)) for r in remain_parts_result]

print(permutation([1, 2, 3]))
