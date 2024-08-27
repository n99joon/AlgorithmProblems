#Edmond Karp algorithm for maximum flow
from collections import deque, defaultdict

n,m,k = map(int, input().split())
mx = 2000
ss = mx+1
tt = mx+3
t = mx+2
s = mx+4
edges = [[0]*(mx+5) for _ in range(mx+5)]

#Edges N -> M
for i in range(1,n+1):
    x, *y = map(int, input().split())
    for j in y:
        j+=1000
        edges[i][j] = 1
        edges[j][i] = 0

#Edges S -> N
for i in range(1,n+1):
    edges[s][i] = 1
    edges[i][s] = 0
    
#edge S ->  SS
edges[s][ss] = k
edges[ss][s] = 0

#Edges SS -> N
for i in range(1,n+1):
    edges[ss][i] = k
    edges[i][ss] = 0

#Edges M -> T
for i in range(1001,1001+m):
    edges[i][t] = 1
    edges[t][i] = 0

#Edges T -> TT
edges[t][tt] = 2001
edges[tt][t] = 0


#Augment from S to TT
while True:
    vstd = [0]*(mx+5)
    vstd[s] = s
    q = deque([s])
    while q:
        x = q.popleft()
        for y in range((mx+5)):
            if edges[x][y] and not vstd[y]:
                vstd[y] = x
                q.append(y)
    if not vstd[tt]:
        break
    #update residual graph
    x = tt
    while x != s:
        y = vstd[x]
        edges[y][x] -= 1
        edges[x][y] += 1
        x = y

print(edges[tt][t])