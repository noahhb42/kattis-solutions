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
    vvll op(n,vll(n));
    rep(_,0,n*n){
        ll i,j,k;cin>>i>>j>>k;
        op[i][j]=k;
    }

    bool assoc = true;
    rep(x,0,n){
        rep(y,0,n){
            rep(z,0,n){
                if(op[op[x][y]][z] != op[x][op[y][z]]){
                    assoc = false;
                    break;
                }
            }
            if(!assoc)break;
        }
        if(!assoc)break;
    }
    if(!assoc){
        cout<<"magma\n";
        return 0;
    }

    ll I = -1;
    rep(e,0,n){
        bool ok = true;
        rep(x,0,n){
            if(op[x][e] != x || op[e][x] != x){ok = false;break;}
        }
        if(ok){I = e; break;}
    }

    if(I==-1){
        cout<<"semigroup\n";
        return 0;
    }

    bool all_inv = true;
    rep(x,0,n){
        bool has = false;
        rep(y,0,n){
            if(op[x][y]==I && op[y][x]==I){has = true;break;}
        }
        if(!has)all_inv = false;
    }

    cout << (all_inv ? "group\n" : "monoid\n");
}
