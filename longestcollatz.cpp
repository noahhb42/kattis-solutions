#include"bits/stdc++.h"
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll mxn = 1000001;
ll dp[mxn];

void precompute(){
    rep(i,2,mxn){
        ll steps = 0;
        ll cur = i;
        while(cur >= i){
            steps++;
            if(cur & 1)cur = 3*cur+1;
            else cur >>= 1;
        }
        dp[i] = steps + dp[cur];
    }
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    precompute();

    ll n;cin>>n;
    ll mx = -1, ind = -1;
    rep(i,1,n+1){
        if(dp[i] > mx){
            mx = dp[i];
            ind = i;
        }
    }
    cout << ind << "\n";
}