X = input()
Y = input()
s_11 = X[0]
s_12 = X[1]
s_21 = Y[0]
s_22 = Y[1]

if s_11 == "A":
    if s_22 == "D":
        print("No")
    else:
        print("Yes")
        
if s_21 == "A":
    if s_12 == "D":
        print("No")
    else:
        print("Yes")

if s_12 == "A":
    if s_21 == "D":
        print("No")
    else:
        print("Yes")
        
if s_22 == "A":
    if s_11 == "D":
        print("No")
    else:
        print("Yes")