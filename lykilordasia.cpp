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
    string s;getline(cin,s);

    vector<string> parts;
    string cur;
    stringstream ss(s);
    while(ss>>cur)parts.push_back(cur);

    for(string& w : parts){
        bool hasL = false, hasD = false;
        for(char c : w){
            hasL |= isalpha(c);
            hasD |= isdigit(c);
            if(hasL && hasD)break;
        }
        if(hasL && hasD)w.assign(w.size(), '*');
    }

    for(auto w : parts){
        cout<<w<<" ";
    }
    cout<<"\n";
}