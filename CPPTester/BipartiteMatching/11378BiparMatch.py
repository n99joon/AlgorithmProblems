#bipartite Matching
from collections import defaultdict 
roundNo = 1
edge_ll = defaultdict(list)
vstd = [0]*2005
match = [-1]*2005

def dfs(a):
    #At each round we try to find one Bipartite Matching from a
    if (vstd[a] == roundNo):
        return 0
    vstd[a] = roundNo
    for b in edge_ll[a]:
        if (match[b] == -1 or dfs(match[b])):
            match[b] = a
            match[a] = b
            return 1
        
    return 0

n,m,k = map(int, input().split())
for i in range(1,n+1):
    x, *y = map(int, input().split())
    for j in y:
        j+=1000
        edge_ll[i].append(j)
        #edge_ll[j].append(i)

ans = 0
for i in range(1,n+1):
    ans += dfs(i)
    roundNo += 1

temp = 0
for i in range(1,n+1):
    while(dfs(i) ==1):
        temp += 1
        if temp==k:
            break
        roundNo += 1
    if temp==k:
        break
print(ans + temp)
# j=0
# i = 1
# while i<=n and j<k:
#   d = dfs(i)
#   j += d; i += d^1
#   roundNo += 1
# print(ans+j)

#Add break if ==M 