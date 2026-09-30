n,d = map(int, input().split())
x = list(map(int, input().split()))

count = 0
new_list = []
for i in range(len(x)):
    if  all(i == k or abs(x[i]-x[k]) >= d  for k in range(len(x))):
        count += 1
        new_list.append(i+1)
     
print(count)
print(*new_list)