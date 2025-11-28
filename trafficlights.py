n=int(input())
s=[[*map(int,input().split())] for _ in range(n)]
i = 0
while 1:
    i+=1
    if all(i%(m+n)>=m for m,n in s):break 
print(i)