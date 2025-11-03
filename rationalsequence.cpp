#include"bits/stdc++.h"
using namespace std;int main(){cin.tie(0)->sync_with_stdio(0);
int T;cin>>T;while(T--){long long k,a,b;char s;cin>>k>>a>>s>>b;long long d=a-2*(a%b)+b;cout<<k<<" "<<b<<"/"<<d<<"\n";}}
