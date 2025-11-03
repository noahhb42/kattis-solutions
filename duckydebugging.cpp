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
    string s;
    while(getline(cin,s)){
        if(s=="I quacked the code!")return 0;

        if(s[s.size()-1]=='?'){
            cout<<"Quack!"<<endl;
        }
        else{
            cout<<"*Nod*"<<endl;
        }
    }
}