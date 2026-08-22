N = int(input())
L = list(map(int, input().split())) 
  
all_length = 0
for i in range(N):
    all_length += L[i] 

min_length = all_length
left_length = 0
for i in range(N):
    right_length = 0
    left_length = left_length + L[i]
    right_length = all_length - left_length
    if  abs(left_length - right_length) < min_length:
        min_length = abs(left_length - right_length) 
        
print(min_length)
