a=open(0).read().split();n,m=map(int,a[:2]);g=a[2:2+n]
i=j=s=0;v=set();d={'N':(-1,0),'S':(1,0),'W':(0,-1),'E':(0,1)}
while 1:
    if not(0<=i<n and 0<=j<m):print("Out");break
    if (i,j) in v:print("Lost");break
    c=g[i][j]
    if c=='T':print(s);break
    v.add((i,j));di,dj=d[c];i+=di;j+=dj;s+=1
