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
    ll n;cin>>n;
    unordered_set<ll> rows, cols, diag, antidiag;

    rep(i,0,n){
        ll r,c;cin>>r>>c;
        ll d = r-c;
        ll ad = r+c;
        if(rows.count(r) || cols.count(c) || diag.count(d) || antidiag.count(ad)){
            cout<<"INCORRECT\n";
            return 0;
        }
        rows.insert(r);
        cols.insert(c);
        diag.insert(d);
        antidiag.insert(ad);
    }

    cout<<"CORRECT\n";
}