I = lambda :list(map(int,input().split()))
n = int(input())
p = I()
color = I()
print(1 + sum(color[i]!=color[x-1] for i, x in enumerate(p,1)))