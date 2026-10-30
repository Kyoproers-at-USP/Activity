n,k = map(int,input().split())
a = list(map(int,input().split()))

count = 0
for i in range(n-1):
    if a[i] < k < a[i+1] or a[i+1] < k < a[i] or a[i] == k:
        count += 1
if a[i+1] == k:
    count += 1       
print(count)