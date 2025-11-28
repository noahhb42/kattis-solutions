from sys import*
d=list(map(int,stdin.read().split()))
n=d[0];a=[0]+d[1:n+1];s=a[:];p=n+2
for _ in[0]*d[n+1]:
 x=d[p];y=d[p+1];p+=2;s[x]+=a[y];s[y]+=a[x]
t=s[1:];print(t.index(min(t))+1)