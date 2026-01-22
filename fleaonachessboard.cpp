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

    ll S,x,y,dx,dy;
    while(cin>>S>>x>>y>>dx>>dy){
        if(S == 0){
            return 0;
        }

        ll s =  S<<1;
        
        bool done = false;
        rep(i,0,S){
            bool a = (x+i*dx)%s > S;
            bool b = (y+i*dy)%s > S;
            if(a ^ b){
                cout<<"After "<<i<<" jumps the flea lands at ("<<x+i*dx<<", "<<y+i*dy<<").\n";
                done = true;
                break;
            }
        }
        if(!done){
            cout<<"The flea cannot escape from black squares.\n";
        }
    }
    
}