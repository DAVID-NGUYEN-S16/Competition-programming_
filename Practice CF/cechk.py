N = int(input())
i = 1
sum = 0.0

    
for i in range(1, N+1):
    sum = sum + (1.0 / (i * (i + 1.0)))
    i = i + 1
print((1 - sum) * 1000000000.0)