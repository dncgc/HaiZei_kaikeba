#!/usr/bin/env python
# coding=utf-8
import random

def quick_sort(elements):
    if not elements: return []

    pivot = random.choice(elements)

    return quick_sort([e for e in elements if e < pivot]) + [pivot] + quick_sort([e for e in elements if e > pivot])

numbers = [random.randint(-100, 100) for _ in range(200)]
print(quick_sort(numbers))
