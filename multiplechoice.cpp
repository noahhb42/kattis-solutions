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
    ll n;cin>>n;

    vector<char> key(n);
    rep(i,0,n)cin>>key[i];

    ll m;cin>>m;

    struct Stud{ll id, grade;};
    vector<Stud> v;

    rep(i,0,m){
        ll sid, correct=0;cin>>sid;
        rep(j,0,n){
            char c;cin>>c;
            correct+=(c==key[j]);
        }
        v.push_back({sid, correct});
    }

    string order;cin>>order;

    if(order=="STUDENT_ID_ASC"){
        sort(v.begin(),v.end(),[](Stud& a, Stud& b){return a.id < b.id;});
    }
    else if(order=="STUDENT_ID_DESC"){
        sort(v.begin(),v.end(),[](Stud& a, Stud& b){return a.id > b.id;});
    }
    else if(order=="GRADE_ASC"){
        sort(v.begin(),v.end(),[](Stud& a, Stud& b){if(a.grade != b.grade)return a.grade < b.grade; return a.id < b.id;});
    }
    else{
        sort(v.begin(),v.end(),[](Stud& a, Stud& b){if(a.grade != b.grade)return a.grade > b.grade; return a.id < b.id;});
    }

    for(auto stud : v){
        cout<<stud.id<<" "<<stud.grade<<"\n";
    }
}