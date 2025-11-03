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
    string s,t;
    while(cin>>s>>t){
        if(s=="E")return 0;
        ll n = s.size();
        ll a=0,b=0;
        rep(i,0,n){
            if(s[i]=='R'){
                if(t[i]=='P')b++;
                if(t[i]=='S')a++;
            }
            if(s[i]=='S'){
                if(t[i]=='P')a++;
                if(t[i]=='R')b++;
            }
            if(s[i]=='P'){
                if(t[i]=='R')a++;
                if(t[i]=='S')b++;
            }
        }
        cout<<"P1: "<<a<<"\n"<<"P2: "<<b<<"\n";
    }
}