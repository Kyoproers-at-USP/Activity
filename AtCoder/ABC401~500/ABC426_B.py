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
SL = lambda: list(input())
s=SL()

al={}

for i in s:
    if i not in al:
        al[i]=1
    else:
        al[i]+=1

for k,v in al.items():
    if v==1:
        print(k)
        sys.exit()