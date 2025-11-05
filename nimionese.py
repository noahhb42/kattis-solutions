H='bcdgknpt'
w=input().split()
def g(x):
 y=x.split('-');a=y[0][0];h=min(H,key=lambda c:(abs(ord(c)-ord(a.lower())),ord(c)))
 r=(h.upper() if a<'[' else h)+y[0][1:]
 for z in y[1:]: r+=''.join(h if c in H else c for c in z)
 if r[-1].lower() in H:
  v=min('aou',key=lambda u:(abs(ord(u)-ord(r[-1].lower())),ord(u)));r+=v+'h'
 return r
print(' '.join(map(g,w)))
