from functools import cache
import sys

q,n,d=map(int,input().split())
s=input()
t=input()

sys.setrecursionlimit(100000)

@cache
def count(s,t,q,rem):
    if rem>len(s)*2:return 0
    if len(s)==len(t)==1:
        if s==t and rem==1:
            return 0
        elif s==t and rem==0:
            return 1
        elif s==t and rem==2:
            return q-1
        elif s!=t and rem==1:
            return 2
        elif s!=t and rem==2:
            return q-2
        else:
            return 0
    if s[0]==t[0]:
        return count(s[1:],t[1:],q,rem) + (q-1)*count(s[1:],t[1:],q,rem-2)
    return 2*count(s[1:],t[1:],q,rem-1) + (q-2)*count(s[1:],t[1:],q,rem-2)

print(count(s,t,q,d))