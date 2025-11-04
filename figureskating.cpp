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
    unordered_map<string,ll> pred;

    rep(i,1,n+1){
        string name;cin>>name;
        pred[name]=i;
    }

    string best_name;
    ll best_rise = 0;
    ll best_final_pos = LLONG_MAX;

    rep(i,1,n+1){
        string name;cin>>name;
        ll rise = pred[name]-i;
        if(rise > best_rise || (rise == best_rise && rise>0 && i<best_final_pos)){
            best_rise = rise;
            best_final_pos = i;
            best_name = name;
        }
    }
    if(best_rise == 0){cout<<"suspicious\n";}
    else cout<<best_name << "\n";
}