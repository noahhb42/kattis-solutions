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
    string ans = "";
    string cur;
    rep(i,0,n){cin>>cur; ans += (cur[i]=='0' ? '1' : '0');}
    cout<<ans<<"\n";
}