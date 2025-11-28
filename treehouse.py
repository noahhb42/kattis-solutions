from sys import*
a=list(map(int,stdin.read().split()))
n=a[0]
p=[a[i]+a[i+1]*1j for i in range(1,2*n,2)]
s=set(p)
c=0
for i in range(n):
 z=p[i]
 for j in range(i+1,n):
  w=p[j];v=w-z
  if z+v*1j in s and w+v*1j in s:c+=1
  if z-v*1j in s and w-v*1j in s:c+=1
print(c//4)