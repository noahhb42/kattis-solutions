import collections
input()
input()
A=[*map(int,input().split())]
B=[*map(int,input().split())]
C=collections.Counter(b-a for b in B for a in A if b-a>=0)
s,ans=max((C[k],-k)for k in C) if C else (0,0)
print(-ans)