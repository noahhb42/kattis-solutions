from math import log, sqrt, exp
n,p,s,v=map(float,input().split());n=int(n)
L=sqrt(2)*log(log(n)/log(2));A=n/(p*1e9);B=s/v
d=lambda c:A*L*exp(L*c)-B/c**2
lo,hi=1e-12,1
while d(hi)<=0:hi*=2
for _ in range(200):
    m=(lo+hi)/2
    if d(m)<=0:lo=m
    else: hi=m
c=(lo+hi)/2
t=A*exp(L*c)+B*(1+1/c)
print(t,c)