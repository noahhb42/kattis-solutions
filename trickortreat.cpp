#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef array<ll,2> pll;
typedef array<ll,3> tll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

long double dist(long double a, long double b, long double c, long double d){
    return sqrtl((a-c)*(a-c)+(b-d)*(b-d));
}

long double maxdis(vector<array<long double,2>>& points, long double X){
    long double mx = 0;
    for(auto [x,y] : points){
        mx=max(mx,sqrtl((x-X)*(x-X)+y*y));
    }
    return mx;
}

array<long double,2> calc(vector<array<long double,2>>& points, long double a, long double b){
    long double x1 = a, x2 = 2*a/3+b/3, x3 = a/3+2*b/3, x4 = b;
    long double d1 = maxdis(points,x1), d2 = maxdis(points,x2), d3 = maxdis(points,x3), d4 = maxdis(points,x4);
    if(d1 > d2 && d3 < d4)return {d2, d3};
    if(d1 > d2)return {d3, d4};
    return {d1, d2};
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n;
    while(cin>>n){
        if(n==0)break;
        vector<array<long double,2>> points(n);
        long double mnx = 1e300, mxx = -1e300;
        rep(i,0,n){
            long double a,b;cin>>a>>b;
            points.push_back({a,b});
            mnx=min(a,mnx);
            mxx=max(a,mxx);
        }
        long double a = mnx, b = mxx;
        rep(i,0,60){
            auto [aa,bb] = calc(points,a,b);
            a=aa;b=bb;
        }
        cout<<setprecision(10)<<(a+b)/2<<" "<<maxdis(points,(a+b)/2)<<"\n";
    }
}