r,g,b,cr,cg,cb,crg,cgb=map(int,open(0).read().split())
dr=max(0,r-cr);dg=max(0,g-cg);db=max(0,b-cb)
print(-1 if dr>crg or db>cgb or crg-dr+cgb-db<dg else dr+db+dg)