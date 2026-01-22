#include"bits/stdc++.h"
using namespace std;
typedef long long ll;

const ll mx = 6000;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n;
    while(cin>>n){
        if(n==0)break;
        vector<ll> a(n);
        ll all = 0;
        for(auto &i : a){cin>>i;all+=i;}
        bitset<mx> ks;
        ks[0] = 1;
        for(ll c : a){
            for(ll i = mx ; i>0 ; --i){
                if(i-c<0)continue;
                if(ks[i-c])ks[i]=1;
            }
        }
        for(ll i = (all+1)/2 ; i>=0 ; --i){
            if(ks[i]){
                cout << max(all-i,i) << " " << min(all-i,i) << endl;
                break;
            }   
        }
    }
}