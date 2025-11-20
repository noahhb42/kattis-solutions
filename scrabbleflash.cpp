#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef array<ll,2> pll;
typedef array<ll,3> tll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

const ll INF = 1e9;

ll longestCommonSubstring(string &a, string &b) {
    ll best = 0,n = a.size(),m = b.size();
    rep(i,0,n){
        rep(j,0,m){
            ll len = 0;
            while (i + len < n && j + len < m && a[i + len] == b[j + len]) {
                ++len;
                best = max(best, len);
            }
        }
    }
    return best;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll u,n;cin>>u>>n;

    vector<string> words(n);
    rep(i,0,n) cin >> words[i];

    vvll cost(n, vll(n, 0));
    rep(i,0,n){
        rep(j,0,n){
            if (i == j) continue;
            ll w = words[j].size();
            ll s = longestCommonSubstring(words[i], words[j]);
            cost[i][j] = w * (w + 1) / 2 - s * (s + 1) / 2;
        }
    }

    ll FULL = 1 << n;
    ll dp[1 << 10][10];

    rep(mask,0,FULL)rep(i,0,n)dp[mask][i] = INF;

    dp[1 << 0][0] = 0;

    rep(mask,0,FULL){
        rep(last,0,n){
            ll curTime = dp[mask][last];
            if (curTime > u) continue;

            rep(nxt,0,n){
                if (mask & (1 << nxt)) continue;

                ll newMask = mask | (1 << nxt);
                ll newTime = curTime + cost[last][nxt];
                if (newTime <= u && newTime < dp[newMask][nxt]) {
                    dp[newMask][nxt] = newTime;
                }
            }
        }
    }

    ll ans = 1;
    rep(mask,0,FULL){
        rep(last,0,n){
            if (dp[mask][last] <= u){
                ll cnt = __builtin_popcount(mask);
                ans = max(ans, cnt);
            }
        }
    }

    cout << ans << "\n";
    return 0;
}
