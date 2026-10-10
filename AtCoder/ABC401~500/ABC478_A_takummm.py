n,m = map(int, input().split())

X_list = []
X = m // n   #全員共通してもらえる個数
X_rest = m - n*X

i = 0
for i in range(n):
    X_list.append(X) 

for j in range(X_rest):
    X_list[j] = X+1
    
for k in range(n):
    print(X_list[k])