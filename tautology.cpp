#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef array<ll,2> pll;
typedef array<ll,3> tll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

bool eval_expr(string& s, ll mask){
    auto val = [&](char v){
        ll idx = string("pqrst").find(v);
        return (mask >> idx) & 1;
    };
    vector<bool> st;
    for(ll i = s.size() -1 ; i>=0 ; --i){
        char c = s[i];
        if(c==' ')continue;
        if(c=='p' || c=='q' || c=='r' || c=='s' || c=='t'){
            st.push_back(val(c));
        }
        else if(c=='N'){
            bool a = st.back();st.pop_back();
            st.push_back(!a);
        }
        else{
            bool a = st.back();st.pop_back();
            bool b = st.back();st.pop_back();
            bool r;
            switch(c){
                case 'K':r=(a&b);break;
                case 'A':r=(a|b);break;
                case 'C':r=(!a|b);break;
                case 'E':r=(a==b);break;
                default: r=false;break;
            }
            st.push_back(r);
        }
    }
    return st.size()==1 && st.back();
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    string s;
    while(getline(cin,s)){
        if(s=="0")break;
        bool taut = true;
        for(ll m = 0 ; m<32 && taut ; ++m){
            taut = eval_expr(s,m);
        }
        cout<< (taut ? "tautology" : "not") << "\n";
    }
}