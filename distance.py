sm=0
A=[]
B=[]
n=int(input())
for i in range(n):
    a,b=map(int,input().split())
    A.append(a)
    B.append(b)
A.sort()
B.sort()
for i in range(n):
    sm+=(2*i+1-n)*(A[i]+B[i])
print(sm)