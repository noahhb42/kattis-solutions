while True:
    s = input()
    if len(s.split())==1:break

    n,*s = map(int,s.split())
    print(s[0],end=' ')
    last = s[0]
    for i in s:
        if i==last:
            pass
        else:
            print(i,end=' ')
        last = i
    print('$')