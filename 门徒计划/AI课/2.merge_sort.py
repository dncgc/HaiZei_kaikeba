#!/usr/bin/env python
# coding=utf-8

def merge_sort(elements):
    if len(elements) == 1: return elements

    mid = len(elements) // 2
    left, right = merge_sort(elements[:mid]), merge_sort(elements[mid:])
    sorted_result = []
    while left and right:
        left_head = left[0]
        right_head = right[0]
        if left_head < right_head:
            sorted_result.append(left_head)
            left.pop(0)
        else:
            sorted_result.append(right_head)
            right.pop(0)
    sorted_result += (left or right)
    return sorted_result

import random
numbers = [random.randint(-100,100) for _ in range(200)]
print(merge_sort(numbers))
