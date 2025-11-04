#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef array<ll,2> pll;
typedef array<ll,3> tll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

string to_base(ll x, ll b){
    string dig = "0123456789abcdef";
    string s;
    while(x){
        s.push_back(dig[x%b]);
        x/=b;
    }
    reverse(s.begin(),s.end());
    return s;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll y;
    string w1,w2,w3;
    cin>>y>>w1>>w2>>w3;

    rep(b,2,17){
        ll bb = b*b;
        if(y%bb==0){
            cout<<b<<" "<<to_base(y,b)<<"\n";
            return 0;
        }
    }

    cout<<"impossible\n";
}