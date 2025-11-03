#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef array<ll,2> pll;
typedef array<ll,3> tll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll T;cin>>T;
    auto C=[&](ll n,ll k)->long double{
        if(k<0||k>n) return 0;
        if(k>n-k) k=n-k;
        long double r=1;
        rep(i,1,k+1)r=r*(n-k+i)/i;
        return r;
    };
    while(T--){
        ll N,V1,V2,W;cin>>N>>V1>>V2>>W;
        ll M=V1+V2,R=N-M,need=max(0LL,(N/2+1)-V1);
        long double p;
        if(need<=0)p=1.0L;
        else if(need>R)p=0.0L;
        else{
            long double s=0;
            rep(x,need,R+1)s+=C(R,x);
            p=s/powl(2.0L, R);
        }
        cout << (p*100.0L>W ? "GET A CRATE OF CHAMPAGNE FROM THE BASEMENT!\n" : (p==0.0L ? "RECOUNT!\n" : "PATIENCE, EVERYONE!\n"));
    }
}
