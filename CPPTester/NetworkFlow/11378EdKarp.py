#Edmond Karp algorithm for maximum flow
from collections import deque, defaultdict
import pprint


n,m,k = map(int, input().split())
mx = 2000
ss = mx+1
tt = mx+3
t = mx+2
s = mx+4
edges = [[0]*(mx+5) for _ in range(mx+5)]
edge_list = defaultdict(list)
#Edges N -> M
for i in range(1,n+1):
    x, *y = map(int, input().split())
    for j in y:
        j+=1000
        edges[i][j] = 1
        edges[j][i] = 0
        edge_list[i].append(j)
        edge_list[j].append(i)

#Edges S -> N
for i in range(1,n+1):
    edges[s][i] = 1
    edges[i][s] = 0
    edge_list[s].append(i)
    edge_list[i].append(s)
    
#edge S ->  SS
edges[s][ss] = k
edges[ss][s] = 0
edge_list[s].append(ss)
edge_list[ss].append(s)

#Edges SS -> N
for i in range(1,n+1):
    edges[ss][i] = k
    edges[i][ss] = 0
    edge_list[ss].append(i)
    edge_list[i].append(ss)

#Edges M -> T
for i in range(1001,1001+m):
    edges[i][t] = 1
    edges[t][i] = 0
    edge_list[i].append(t)
    edge_list[t].append(i)

#Edges T -> TT
edges[t][tt] = 2001
edges[tt][t] = 0
edge_list[t].append(tt)
edge_list[tt].append(t)


#Augment from S to TT

        
while True:
    vstd = [-1]*(mx+5)
    q = deque([s])
    vstd[s] = s
    while q:
        x = q.popleft()
        #print(x)
        for y in edge_list[x]:
            if vstd[y] == -1 and edges[x][y] > 0:
                vstd[y] = x
                q.append(y)

                if y == tt:
                    break
    if vstd[tt] == -1:
        break
    #update residual graph
    x = tt
    #find the bottleneck flow
    flow = float('inf')
    #print('path found')
    while x != s:
        #print(x,end=' ')
        y = vstd[x]
        #print(x,y)
        flow = min(flow, edges[y][x])
        x = y
        
    
    x=tt
    while x != s:
        y = vstd[x]
        edges[y][x] -= flow
        edges[x][y] += flow
        x = y
    
    

print(edges[tt][t])