n = int(input())
sm = 0
for i in range(2,int(n**.25)+10):
    m = int((n//(i*i))**.5)
    for j in range(m-2,m+4):
        if i>=j:continue
        if i*i*j*j==n:sm+=1;break
print(sm)