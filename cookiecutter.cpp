#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef array<ll,2> pll;
typedef array<ll,3> tll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

struct Pt{long double x,y;};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout<<setprecision(20);

    ll n;cin>>n;
    vector<Pt> p(n);
    rep(i,0,n)cin>>p[i].x>>p[i].y;
    long double a;cin>>a;

    auto poly_area = [&](vector<Pt>& p){
        long double a = 0;
        rep(i,0,n){
            ll j = (i+1)%n;
            a += p[i].x*p[j].y-p[i].y*p[j].x;
        }
        return fabsl(a)/2.0;
    };

    long double area = poly_area(p);
    long double s = sqrtl(a/area);

    long double mnx = 4e18;
    long double mny = 4e18;

    for(auto& pt : p){
        pt.x*=s;
        pt.y*=s;
        mnx=min(mnx,pt.x);
        mny=min(mny,pt.y);
    }

    for(auto& pt : p){
        cout<<pt.x-mnx<<" "<<pt.y-mny<<"\n";
    }
}