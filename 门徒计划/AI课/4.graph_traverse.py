#!/usr/bin/env python
# coding=utf-8

user_information = {
    'name': ['老王', '老刘', '老张'],
    'links': ['小美 小梅 大花', '小梅 小李', '建军 建国 小李']
}

import pandas as pd
dataframe = pd.DataFrame.from_dict(user_information)
dataframe
simple_graph = {
    'A': 'B C D'.split(),
    'B': 'A'.split(),
    'C': 'A E'.split(),
    'D': 'A'.split(),
    'E': 'F C G W'.split(),
    'W': 'E'.split(),
    'F': 'H I E'.split(),
    'G': 'H E'.split(),
    'H': 'I F E'.split(),
}

import networkx as nx
nx.draw(nx.Graph(simple_graph), with_lables=True)
