r=open(0).read().split();n=int(r[0]);B=[0]*(n+1);o=[];i=2
def u(x,d):
    while x<=n:B[x]+=d;x+=x&-x
def q(x):
    s=0
    while x:s+=B[x];x-=x&-x
    return s
while i<len(r):
    if r[i][0]=='F':
        j=int(r[i+1]);u(j,1-2*(q(j)-q(j-1)));i+=2
    else:
        l=int(r[i+1]);j=int(r[i+2]);o+=str(q(j)-q(l-1)),
        i+=3
print('\n'.join(o))
