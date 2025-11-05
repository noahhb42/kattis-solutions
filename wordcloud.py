from math import ceil
it=iter(open(0).read().split());o=[];i=1
while True:
    W=int(next(it));N=int(next(it))
    if W==0 and N==0:break
    a=[];mx=0
    for _ in range(N):
        s=next(it);c=int(next(it));a.append((s,c));mx=max(mx,c)
    d=mx-4;H=0;w=0;rh=0
    for s,c in a:
        P=8+(40*(c-4)+d-1)//d
        ww=(9*len(s)*P+15)//16
        if w and w+10+ww>W:H+=rh;w=0;rh=0
        if w:w+=10
        w+=ww;rh=max(rh,P)
    H+=rh
    o.append(f"CLOUD {i}: {H}");i+=1
print('\n'.join(o))
