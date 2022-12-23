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
#define Y() cout <<"YES"<<endl
#define N() cout <<"NO"<<endl

//-------------------------------------------------------------------

vll g[20005];
bool vis[20005];
ll L, V;

void dfs(ll start, ll prev){
    vis[start] = 1;

    if(prev==0) L++;
    else V++;

    for(auto t: g[start]){
        if(!vis[t]){
            if(prev==0) dfs(t, 1);
            else dfs(t, 0);
        }
    }
}

void solve()
{
    // clear
    for0(i, 20005) g[i].clear(), vis[i]=0;
    V=L=0;

    // input
    ll n; cin>>n;
    for0(i,n){
        ll x, y; cin>>x>>y;
        g[x].pb(y), g[y].pb(x);
    }

    // dfs start if a node is not visited
    ll ans=0;
    for1(i, 20000){
        if(g[i].sz and !vis[i]){
            dfs(i, 0);
            ans += max(L,V);
            L=0, V=0;
        }
    }

    cout<<ans<<endl;
}

int main()
{
    int tc=1;
    cin>>tc;
    int testCase = 0;
    while(tc--){
        cout<<"Case "<<++testCase<<": ";
        solve();
    }
}

