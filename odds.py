from math import gcd
d=range(1,7)
S=lambda x:d if x=='*' else [int(x)]
F=lambda a,b:(2,0,0)if a+b==3 else((1,a,0)if a==b else(0,max(a,b),min(a,b)))
t=open(0).read().split();i=0
while 1:
    a,b,c,e=t[i:i+4];i+=4
    if a==b==c==e=='0':break
    A,B,C,E=S(a),S(b),S(c),S(e);w=T=0
    for x in A:
        for y in B:
            u=F(x,y)
            for p in C:
                for q in E:
                    T+=1;w+=u>F(p,q)
    g=gcd(w,T);print(0 if w<1 else 1 if w==T else f"{w//g}/{T//g}")