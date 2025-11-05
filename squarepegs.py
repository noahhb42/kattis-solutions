t=iter(open(0).read().split())
n,m,k=map(int,[next(t),next(t),next(t)])
H=sorted(2*int(next(t))**2 for _ in range(n))
P=sorted([2*int(next(t))**2 for _ in range(m)]+[int(next(t))**2 for _ in range(k)])
i=0
for h in H:
    if i<len(P) and P[i]<h:i+=1
print(i)
