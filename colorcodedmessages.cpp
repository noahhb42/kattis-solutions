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
    tll colors[17] = {{255,255,255}, {0,0,255}, {255,0,255}, {255,165,0}, {18,10,143}, {220,20,60}, {255,0,0}, {255,255,0}, {192,192,192}, {75,0,130}, {165,42,42}, {0,255,0}, {0,255,255}, {128,0,0}, {80,200,120}, {255,192,203}, {0,0,0}};
    map<ll,char> m = {
        {0,'w'},
        {1,'b'},
        {2,'f'},
        {3,'o'},
        {4,'u'},
        {5,'c'},
        {6,'r'},
        {7,'y'},
        {8,'s'},
        {9,'i'},
        {10,'h'},
        {11,'g'},
        {12,'a'},
        {13,'m'},
        {14,'e'},
        {15,'p'},
        {16,' '}
    };
    auto dis = [&](tll& a, tll& b){
        return abs(a[0]-b[0])+abs(a[1]-b[1])+abs(a[2]-b[2]);
    };

    string ans;
    ll n;cin>>n;
    rep(_,0,n){
        tll a;
        cin>>a[0]>>a[1]>>a[2];
        rep(i,0,17){
            if(dis(a,colors[i])<25){
                ans.push_back(m[i]);
                break;
            }
        }
    }
    cout<<ans<<"\n";
}