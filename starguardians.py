from sys import*
d=list(map(int,stdin.read().split()))
n=d[0];a=d[1:n+1];s=d[n+1:];s.sort()
b=m=0.
for i in range(1,n+1):
 b+=s[-i];t=(b+a[i-1])/i
 if t>m:m=t
print(m)