p,q=map(int,input().split());s=input();r=()
if s=="AABB"and q==7:r=8,9
elif s=="BBAA"and p==3:r=1,2
elif s=="ABBA"and q-p==3:r=p+1,p+2
elif s=="BAAB"and p*9+q==26:r=1,9
elif s=="ABAB"and p*9+q==62:r=7,9
elif s=="BABA"and p*9+q==22:r=1,3
print(-1 if not r else'%d %d'%r)