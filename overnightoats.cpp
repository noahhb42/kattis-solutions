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
    ll n,x;cin>>n>>x;
    queue<ll> q;

    rep(i,0,n){
        string s;cin>>s;
        if(!q.empty() && i-q.front()>x){
            cout<<"ono..\n";
            return 0;
        }
        if(s=="ADD"){
            q.push(i);
        } else if (s=="EAT"){
            q.pop();
        }
    }

    cout<<"yay!\n";
}