import sys
t=sys.stdin.read().split()
v=[0]*3;c=[0]*3;V=C=0
for s in t[1:]:
 if s[0]=='Y':
  V+=1
  for i in 0,1,2:
   if s[i+1]=='Y':v[i]+=1
 else:
  C+=1
  for i in 0,1,2:
   if s[i+1]=='Y':c[i]+=1
for i in 0,1,2:
 a=v[i]*C;b=c[i]*V
 print('Not Effective' if a>=b else 100*(1-a/b))
