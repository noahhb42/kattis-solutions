s=open(0).read().splitlines()
n=int(s[0]);A=[list(map(int,s[i].split()))for i in range(1,n+1)]
m="ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 "
t=s[n+1];x=[m.find(c)for c in t]+[36]*(-len(t)%n)
r=""
for i in range(0,len(x),n):
    v=x[i:i+n]
    for R in A:r+=m[sum(p*q for p,q in zip(R,v))%37]
print(r)