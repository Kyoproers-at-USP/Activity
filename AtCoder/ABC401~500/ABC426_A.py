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

X,Y=SS()
al={ "Ocelot":1, "Serval":2, "Lynx":3}
if al[X]>=al[Y]:
    print("Yes")
else:
    print("No")