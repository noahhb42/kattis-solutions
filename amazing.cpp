#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef array<ll,2> pll;
typedef array<ll,3> tll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

ll query(ll dir){

    if (dir == 0) cout << "up" << endl;
    else if (dir == 1) cout << "left" << endl;
    else if (dir == 2) cout << "down" << endl;
    else cout << "right" << endl;

    string ret;
    cin >> ret;
    if (ret == "solved" || ret == "wrong") return 2;
    if (ret == "ok") return 1;
    return 0;

}

int main(){

    cin.tie(0)->sync_with_stdio(0);

    set<tll> seen;

    stack<tll> st;
    st.push({0,0,0});
    st.push({0,0,1});
    st.push({0,0,2});
    st.push({0,0,3});

    while(!st.empty()){

        tll u = st.top();st.pop();
        if(seen.find(u) != seen.end()){
            cout<<"no way out"<<endl;
            return 0;
        }
        seen.insert(u);
        auto[x,y,dir] = u;

        ll move = query(dir);
        if(move == 1){
            if(dir == 0){
                st.push({x,y-1,2});
                st.push({x,y-1,1});
                st.push({x,y-1,0});
                st.push({x,y-1,3});
            }
            if(dir == 1){
                st.push({x-1,y,3});
                st.push({x-1,y,2});
                st.push({x-1,y,1});
                st.push({x-1,y,0});
            }
            if(dir == 2){
                st.push({x,y+1,0});
                st.push({x,y+1,3});
                st.push({x,y+1,2});
                st.push({x,y+1,1});
            }
            if(dir == 3){
                st.push({x+1,y,1});
                st.push({x+1,y,0});
                st.push({x+1,y,3});
                st.push({x+1,y,2});
            }
        }
        if(move == 2) return 0;
    }
    return 0;

}