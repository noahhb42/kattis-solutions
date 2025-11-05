import itertools as I
t=int(input())
for _ in range(t):
 s=input().replace(' ',''); S=set()
 for p in set(I.permutations(s)):
  y=int(''.join(p[:4])); m=int(p[4]+p[5]); d=int(p[6]+p[7])
  if y>1999 and 1<=m<=12:
   k=[31,28,31,30,31,30,31,31,30,31,30,31][m-1]
   if m==2 and (y%4==0 and y%100 or y%400==0): k=29
   if 1<=d<=k: S.add((y,m,d))
 if not S: print(0)
 else: y,m,d=min(S); print(len(S),f'{d:02d} {m:02d} {y:04d}')
