#include<bits/stdc++.h>
using namespace std;

//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx,avx2,fma")

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef vector<pii> vpii;
typedef vector<pil> vpil;
typedef vector<pli> vpli;
typedef set<int> si;
typedef set<ll> sll;
typedef map<int, int> mii;
typedef map<ll, ll> mll;

const double pi = acos(-1.0);
const long long INF = 2e18;

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define sz size()
#define in insert
#define endl "\n"

#define sqr(a) ((a) * (a))
#define jor(a) !(a&1)// jor means EVEN number
#define bjor(a) (a&1)// bjor means ODD number

#define all(a)  a.begin(), a.end()
#define mem(arr, b) memset(arr, b, sizeof(arr)) 
//memset only for -1 and 0
//fill(a, a+n, 5) //fill for any value

#define for0(i,b) for(int i=0;i<(b);i++)
#define for1(i,b) for(int i=1;i<=(b);i++)
#define forab(i,a,b) for(int i=(a);i<=(b);i++)
#define forba(i,b,a) for(int i=(b);i>=(a);i--)
#define rep(i,a,b,c) for(int i=(a);i!=(b);i+=(c))

#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fileRead freopen("input.txt", "r", stdin);
#define fileWrite freopen("output.txt", "w", stdout);

void print(int a[], int n){ // for testing or debugging
    for(int i=0;i<n;i++)cout<<a[i]<<" "; cout<<endl;
}

#define watch(x) cout << (#x) << " is " << (x) << endl;
#define Y() cout <<"YES"<<endl;
#define N() cout <<"NO"<<endl;

//-------------------------------------------------------------------


void solve()
{
	ll n; cin>>n; ll q; cin>>q;
	ll a[n]; for0(i,n) cin>>a[i];
	while(q--){
		ll x,y; cin>>x>>y;
        
        // array er value gula thakbe 1-1000 er moddhe tahole jodi query er 
        // i and j er diff 1000 theke beshi hoy taile kintu ekta num must 		  // ekbare beshi ache. ar same num thaka manei ans 0
        
        if(y-x>=1000) cout<<0<<endl;		
        else{
            vll v;
            forab(i,x,y) v.pb(a[i]);
            sort(all(v));
            ll diff=1e9;
            ll vsz=v.sz;
            for0(i,vsz-1){
                diff = min(v[i+1]-v[i], diff);
            }
            cout<<diff<<endl;
        }
	}
}

int main()
{
    FAST
    int tc=1; 
    cin>>tc;
    int testCase = 0;
    while(tc--){
        cout<<"Case "<<++testCase<<":\n";
        solve();
    }
}
