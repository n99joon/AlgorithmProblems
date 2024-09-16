n = 500
primes = [1]
for i in range(2,n):
    isPrime = True
    for p in primes:
        if i%p == 0 and p!=1:
            isPrime = False
            break
    if isPrime:
        primes.append(i)
primes.reverse()
print(primes)

G = [0]*len(primes) #Greedy selection
M = [0]*len(primes) #Minimal selection

def getGreedySelection(w):
    G = [0]*len(primes) #Greedy selection
    for i in range(len(primes)):
        if w >= primes[i]:
            G[i] = w//primes[i]
            w -= primes[i]*G[i]
    return G

def calcW(j,G):
    M = [0]*len(primes) #Minimal selection
    w = 0
    for i in range(0,j):
        M[i] = G[i]
        w += primes[i]*M[i]
    M[j] = G[j]+1
    w+=primes[j]*(M[j])
    return M, w

ans = []
for i in range(1, len(primes)):
    for j in range(i+1, len(primes)): #if i==j, then one coin is enough, so not a counter example
        
        ci_1 = primes[i-1]
        
        G = getGreedySelection(ci_1-1)
        M, w = calcW(j,G)
        
        G = getGreedySelection(w)
        
        if sum(M) < sum(getGreedySelection(w)):
            #ans.append([w,G,M])
            G_used = []
            M_used = []
            for k in range(len(G)):
                if G[k] != 0:
                    G_used.append(primes[k])
                if M[k] != 0:
                    M_used.append(primes[k])
            ans.append([w,G_used,M_used])
            #ans.append(w)
#ans= list(set(ans))
ans.sort()
for a in ans:
    if a[0]>=5000: break
    print(a)
#print(ans)

        