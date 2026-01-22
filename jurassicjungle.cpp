#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

int main(){
    ll n,m;
    while(cin>>n>>m){
        if(n == -1 && m == -1)break;
        
        if(n == m){
            cout << "YES\n";
            rep(i,0,n)cout << (i%n)+1 << " " << ((i+1)%n)+1 << "\n";
            continue;
        }
        
        if(m == n*(n-1)/2){
            cout << "YES\n";
            rep(i,0,n){
                rep(j,0,i)cout<<j+1 << " " << i+1 << "\n";
            }
            continue;
        }
        
        if(n%2 == 0){
            if (m == n*n/4){
                cout << "YES\n";
                for(ll i = 1 ; i<=n ; i+=2){
                    for(ll j = 2 ; j<=n ; j+=2){
                        cout << i << " " << j << "\n";
                    }
                }
                continue;
            }
            cout << "NO\n";
            continue;
        }
        
        cout << "NO\n";
        
    }
    
    return 0;
}