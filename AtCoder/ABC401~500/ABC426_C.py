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
N,Q=IS()
n=0
al=[1 for i in range(N)]
for _ in range(Q):
    l,r=IS()
    ans=0
    if n<l:
        for i in range(n ,l):
            ans+=al[i]
        al[r-1]+=ans
        n=l
    print(ans)
