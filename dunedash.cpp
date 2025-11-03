#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef array<ll,2> pll;
typedef array<ll,3> tll;
typedef array<ll,4> qll;
#define rep(i,a,n) for(ll i=a;i<n;++i)

struct Pt {
    ll x, y;
    bool operator<(const Pt& o) const {
        return x < o.x || (x == o.x && y < o.y);
    }
};

ll cross(const Pt& a, const Pt& b, const Pt& c) {
    return (b.x - a.x)*(c.y - a.y) - (b.y - a.y)*(c.x - a.x);
}

ll dist2(const Pt& a, const Pt& b) {
    ll dx = b.x - a.x;
    ll dy = b.y - a.y;
    return dx*dx + dy*dy;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    vector<Pt> pts(n);
    for (auto &p : pts) cin >> p.x >> p.y;

    sort(pts.begin(), pts.end());
    vector<Pt> H;
    for (auto &p : pts) {
        while (H.size() >= 2 && cross(H[H.size()-2], H.back(), p) <= 0) H.pop_back();
        H.push_back(p);
    }
    size_t lower = H.size();
    for (int i = n-2; i >= 0; --i) {
        while (H.size() > lower && cross(H[H.size()-2], H.back(), pts[i]) <= 0) H.pop_back();
        H.push_back(pts[i]);
    }
    H.pop_back();

    int h = H.size();
    int a = 0, b = 1;
    ll best = dist2(H[0], H[1]);
    int j = 1;
    for (int i = 0; i < h; i++) {
        int ni = (i + 1) % h;
        while (abs((long long)cross(H[i], H[ni], H[(j + 1) % h])) > abs((long long)cross(H[i], H[ni], H[j]))) {
            j = (j + 1) % h;
        }
        if (dist2(H[i], H[j]) > best) { best = dist2(H[i], H[j]); a = i; b = j; }
    }

    Pt A = H[a], B = H[b];
    long long vx = B.x - A.x, vy = B.y - A.y;

    vector<pair<ll,int>> key;
    key.reserve(n);
    for (int i = 0; i < n; ++i) {
        ll proj = (ll)(pts[i].x - A.x)*vx + (ll)(pts[i].y - A.y)*vy;
        key.emplace_back(proj, i);
    }
    sort(key.begin(), key.end());

    long double total = 0;
    for (int i = 1; i < n; ++i) {
        auto &P = pts[key[i-1].second];
        auto &Q = pts[key[i].second];
        long double dx = (long double)Q.x - P.x;
        long double dy = (long double)Q.y - P.y;
        total += sqrtl(dx*dx + dy*dy);
    }

    cout << setprecision(10) << (double)total << "\n";
    return 0;
}