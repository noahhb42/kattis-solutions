#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

int main(){
    ll h,m,t;char c;string d;
    cin>>h>>c>>m>>d>>t;
    
    ll h24 = 0;
    if(d=="AM"){
        if (h==12)h24=0;
        else h24=h;
    }
    else{
        if (h==12)h24=h;
        else h24=h+12;
    }
    
    ll tot = h24*60+m;
    tot-=t;
    if(tot<0)tot+=1440;
    h24 = tot/60;
    m=tot%60;
    
    if(h24==0){
        h=12;
        d="AM";
    }
    else if(h24<=11){
        h=h24;
        d="AM";
    }
    else if(h24==12){
        h=h24;
        d="PM";
    }
    else{
        h=h24-12;
        d="PM";
    }
    cout<<h<<c<<setw(2)<<setfill('0')<<m<<" "<<d<<"\n";
}