n=int(input())
al=[0]*(n+1)
for i in range(1,n+1):
  for j in range(0, n+1, i):
    al[j]+=1

ans=0
for i,e in enumerate(al):
  if e==8 and i%2==1:
    ans+=1
print(ans)