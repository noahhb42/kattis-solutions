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
    ll n;
    while(cin>>n){
        stack<ll> st;
        queue<ll> q;
        priority_queue<ll> pq;
        bool isS = true, isQ = true, isPQ = true;
        rep(i,0,n){
            ll op,x;cin>>op>>x;
            if(op==1){
                st.push(x);
                q.push(x);
                pq.push(x);
            }
            else{
                if(st.empty() && q.empty() && pq.empty()){
                    isS = isQ = isPQ = false;
                }
                else{
                    if(st.top() != x)isS=false;
                    if(q.front() != x)isQ=false;
                    if(pq.top() != x)isPQ=false;

                    st.pop();q.pop();pq.pop();
                }
            }
        }
        ll cnt = isS + isQ + isPQ;
        if(cnt==0)cout<<"impossible\n";
        else if(cnt>1)cout<<"not sure\n";
        else if(isS)cout<<"stack\n";
        else if (isQ)cout<<"queue\n";
        else cout<<"priority queue\n";
    }
}