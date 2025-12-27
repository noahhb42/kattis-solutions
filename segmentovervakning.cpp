#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef array<ll,2> pll;
typedef array<ll,3> tll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

struct SegTree{
    ll n;
    vll st;
    SegTree(ll N = 0){init(N);}
    void init(ll N){
        n=1;while(n<N)n*=2;
        st.assign(2*n,LLONG_MIN);
    }
    void setval(ll i, ll v){
        i+=n;
        st[i] = v;
        for(i >>= 1 ; i; i>>=1)st[i] = max(st[i<<1], st[i<<1|1]);
    }
    ll query(ll l, ll r){
        if(l>r)return LLONG_MIN;
        l+=n;r+=n;
        ll res = LLONG_MIN;
        while(l<=r){
            if(l&1)res=max(res,st[l++]);
            if(!(r&1))res=max(res,st[r--]);
            l>>=1;
            r>>=1;
        }
        return res;
    }
};

struct Op{
    char d;ll id, b, c;
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll xmin, xmax;cin >> xmin >> xmax;
    ll n;cin>>n;

    vector<Op> ops(n);
    vll coords;

    rep(i,0,n){
        char d;ll a;cin>>d>>a;
        ops[i].d=d;ops[i].id=a;
        if(d=='+'){
            ll b,c;cin>>b>>c;
            ops[i].b=b;ops[i].c=c;
            coords.push_back(b);
        }
    }

    sort(coords.begin(),coords.end());
    coords.erase(unique(coords.begin(),coords.end()),coords.end());
    ll m = coords.size();

    auto idx = [&](ll b){
        return (ll)(lower_bound(coords.begin(),coords.end(),b)-coords.begin());
    };
    auto pos = [&](ll x){
        ll p = (ll)(upper_bound(coords.begin(),coords.end(),x)-coords.begin())-1;
        return p;
    };

    vector<multiset<ll>> ends(m);
    SegTree seg(m);

    map<ll,pll> by;

    for(auto &op : ops){
        if(op.d=='+'){
            ll i = idx(op.b);
            ends[i].insert(op.c);
            seg.setval(i,*ends[i].rbegin());
            by[op.id] = {i, op.c};
        }
        else{
            auto it = by.find(op.id);
            if(it != by.end()){
                ll i = it->second[0];
                ll c = it->second[1];
                auto jt = ends[i].find(c);
                if(jt != ends[i].end())ends[i].erase(jt);
                seg.setval(i,ends[i].empty() ? LLONG_MIN : *ends[i].rbegin());
                by.erase(it);
            }
        }

        ll p1 = pos(xmin);
        ll r1 = (p1 < 0 ? LLONG_MIN : seg.query(0,p1));
        if(r1 == LLONG_MIN){
            cout<<"-1\n";
            continue;
        }
        if(r1 >= xmax){
            cout<<1<<"\n";
            continue;
        }

        ll p2 = pos(r1);
        ll r2 = (p2 < 0 ? LLONG_MAX : seg.query(0,p2));
        if(r2 != LLONG_MIN && r2>=xmax)cout<<"2\n";
        else cout<<"-1\n";
    }
}