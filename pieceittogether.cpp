#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef array<ll,2> pll;
typedef array<ll,3> tll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

struct TwoSAT {
    ll N;
    vvll g, gr;
    vll comp, order;
    vector<char> used;

    TwoSAT(ll n = 0) {
        init(n);
    }

    void init(ll n) {
        N = n;
        g.assign(2 * N, vll());
        gr.assign(2 * N, vll());
        comp.clear();
        order.clear();
        used.clear();
    }

    ll node(ll var, bool val) {
        return var * 2 + (val ? 1 : 0);
    }

    void addImp(ll u, ll v) {
        g[u].push_back(v);
        gr[v].push_back(u);
    }

    void addOr(ll x, bool x_val, ll y, bool y_val) {
        ll a = node(x, x_val);
        ll b = node(y, y_val);
        addImp(a ^ 1, b);
        addImp(b ^ 1, a);
    }

    void addUnit(ll x, bool val) {
        ll a = node(x, val);
        addImp(a ^ 1, a);
    }

    void dfs1(ll start) {
        stack<pll> st;
        st.push({start, 0});
        used[start] = 1;
        while (!st.empty()) {
            pll &cur = st.top();
            ll v = cur[0];
            ll &idx = cur[1];
            if (idx < (ll)g[v].size()) {
                ll to = g[v][idx++];
                if (!used[to]) {
                    used[to] = 1;
                    st.push({to, 0});
                }
            } else {
                order.push_back(v);
                st.pop();
            }
        }
    }

    void dfs2(ll start, ll c) {
        stack<ll> st;
        st.push(start);
        comp[start] = c;
        while (!st.empty()) {
            ll v = st.top();
            st.pop();
            for (ll to : gr[v]) {
                if (comp[to] == -1) {
                    comp[to] = c;
                    st.push(to);
                }
            }
        }
    }

    bool satisfiable() {
        ll n2 = 2 * N;
        used.assign(n2, 0);
        order.clear();
        order.reserve(n2);

        rep(i, 0, n2) {
            if (!used[i]) dfs1(i);
        }

        comp.assign(n2, -1);
        ll j = 0;
        for (ll idx = n2 - 1; idx >= 0; --idx) {
            ll v = order[idx];
            if (comp[v] == -1) {
                dfs2(v, j++);
            }
        }

        rep(i, 0, N) {
            if (comp[2 * i] == comp[2 * i + 1]) return false;
        }
        return true;
    }
};

int main(){
    cin.tie(0)->sync_with_stdio(0);

    ll n,m;cin>>n>>m;
    vector<string> grid(n);
    for(auto&i:grid)cin>>i;

    ll Bcnt=0,Wcnt=0;
    rep(i,0,n){
        rep(j,0,m){
            if(grid[i][j]=='B')++Bcnt;
            else if(grid[i][j]=='W')++Wcnt;
        }
    }

    if(Wcnt!=2*Bcnt){
        cout<<"NO\n";
        return 0;
    }

    ll Ncells = n*m;
    ll UP=0, RIGHT=1, DOWN=2, LEFT=3;
    ll dx[4] = {-1,0,1,0};
    ll dy[4] = {0,1,0,-1};

    vector<array<ll,4>> varId(Ncells);
    rep(i,0,Ncells){
        rep(d,0,4){
            varId[i][d]=-1;
        }
    }

    ll varCount = 0;

    rep(i,0,n){
        rep(j,0,m){
            if(grid[i][j]!='B')continue;
            ll idxB=i*m+j;
            rep(d,0,4){
                ll ni=i+dx[d],nj=j+dy[d];
                if(ni<0 || nj<0 || ni>=n || nj>=m)continue;
                if(grid[ni][nj]=='W'){
                    varId[idxB][d]=varCount++;
                }
            }
        }
    }

    TwoSAT sat(varCount);

    rep(i,0,n){
        rep(j,0,m){
            if(grid[i][j]!='B')continue;
            ll idxB = i*m+j;

            vll horiz,vert;
            if (varId[idxB][LEFT] != -1) horiz.push_back(varId[idxB][LEFT]);
            if (varId[idxB][RIGHT] != -1) horiz.push_back(varId[idxB][RIGHT]);
            if (varId[idxB][UP] != -1) vert.push_back(varId[idxB][UP]);
            if (varId[idxB][DOWN] != -1) vert.push_back(varId[idxB][DOWN]);

            if(horiz.empty() || vert.empty()){
                cout<<"NO\n";
                return 0;
            }

            if(horiz.size()==1){
                sat.addUnit(horiz[0],true);
            }
            else if(horiz.size()==2){
                ll a=horiz[0],b=horiz[1];
                sat.addOr(a,true,b,true);
                sat.addOr(a,false,b,false);
            }

            if (vert.size()==1) {
                sat.addUnit(vert[0], true);
            }
            else if (vert.size()==2) {
                ll a=vert[0],b=vert[1];
                sat.addOr(a,true,b,true);
                sat.addOr(a,false,b,false);
            }
        }
    }

    ll opp[4];
    opp[UP] = DOWN;
    opp[RIGHT] = LEFT;
    opp[DOWN] = UP;
    opp[LEFT] = RIGHT;

    rep(i,0,n){
        rep(j,0,m){
            if(grid[i][j]!='W')continue;

            vll adjVars;
            rep(d, 0, 4) {
                ll ni = i + dx[d], nj = j + dy[d];
                if (ni < 0 || nj < 0 || ni >= n || nj >= m) continue;
                if (grid[ni][nj] != 'B') continue;
                ll idxB = ni * m + nj;
                ll dirFromB = opp[d];
                ll v = varId[idxB][dirFromB];
                if (v != -1) adjVars.push_back(v);
            }

            if(adjVars.empty()){
                cout<<"NO\n";
                return 0;
            }

            ll k = adjVars.size();
            rep(a,0,k){
                rep(b,a+1,k){
                    sat.addOr(adjVars[a],false,adjVars[b],false);
                }
            }
        }
    }

    bool ok = sat.satisfiable();
    cout << (ok ? "YES\n" : "NO\n");

    return 0;
}