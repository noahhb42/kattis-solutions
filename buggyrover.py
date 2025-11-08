from itertools import permutations as P
a=open(0).read().split();R=int(a[0]);C=int(a[1]);G=a[2:2+R];S=a[2+R]
for i,r in enumerate(G):
    if'S'in r:x=i;y=r.find('S');break
D="NESW";dr=[-1,0,1,0];dc=[0,1,0,-1];P=list(P(range(4)));INF=10**9;dp=[0]*24
for ch in S:
    U=[0]*4
    for k in range(4):
        i=x+dr[k];j=y+dc[k];U[k]=0<=i<R and 0<=j<C and G[i][j]!='#'
    t=D.index(ch);nd=[INF]*24;m=min(dp)
    for j,q in enumerate(P):
        for k in q:
            if U[k]:
                if k==t:nd[j]=min(dp[j],m+1)
                break
    dp=nd;x+=dr[t];y+=dc[t]
print(min(dp))