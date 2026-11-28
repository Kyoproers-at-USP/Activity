n,m = map(int, input().split())
a = list(map(int, input().split()))

for i in range(m):
    x = []
    x = list(map(int, input().split()))
    a.remove(x[0])
    a.append(x[1])
a.sort()
print(*a)