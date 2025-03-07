n = int(input())
a = list(map(int, input().split()))
res = []

res.append(1)

for i in range(1, len(a) - 1):
    cnt = 0
    for j in range(0, i - 1):
        if a[i] > a[j]:
            cnt = max(cnt, res[j])
    res.append(cnt + 1)

print(max(res))
