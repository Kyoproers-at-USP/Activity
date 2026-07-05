cnt = 0
n, m = map(int, input().split())
while m != 0:
    x = n % m
    m = x
    cnt = cnt + 1
print(cnt)   