it = iter(open(0).read().splitlines())
n, k = map(int, next(it).split())
names = [next(it).strip() for _ in range(n)]
steps = [int(next(it)) for _ in range(k)]

N = n
t = [0]*(N+1)
for i in range(1, N+1):
    t[i] = i & -i

def bit_add(i, v):
    while i <= N:
        t[i] += v
        i += i & -i

def bit_kth(k):
    i = 0
    bit = 1 << (N.bit_length())
    while bit:
        j = i + bit
        if j <= N and t[j] < k:
            k -= t[j]
            i = j
        bit >>= 1
    return i + 1

cnt = n
pos = 0
i = 0

while cnt > 1:
    s = steps[i % k] % cnt
    target_rank = (pos + s) % cnt
    idx = bit_kth(target_rank + 1)
    bit_add(idx, -1)
    cnt -= 1
    pos = target_rank % cnt
    i += 1

last_idx = bit_kth(1) - 1
print(names[last_idx])
