#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef array<ll,2> pll;
typedef array<ll,3> tll;
#define rep(i,a,n) for(ll i = a ; i<n ; ++i)

ll to_seconds_12h(string& hms, string& ampm){
    ll h,m,s;
    char c1,c2;
    stringstream ss(hms);
    ss >> h >> c1 >> m >> c2 >> s;
    ll h24 = h%12;
    if(ampm == "PM")h24+=12;
    return 3600*h24+60*m+s;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    string start_hms, start_ampm;
    cin>>start_hms >> start_ampm;
    ll startsec = to_seconds_12h(start_hms,start_ampm);
    ll limit = startsec + 3*3600;

    ll n;cin>>n;
    string dump;getline(cin,dump);

    ll prev_abs = -4e18;
    ll day = 0;

    unordered_map<string, ll> beforeCnt, finishTime;

    rep(i,0,n){
        string line;getline(cin,line);

        string hms, ampm;
        stringstream ss(line);
        ss >> hms >> ampm;

        ll pos = line.find(ampm);
        string name = line.substr(pos+ampm.size());
        if(!name.empty() && name[0]==' ')name.erase(name.begin());

        ll t = to_seconds_12h(hms,ampm);
        ll abs_t = t + day*86400;
        if(abs_t <= prev_abs){
            day++;
            abs_t = t + day*86400;
        }
        prev_abs = abs_t;

        if(finishTime.find(name) != finishTime.end())continue;

        if(abs_t < limit){
            beforeCnt[name]++;
        }
        else{
            finishTime[name] = abs_t;
        }
    }

    struct Participant{ll laps, fin; string name;};
    vector<Participant> par;
    for(auto [k,v] : finishTime){
        string name = k;
        ll fin = v;
        ll laps = (beforeCnt.count(name) ? beforeCnt[name] : 0) + 1;
        par.push_back({laps, fin, name});
    }

    sort(par.begin(),par.end(),[](Participant& a, Participant& b){
        if(a.laps != b.laps) return a.laps > b.laps;
        if(a.fin != b.fin)return a.fin < b.fin;
        return a.name < b.name;
    });

    for(auto p : par){
        cout<<p.laps<<" "<<p.name<<"\n";
    }
}
