from collections import defaultdict

n= int(input())
size = [0]*n
speed = [0]*n
intel = [0]*n 
for i in range(n):
    size[i], speed[i], intel[i] = map(int, input().split())

edge_ll = defaultdict(list)
for i in range(n):
    for j in range(n):
        if i==j: 
            continue
        if size[i] <= size[j] and speed[i] <= speed[j] and intel[i] <= intel[j]:
            if size[i] == size[j] and speed[i] == speed[j] and intel[i] == intel[j]:
                if i>j:
                    edge_ll[j].append(i)
            else:
                edge_ll[j].append(i)

roundNo = 1
vstd = [0]*n
match = [-1]*n

def dfs(a):
    if vstd[a] == roundNo:
        return 0
    vstd[a] = roundNo
    for b in edge_ll[a]:
        if match[b] == a:
            continue
        if match[a]==b:
            continue
        if match[b] == -1 or dfs(match[b]):
            match[b] = a
            return 1
    return 0

ans = 0
for i in range(n):
    ans += dfs(i)
    roundNo += 1
    ans += dfs(i)
    roundNo += 1

print(n-ans)

