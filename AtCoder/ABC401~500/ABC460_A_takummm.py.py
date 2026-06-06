n= 0
N, M = map(int, input().split())
while M != 0:
    x = N % M
    M = x
    n = n + 1
print(n)  
  