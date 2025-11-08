from collections import deque

it = iter(open(0).read().splitlines())
n, k = map(int, next(it).split())
d = deque(next(it).strip() for _ in range(n))
L = [int(next(it)) for _ in range(k)]

i = 0
while len(d) > 1:
    s = L[i % k] % len(d)
    d.rotate(-s)
    d.popleft()
    i += 1

print(d[0])
