N = int(input())
L = list(map(int, input().split())) 
  
all_length = 0
for i in range(N):
    all_length += L[i] 

min_length = all_length
left_length = 0
for i in range(N):
    left_length = left_length + L[i]
    right_length = all_length - left_length
    min_length = min(min_length, abs(right_length - left_length))
        
print(min_length)
