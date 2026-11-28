n = int(input())
s = input()
ans = []
for i in range(n):
    if s[i] == "A":
        ans.append("Alpha")
    elif s[i] == "B":
        ans.append("Bravo")
    else:
        ans.append("Charlie")
print(*ans)