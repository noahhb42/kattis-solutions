n=int(input())
s=[*map(int,input().split())]
sm=0
for i in range(len(s)-2,-1,-1):
    if s[i]>=s[i+1]:
        sm+=s[i]-s[i+1]+1
        s[i] = s[i+1]-1

if s[0]<0:
    print(1)
else:
    print(sm)