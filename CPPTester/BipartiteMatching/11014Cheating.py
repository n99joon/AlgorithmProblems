from collections import defaultdict

c = int(input())

def dfs(a, vstd, roundNo, match, edge_ll):
    if vstd[a] == roundNo:
        return 0
    vstd[a] = roundNo
    for b in edge_ll[a]:
        if match[b] == -1 or dfs(match[b], vstd, roundNo, match, edge_ll):
            match[b] = a
            return 1
    return 0

def getIndex(i, j, m): #(i, j) -> idx
    return i*m+j

def isValid(i, j, n, m):
    return 0 <= i < n and 0 <= j < m
for _ in range(c):
    n, m = map(int, input().split())
    cnt = 0
    seatings = [[] for _ in range(n)]
    
    #read input
    for i in range(n-1,-1, -1):
        inp = input()
        for j in range(m):
            if inp[j] == '.':
                cnt += 1
            seatings[i].append(inp[j])

    #assign node nums and edges from odd to even rows
    idx = 0
    oddNodes =[]
    edge_ll = defaultdict(list)
    for i in range(n):
        for j in range(0,m,2):
            if seatings[i][j] == '.':
                oddNodes.append(getIndex(i,j,m))
                for col_diff in [-1,0,1]:
                    for row_diff in [-1,1]:
                        if isValid(i+col_diff, j+row_diff, n, m) and seatings[i+col_diff][j+row_diff] == '.':
                            edge_ll[getIndex(i,j,m)].append(getIndex(i+col_diff, j+row_diff, m))
    #print('oddNodes:', oddNodes)
    #print('edge_ll:', edge_ll)
    vstd = [0]*(n*m)
    match = [-1]*(n*m)
    roundNo = 1
    ans = 0
    for i in oddNodes:
        #print('match: ', match)
        ans += dfs(i, vstd, roundNo, match, edge_ll)
        roundNo += 1
    #print('cnt:', cnt)
    #print('ans:', ans)
    print(cnt-ans)
    

    #divide into odd and even columns
        
