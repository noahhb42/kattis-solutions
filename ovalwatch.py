n,m=map(int,input().split())
r=[*range(n)]
s=[]
for _ in range(m):
    a,b=map(int,input().split())
    s.append((b,a))
s.sort(reverse=1)
for b,a in s:
    r[a],r[a+1]=r[a+1],r[a]
print(*r)