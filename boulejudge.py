s=list(map(int,open(0).read().split()))
it=iter(s); jx, jy=next(it), next(it)
f=lambda x,y:(x-jx)**2+(y-jy)**2
R=[f(next(it),next(it)) for _ in range(6)]
B=[f(next(it),next(it)) for _ in range(6)]
mr, mb=min(R), min(B)
if mr<mb:
    print("JONNA"); print(sum(x<mb for x in R))
elif mb<mr:
    print("OPPONENTS"); print(sum(x<mr for x in B))
else:
    print("TIE")
