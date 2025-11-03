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
    vll outdeg(n+1,0);
    vvll gr(n+1,vll(0));
    rep(i,1,n+1){
        ll a;cin>>a;
        outdeg[i]=a;
        rep(_,0,a){
            ll b;cin>>b;
            gr[b].push_back(i);
        }
    }
    vvll ans(0);
    vll pos,cr;
    ll sm = 0;
    rep(s,1,n+1)if(outdeg[s]==0)pos.push_back(s);
    ans.push_back(pos);
    sm+=pos.size();
    while(!pos.empty()){
        cr.clear();
        for(auto i : pos){
            for(auto j : gr[i]){
                if(--outdeg[j]==0){
                    cr.push_back(j);
                }
            }
        }
        swap(pos,cr);
        ans.push_back(pos);
        sm+=pos.size();
    }
    if(sm<n){
        cout<<"Omogulegt!\n";
    }
    else{
        cout<<"Mogulegt!\n"<<ans.size()-1<<"\n";
        for(auto i : ans){
            if(i.size()==0)continue;
            cout<<i.size()<<" ";
            for(auto j : i){
                cout<<j<<" ";
            }
            cout<<"\n";
        }
    }
}