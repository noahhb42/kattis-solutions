a,b=input().split()

def encrypt(s):
    cr = s[0]; nr = 0
    ans = ''
    for i in s:
        if i==cr:
            nr+=1
        else:
            ans += str(nr) + str(cr)
            nr = 1
            cr = i
    ans += str(nr) + str(cr)
    return ans

ans = 0
while(a!=b):
    ans+=1
    a = encrypt(a)
print(ans)