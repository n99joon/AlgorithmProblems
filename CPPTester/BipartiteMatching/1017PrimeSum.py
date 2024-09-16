#Bipartite Matching
from collections import defaultdict 
roundNo = 1
edge_ll = defaultdict(list)
mx = 51
vstd = [0]*mx

LOG = 0

n = int(input())
num = list(map(int, input().split()))

def log(x):
    if LOG:
        print(x)

def isPrime(x):
    if x<2:
        return 0
    for i in range(2, int(x**0.5)+1):
        if x%i == 0:
            return 0
    return 1

def dfs(a,t):
    #At each round we try to find one Bipartite Matching from a
    if (vstd[a] == roundNo) or a==t or a==0:
        return 0
    vstd[a] = roundNo
    
    for b in edge_ll[a]:
        if isPrime(num[a]+num[b]):
            if (match[b] == -1 or dfs(match[b],t)):
                match[b]= a
                match[a]=b
                return 1
    return 0



#link edges
for i in range(n):
    for j in range(n):
        if i!=j:
            if(isPrime(num[i]+num[j])):
                edge_ll[i].append(j)
                

flag = 0
ret =[]
for i in range(1,n):
    ans = 0
    #Fix the first 
    if not isPrime(num[i]+num[0]):
        continue
    vstd = [0]*(n)
    match = [-1]*n
    match[i] = 0
    match[0] = i
    #log('i: '+str(i))
    #log(match)
    for j in range(1,n):
        if i==j or (num[i]+num[j])%2!=0:
            continue
        #log(j)
        ans += dfs(j,i)
        roundNo += 1
        #log(match)

    ##log(i)
    ##log(match)
    if ans == (n-2)/2:
        #print(num[i],end=' ')
        ret.append(num[i])
        flag =1

if flag:
    ret.sort()
    print(*ret)
else:
    print('-1')


