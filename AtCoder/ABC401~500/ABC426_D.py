import sys
from bisect import bisect_left, bisect_right, bisect
from heapq import heappush, heappop
from itertools import accumulate, combinations, permutations, product
from math import gcd, ceil, floor, sqrt
from collections import deque, Counter, defaultdict
from sortedcontainers import SortedList, SortedDict, SortedSet
from atcoder.segtree import SegTree
from atcoder.fenwicktree import FenwickTree
from copy import deepcopy
from atcoder.dsu import DSU
IN = lambda: input()
II = lambda: int(input())
SS = lambda: input().split()
IS = lambda: map(int, input().split())
IL = lambda: list(map(int, input().split()))
SL = lambda: list(input().split())
def k(c1, c2, m):
    return (c1-m)*2+c2

def num(n, s):
    o=0
    x=0
    c1,c0=0,0
    m0,m1=0,0
    for i in s:
        if i=="1":
            o+=1
            x=0
            c1+=1
            m1=max(m1, o)
        else:
            x+=1
            o=0
            c0+=1
            m0=max(m0, x)
    return min(k(c1, c0, m1), k(c0, c1, m0))

T=II()
for _ in range(T):
    n=II()
    s=list(input())
    print(num(n, s))

