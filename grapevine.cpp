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

    map<string, ll> name_to_int;

    ll n,m,d;cin>>n>>m>>d;

    vll s(n);

    rep(i,0,n){
        string name; ll skepticism;
        cin>>name>>skepticism;
        name_to_int[name] = i;
        s[i] = skepticism;
    }

    vvll g(n);
    rep(i,0,m){
        string a,b;cin>>a>>b;
        g[name_to_int[a]].push_back(name_to_int[b]);
        g[name_to_int[b]].push_back(name_to_int[a]);
    }

    vll spread(n,0);
    vll heard(n,(ll)4e18);
    vll nr(n,0);
    vll cur, next;
    string start;cin>>start;
    cur.push_back(name_to_int[start]);
    heard[name_to_int[start]]=0;


    ll day = 0;
    while(!cur.empty()){
        day++;
        for(auto i : cur){
            if(spread[i])continue;
            spread[i] = 1;
            for(auto j : g[i]){
                if(++nr[j]==s[j]){
                    next.push_back(j);
                }
                heard[j]=min(heard[j],day);
            }
        }
        swap(next,cur);
        next.clear();
    }

    ll ans = 0;
    rep(i,0,n){
        ans+=(heard[i]<=d);
    }
    cout<<ans-1<<"\n";
}