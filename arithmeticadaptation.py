import random
n = int(input())
while 1:
    a = random.randint(-999,1000)
    b = n-a
    if(max(abs(a),abs(b))>999):continue
    print(a,b)
    exit()