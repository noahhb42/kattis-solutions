#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

int main(){
    string a,b;cin>>a>>b;
    ll n = a.size(), m = b.size();
    
    ll i = 0;
    while(i<n && i<m && a[i]==b[i])i++;
    ll j = 0;
    while(n-1-j>=i && m-1-j>=i && a[n-1-j]==b[m-1-j])j++;
    
    cout<<m-i-j<<"\n";
}