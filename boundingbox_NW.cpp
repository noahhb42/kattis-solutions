#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef array<ll,2> pll;
typedef array<ll,3> tll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

typedef long double ld;
const ld PI = acosl(-1.0);

struct P {ld x,y;};
static inline P operator+(P a,P b){return {a.x+b.x,a.y+b.y};}
static inline P operator-(P a,P b){return {a.x-b.x,a.y-b.y};}
static inline P operator*(P a,ld k){return {a.x*k,a.y*k};}
static inline ld dot(P a, P b){return a.x*b.x+a.y*b.y;}
static inline ld norm2(P a){return dot(a,a);}
static inline ld norm(P a){return sqrtl(norm2(a));}
static inline P perp(P a){return {-a.y,a.x};}
static inline P unit(P a){ld d=norm(a); return{a.x/d, a.y/d};}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout<<setprecision(10)<<fixed;

    ll n;
    while((cin>>n) && n>0){
        P p[3];
        rep(i,0,3)cin>>p[i].x>>p[i].y;

        auto solve_from_pair = [&](P A, P B, P C3, ld &area){
            P v = B - A;
            ld d = norm(v);
            if(d==0)return false;
            P M = (A+B)*0.5;
            P nrm = unit(perp(v));

            rep(s,1,n){
                ld sines = sinl(PI*s/n);
                if(fabsl(sines)<1e-18)continue;
                ld R = d/(2*sines);
                ld half = d*0.5;
                ld sq = R*R-half*half;
                if(sq<1e-10)continue;
                ld h = sq<=0 ? 0 : sqrtl(max(0.0L,sq));

                for(ll sign : {-1,1}){
                    P Cc = M+nrm*(sign*h);

                    ld distC3 = fabsl(norm(C3-Cc)-R);
                    ld tol = 1e-6*(1.0+R);

                    if(distC3>tol)continue;

                    ld ang0 = atan2l(A.y-Cc.y,A.x-Cc.x);
                    ld step = 2*PI/n;

                    ld minx = 1e300, miny = 1e300, maxx = -1e300, maxy = -1e300;
                    rep(k,0,n){
                        ld ang = ang0+k*step;
                        ld cx = Cc.x+R*cosl(ang);
                        ld cy = Cc.y+R*sinl(ang);
                        minx=min(minx,cx);maxx=max(maxx,cx);
                        miny=min(miny,cy);maxy=max(maxy,cy);
                    }
                    area=(maxx-minx)*(maxy-miny);
                    return true;
                }
            }
            return false;
        };

        bool found = false;
        ld area = 0;

        ll idx[3][2] = {{0,1},{0,2},{1,2}};
        for(auto& pr : idx){
            if(found)break;
            ll i = pr[0], j = pr[1], k = 3-i-j;
            if(solve_from_pair(p[i],p[j],p[k],area)){found = true;break;}
            if(solve_from_pair(p[j],p[i],p[k],area)){found = true;break;}
        }

        cout<<area<<"\n";
    }
}