n,m=map(int,input().split());k=max(n,m)
p=lambda x:x>1 and all(x%i for i in range(2,int(x**.5)+1))
L=[['2','3','5','7']]
for _ in range(k-1):
 a=[]
 for s in L[-1]:
  for d in'0123456789':
   t=s+d
   if p(int(t)):a.append(t)
 L.append(a)
R=L[m-1];C=L[n-1]
P=[set()for _ in range(n+1)]
for s in C:
 for i in range(1,n+1):P[i].add(s[:i])
z=0;c=['']*m
def f(i):
 global z
 if i==n:z+=1;return
 for r in R:
  for j in range(m):
   t=c[j]+r[j]
   if t not in P[i+1]:break
  else:
   for j in range(m):c[j]+=r[j]
   f(i+1)
   for j in range(m):c[j]=c[j][:-1]
f(0)
print(z)