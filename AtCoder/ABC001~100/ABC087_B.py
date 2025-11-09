ii=lambda:int(input())
A =ii()
B=ii()
C=ii()
X=ii()
al=set()

for i in range(A+1):
  for j in range(B+1):
    for k in range(C+1):
      if i*500+j*100+k*50==X:
        al.add(str(i)+str(j)+str(k))

print(len(list(al)))