N = int(input())
S = input()
T = input()   

for i in range(N):
    if T[i] != "*" and T[i] != S[i]:
        ans ="No"
        break
    else:
        ans ="Yes"        
print(ans)