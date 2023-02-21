def solve():
    n = int(input())
    s = input();
    t = input();
    if t.count('a')!=s.count('a') or t.count('b')!=s.count('b') or t.count('c')!=s.count('c'):
        print("NO\n")
        return
    j = 0;
    for i in range(n):
        if s[i]=='b': continue;
        while t[j]=='b': j+=1
        if(s[i]!=t[j] or (s[i]=='a' and i<j) or (s[i]=='c' and i > j)):
            print("NO\n")
            return
        j+=1
    print("YES\n")
        
for i in range (int(input())):
    solve()