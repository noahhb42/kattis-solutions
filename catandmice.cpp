#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef array<ll,2> pll;
typedef array<ll,3> tll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

const long double INF = 1e100;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll n;cin>>n;

    vector<long double> x(n), y(n), s(n);
    rep(i,0,n){
        cin >> x[i] >> y[i] >> s[i];
    }
    long double m;cin>>m;

    vector<long double> dist0(n);
    vector<vector<long double>> dist(n, vector<long double>(n));
    rep(i,0,n){
        dist0[i] = hypot(x[i], y[i]);
        rep(j,0,n){
            dist[i][j] = hypot(x[i] - x[j], y[i] - y[j]);
        }
    }

    vector<long double> powm(n + 1);
    powm[0] = 1.0;
    rep(k,1,n+1){
        powm[k] = powm[k - 1] * m;
    }

    auto can = [&](long double v0){
        ll FULL = 1 << n;
        static long double dp[1 << 15][15];
        rep(mask,0,FULL)rep(i,0,n)dp[mask][i] = INF;

        rep(mask,1,FULL) {
            ll k = __builtin_popcountll(mask);
            rep(i,0,n) {
                if (!(mask & (1 << i))) continue;
                if (k == 1) {
                    long double time = dist0[i] / v0;
                    if (time <= s[i] + 1e-9) dp[mask][i] = time;
                } 
                else {
                    ll pmask = mask ^ (1 << i);
                    long double v_leg = v0 * powm[k - 1];
                    long double best = INF;

                    rep(j,0,n) {
                        if (!(pmask & (1 << j))) continue;
                        long double prev = dp[pmask][j];
                        if (prev >= INF) continue;
                        long double candidate = prev + dist[j][i] / v_leg;
                        if (candidate < best) best = candidate;
                    }

                    if (best <= s[i] + 1e-9)
                        dp[mask][i] = best;
                }
            }
        }

        ll ALL = FULL - 1;
        rep(i,0,n){
            if (dp[ALL][i] < INF) return true;
        }
        return false;
    };

    long double lo = 0.0, hi = 1.0;
    while (!can(hi)) hi *= 2.0;

    rep(it,0,60) {
        long double mid = 0.5 * (lo + hi);
        if (can(mid)) hi = mid;
        else lo = mid;
    }

    cout << fixed << setprecision(10) << hi << "\n";
    return 0;
}
