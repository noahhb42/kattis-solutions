#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

ll dr[4] = {-1,-1,1,1};
ll dc[4] = {-1,1,-1,1};

ll dfs(ll r, ll c, vector<string>& board){
    ll best = 0;
    rep(k,0,4){
        ll r1 = r+dr[k], r2 = r+2*dr[k], c1 = c+dc[k], c2 = c+2*dc[k];
        if(r2 < 0 || r2 >= 10 || c2<0 || c2>=10)continue;
        if(board[r1][c1]=='B' && board[r2][c2]=='#'){
            board[r][c]='#';
            board[r1][c1]='#';
            board[r2][c2]='W';
            ll cur = 1 + dfs(r2,c2,board);
            best=max(best,cur);
            board[r][c]='W';
            board[r1][c1]='B';
            board[r2][c2]='#';
        }
    }
    return best;
}

int main(){
    ll t;cin>>t;
    while(t--){
        vector<string> board(10);
        rep(i,0,10)cin>>board[i];
        ll ans = 0;
        rep(i,0,10){
            rep(j,0,10){
                if(board[i][j]=='W'){
                    ans=max(ans,dfs(i,j,board));
                }
            }
        }
        cout<<ans<<"\n";
    }
}