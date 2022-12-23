#include<bits/stdc++.h>
using namespace std;

//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx,avx2,fma")

typedef long long ll;
typedef unsigned long long ull;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

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
#define jor(a) !(a&1) /// jor means EVEN number
#define bjor(a) (a&1) /// bjor means ODD number

#define all(a)  a.begin(), a.end()
#define mem(arr, b) memset(arr, b, sizeof(arr)) 
/// memset only for -1 and 0
/// fill(a, a+n, 5) /// fill for any value

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
void printll(ll a[], ll n){ // for testing or debugging
    for(int i=0;i<n;i++)cout<<a[i]<<" "; cout<<endl;
}

#define watch(x) cout << (#x) << " is " << (x) << endl;
#define Y() cout << "YES" << endl;
#define N() cout << "NO" << endl;

///------------------------------------------------------------------
/// some useful functions

ll const mx = 1e6+2, mod=1000003; // vuleo 1e6+3 er factorial ber kora jabe na, taile mod korle kintu ans 0 asbe. karon 1e6+3 ! er moddhe 1e6+3 gun hobe, jodi 10 mod korte bole 10! nile to 10 gun hobei ar tokhon mod 0 asbe tai sabdhan

ll fact[mx];
ll modInvFact[mx];

void findAllFact()
{
	fact[0]=1;
	for(int i=1; i<mx; i++) fact[i] = (1LL*i*fact[i-1])%mod;
}

ll mod_exp(ll n, ll p)
{
	if(p==-1) p=mod-2;
	ll ans=1;
	while(p){
	    if(p&1) ans=(1LL*ans*n)%mod;
       	    n=(1LL*n*n)%mod;
	    p=p/2;
	}
	return ans;
}

void findAllmodInvFact(){
	modInvFact[0]=1;
	modInvFact[mx-1] = mod_exp(fact[mx-1], -1);
	for(ll i=mx-2; i>=1; i--) modInvFact[i] = (modInvFact[i+1]*(i+1))%mod;
}

void solve(){
	ll n; cin>>n; 
    ll m; cin>>m;
	cout<<((fact[n]*modInvFact[n-m])%mod*modInvFact[m])%mod<<endl;
}

int main()
{
	findAllFact();
	findAllmodInvFact();
    int tc=1; 
    cin>>tc;
    int testCase = 0;
    while(tc--){
        cout<<"Case "<<++testCase<<": ";
        solve();
    }
}
