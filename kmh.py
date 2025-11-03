n = int(input())
mx = 0
for _ in range(n):
    a = input()
    if a.isnumeric():
        print(a)
        mx = max(mx, (int(a)//10+1)*10)
    else:
        print(mx)
