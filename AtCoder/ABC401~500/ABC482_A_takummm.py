s = input()

count = 0
for i in range(len(s)):
    if s[i] == "o":  
        count += 1

if count % 2 == 1:
    print("odd")
else:
    print("even")