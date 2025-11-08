r=open(0).read().split();i=0;o=[]
def X(a,b,c):return(b[0]-a[0])*(c[1]-a[1])-(b[1]-a[1])*(c[0]-a[0])
while 1:
 n=int(r[i]);i+=1
 if n<1:break
 p=sorted({(int(r[i+2*j]),int(r[i+2*j+1]))for j in range(n)});i+=2*n
 if len(p)<3:o+=("0.0",);continue
 h=[]
 for q in p:
  while len(h)>1 and X(h[-2],h[-1],q)<=0:h.pop()
  h+=q,
 t=len(h)
 for q in p[-2::-1]:
  while len(h)>t and X(h[-2],h[-1],q)<=0:h.pop()
  h+=q,
 s=0
 for j in range(len(h)-1):
  x,y=h[j];u,v=h[j+1];s+=x*v-u*y
 o+=('%.1f'%(abs(s)/2),)
print('\n'.join(o))