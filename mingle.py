n,k=map(int,input().split());p=998244353;print(n*pow(2*k,2*k,p)*pow(2*k+1,p-1-2*k,p)%p)
