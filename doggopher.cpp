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
    long double gx, gy, dx, dy;
    cin>>gx>>gy>>dx>>dy;
    long double hx,hy;
    while(cin>>hx>>hy){
        long double dg2 = (gx-hx)*(gx-hx)+(gy-hy)*(gy-hy);
        long double dd2 = (hx-dx)*(hx-dx)+(hy-dy)*(hy-dy);
        if(dg2*4 <= dd2){
            cout<<setprecision(3)<<fixed<<"The gopher can escape through the hole at ("<<hx<<","<<hy<<").\n";
            return 0;
        }
    }
    cout<<"The gopher cannot escape.\n";
}