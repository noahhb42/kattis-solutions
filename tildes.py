a=open(0).read().split();n=int(a[0]);p=list(range(n+1));s=[1]*(n+1);o=[];i=2
def f(x):
  while p[x]-x:p[x]=p[p[x]];x=p[x]
  return x
while i<len(a):
  if a[i]>'s':
    x=int(a[i+1]);y=int(a[i+2]);i+=3;x=f(x);y=f(y)
    if x!=y:
      if s[x]<s[y]:x,y=y,x
      p[y]=x;s[x]+=s[y]
  else:
    x=int(a[i+1]);i+=2;o+=str(s[f(x)]),
print('\n'.join(o))