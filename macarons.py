n,m=map(int,open(0))
s=1<<n
mod = 1e9

def mult(A,B):
    C=[[0]*s for _ in range(s)]
    for i in range(s):
        for j in range(s):
            for k in range(s):
                C[i][j] = (C[i][j]+A[i][k]*B[k][j]) % mod
    return C

b=[1]*(s+s)
for c in range(2,s+s):
    b[c]=b[c//2]
    if c%4==0:
        b[c]+=b[c//4]
t=[[0]*s for _ in range(s)]
for y in range(s):
    for x in range(s):
        if x&y==0:
            t[y][x]=b[s+(x|y)]
res=[[0]*s for _ in range(s)]
for i in range(s):res[i][i]=1
while m:
    if m%2==1:
        res = mult(res,t)
    t = mult(t,t)
    m//=2
print(res[0][0])