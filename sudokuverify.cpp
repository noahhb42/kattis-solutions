#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef array<ll,2> pll;
typedef array<ll,3> tll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll sudoku[9][9];
    rep(i,0,9)rep(j,0,9)cin>>sudoku[i][j];
    set<ll> s;
    rep(i,0,9){
        rep(j,0,9){
            s.insert(sudoku[i][j]);
        }
        if(s.size()<9){
            cout<<"INVALID!\n";
            return 0;
        }
        s.clear();
        rep(j,0,9){
            s.insert(sudoku[j][i]);
        }
        if(s.size()<9){
            cout<<"INVALID!\n";
            return 0;
        }
        s.clear();
    }
    rep(k,0,3){
        rep(l,0,3){
            rep(i,0,3){
                rep(j,0,3){
                    s.insert(sudoku[k*3+i][l*3+j]);
                }
            }
            if(s.size()<9){
                cout<<"INVALID!\n";
                return 0;
            }
            s.clear();
        }
    }
    cout<<"VALID\n";
}