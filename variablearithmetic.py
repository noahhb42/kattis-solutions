mp={}
while True:
    s=input().split()
    if len(s)==1:
        if s[0].isdigit():
            if int(s[0])==0:
                break
            else:
                print(s[0])
        elif s[0] in mp:
            print(mp[s[0]])
        else:
            print(s[0])
    elif s[1]=='=':
        mp[s[0]]=int(s[2])
    else:
        l = []
        sm = 0
        for i in s[::2]:
            if i.isdigit():
                sm+=int(i)
            elif i in mp:
                sm+=mp[i]
            else:
                l.append(i)
        if sm==0:
            print(*l,sep=' + ')
        else:
            print(*([str(sm)]+l),sep=' + ')