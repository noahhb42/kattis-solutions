#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef array<ll,2> pll;
typedef array<ll,3> tll;
typedef array<ll,4> qll;
#define rep(i,a,n) for(ll i=a;i<n;++i)

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll inv(ll a, ll b){ return 1<a ? b - inv(b%a,a)*b/a : 1; }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    map<string,ll>m;
    m["Mon"] = 0; m["Tue"] = 1; m["Wed"] = 2; m["Thu"] = 3; m["Fri"] = 4; m["Sat"] = 5; m["Sun"] = 6;
    string s1; ll a1; char cc1; ll b1; cin>>s1>>a1>>cc1>>b1;
    string s2; ll a2; char cc2; ll b2; cin>>s2>>a2>>cc2>>b2;
    ll n1 = m[s1]*1440 + a1*60 + b1; ll n2 = m[s2]*1440 + a2*60 + b2;
    ll fin = (n2 - n1 + 10080)%10080;
    ll day = fin/1440; ll hours = (fin%1440)/60; ll minutes = (fin%1440)%60;
    ll ok = 0;
    string sday = (day == 1 ? "day" : "days");
    string shour = (hours == 1 ? "hour" : "hours");
    string sminutes = (minutes == 1 ? "minute" : "minutes");
    if(!day&&!hours&&!minutes){
        cout<<7<<" days";
        ok = 1;
    }
    if(day&&hours&&!minutes){
        cout<<day<<" "<<sday<<" and "<<hours<<" "<<shour;
        ok = 1;
    }
    else if(day&&!hours&&minutes){
        cout<<day<<" "<<sday<<" and "<<minutes<<" "<<sminutes;
        ok = 1;
    }
    else if(!day&&hours&&minutes){
        cout<<hours<<" "<<shour<<" and "<<minutes<<" "<<sminutes;
        ok = 1;
    }

    if(!ok){
        if(day){
            if(hours||minutes) cout<<day<<" "<<sday<<", ";
            else cout<<day<<" "<<sday;
        }
        if(hours){
            if(minutes) cout<<hours<<" "<<shour<<", ";
            else cout<<hours<<" "<<shour;
        }
        if(minutes) cout<<minutes<<" "<<sminutes;
    }
}