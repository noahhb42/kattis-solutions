from collections import defaultdict,deque

n=int(input());R=[]
for _ in range(n):
 p=input().split();a=p[0];C=[]
 for t in p[1:]:
  k,v=t.split("=")
  C.append((k[0], v if k[0]=="i" else int(v)))  # p/i/l
 R.append((a,C))

P=int(input())
w=deque();c=defaultdict(int)

for i in range(1,P+1):
 ip,ps=input().split(":");pt=int(ps);m=c[ip]+1
 for a,C in R:
  for t,v in C:
   if (t=="p" and pt!=v) or (t=="i" and ip!=v) or (t=="l" and m<v): break
  else:
   if a=="log": print("log",i)
   else: print(a,i); break
 w.append(ip);c[ip]+=1
 if len(w)>999:
  x=w.popleft();c[x]-=1
  if not c[x]: del c[x]