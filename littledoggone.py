l=open(0).read().splitlines();e,t=map(float,l[0].split());r=e/t;n=int(l[1]);i=2;m=[]
for _ in range(n):b=l[i];i+=1;lr,hr,le,he=map(float,l[i].split());i+=1;(lr<=r<=hr and le<=e<=he) and m.append(b)
print('\n'.join(m) if m else 'Mutt')
