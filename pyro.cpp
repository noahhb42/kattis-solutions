#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef array<ll,2> pll;
typedef array<ll,3> tll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

int main(){
    cin.tie(0)->sync_with_stdio(0);
    vll a; ll x;
    while (cin >> x && x != -1) a.push_back(x);
    vll has(1<<18, 0);
    for (auto v : a) has[v] = 1;
    for (auto v : a) {
        ll c = 0;
        rep(i,0,18){
            ll y = v ^ (1<<i);
            if (y > v && has[y]) ++c;
            rep(j,i+1,18){
                ll z = y ^ (1<<j);
                if (z > v && has[z]) ++c;
            }
        }
        cout << v << ":" << c << "\n";
    }
}
