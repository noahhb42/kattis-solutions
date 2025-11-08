r=open(0).read().splitlines();it=iter(r)
n,m,s,k=map(int,next(it).split());D={c:j for j,c in enumerate(next(it).strip())}
F=set(int(x)-1 for x in next(it).split())
T=[[int(x)-1 for x in next(it).split()]for _ in range(n)]
q=int(next(it));o=[]
for _ in range(q):
    st=s-1
    for c in next(it):st=T[st][D[c]]
    o+=("accept"if st in F else"reject"),
print('\n'.join(o))