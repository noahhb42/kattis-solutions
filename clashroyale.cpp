#include"bits/stdc++.h"
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    ll n;cin>>n;
    ll best = LLONG_MAX, ind = -1;
    rep(k,0,n){
        string s; cin >> s;
        ll w = 0, l = 0, nr = 0;
        for(auto i : s){
            nr++;
            if(i == 'L')l++;
            else w++;
            if(w == 12 && nr < best){
                best = nr; ind = k+1;
            }
            if(l == 3){
                w = 0;
                l = 0;
            }
        }
    }
    if(ind == -1){
        cout << "INCOMPLETE\n";
        return 0;
    }
    cout << ind << "\n";
}