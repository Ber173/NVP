n = int(input())
a = list(map(int, input().split()))
res = [1] * n

for i in range(1, n):
    cnt = 0
    for j in range(0, i):
        if a[i] > a[j]:
            res[i] = max(res[i], res[j] + 1)

print(max(res))
