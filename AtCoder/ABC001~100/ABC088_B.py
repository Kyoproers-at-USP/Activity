N=int(input())
A=list(map(int,input().split()))
A.sort(reverse=True)
al,bo=0,0
for i,e in enumerate(A):
  if i%2==0:
    al+=e
  else:
    bo+=e
print(al-bo)