#include<bits/stdc++.h>
using namespace std;
 
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
 
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define sz size()
#define in insert
#define all(a)  a.begin(), a.end()
#define mem(arr, b) memset(arr, b, sizeof(arr))
/// memset only for -1 and 0
/// fill(a, a+n, 5) /// fill for any value
 
#define for0(i,b) for(int i=0;i<(b);i++)
#define for1(i,b) for(int i=1;i<=(b);i++)
#define forab(i,a,b) for(int i=(a);i<=(b);i++)
#define forba(i,b,a) for(int i=(b);i>=(a);i--)
 
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fileRead freopen("input.txt", "r", stdin);
#define fileWrite freopen("output.txt", "w", stdout);
#define jor(a) !(a&1) /// jor means EVEN number
#define bjor(a) (a&1) /// bjor means ODD number
#define Y() cout << "YES" << endl
#define N() cout << "NO" << endl
#define endl "\n"
const double pi = acos(-1.0);
const long long INF = 2e18;
 
///---------------------------------------------------------------------------------------
/// for debugging
 
#define printLine() cout << "----------" << endl;
 
#ifndef ONLINE_JUDGE
#define watch(x) cout << #x <<" = "; _print(x); cout << endl;
#endif
 
void _print(ll t) {cout << t;}
void _print(int t) {cout << t;}
void _print(string t) {cout << t;}
void _print(char t) {cout << t;}
void _print(double t) {cout << t;}
void _print(ull t) {cout << t;}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cout << "{"; _print(p.ff); cout << ","; _print(p.ss); cout << "}";}
template <class T> void _print(vector <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T> void _print(set <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T> void _print(multiset <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T, class V> void _print(map <T, V> v) {cout << "[ "; for (auto i : v) {_print(i); cout << " ";} cout << "]";}
 
///---------------------------------------------------------------------------------------
 
ll mod = 1e9 + 7;
const ll N = 2500 + 5;
ll n, m;
vll g[N];
vll G[N];
ll dis[N];
ll vis[N];
 
struct edge{
    ll u, v, d;
};
vector<edge> V;
 
set<ll> member;
ll from1 = 0;
ll fromN = 0;
 
set<ll> memberConnectsWith1;
 
void DFSforg(ll s) {
    vis[s] = 1;
    if(member.count(s)) {memberConnectsWith1.in(s); from1 = 1; return;}
    for(auto t : g[s]) {
        if(vis[t] == 0) {
            DFSforg(t);
        }
    }
}
 
void DFSforG(ll s) {
    vis[s] = 1;
    // 1 jader je cycle er memberder kache geche, sei cycle er member der theke ki n e asa jay?
    // oitai mainly check kortechi
    if(memberConnectsWith1.count(s)) {fromN = 1; return;}
    for(auto t : G[s]) {
        if(vis[t] == 0) {
            DFSforG(t);
        }
    }
}
 
void solve()
{
    // 1st e mone hoite pare any kind of pos cycle thaklei baad. asole ta na.
    // 1 theke n e jetei hobe. jodi onno jaygay pos cycle thake taile prob nai kintu
    // jodi 1 theke n e jabar path e kono node pos cycle er part hoye thake taile prob
    // tai pos cycler member kara ber korbo using bellman ford
    // cycle na thakle to ans max dis tai
    // thakle then reverse graph e dekhbo n theke ki eder karo kache jawa jay kina?
    // onnovabe bolle, eder karo kach theke n e asa jay kina
    // jawa gele -1 otherwise max dis(1 to n) e ans
 
    // n theke jawa jay kina + arekta jinis dekhte hobe ta holo : 1 thetke ki oikhane jawa jay?
    // karon jodi just ekta road thake oikhane theke asar? taile to hobe na. ta oikhane jabar jnno check korte hobe
 
    // main kotha hoilo ami 1 theke ekta cycle e gele oi cycle theke ki n e jawa jacche?
    // tai just cycle e gelei hobe na, same cycle e ki jacche eitao jana lagbe.
 
    cin >> n;
    cin >> m;
 
    for0(i, m) {
        ll x, y, z; cin >> x >> y >> z;
        V.pb({x, y , -z});
        g[x].pb(y); // normal graph
        G[y].pb(x); // for reverse graph
    }
 
    // bellman ford
    for1(i, n) dis[i] = INF;
    dis[1] = 0;
    ll x;
    for1(i, n) {
        x = 0;
        for(edge e : V) {
            if(dis[e.v] > dis[e.u] + e.d) {
                dis[e.v] = dis[e.u] + e.d;
                x = 1;
 
                if(i == n) { // n-th update
                    member.insert(e.u);
                }
            }
        }
    }
 
    // watch(x)
    // watch(member)
    ll ans = 0;
 
    if(x == 1) { // cycle ache
        // n theke DFS calaye dekhbo ei member der karo kache jawa jay kina
        // and t thekeo karo kache jawa jay kina
 
        DFSforg(1); //1 thekeo ki jawa jay? karon just oikhan theke aslei hobe na, oikhane jeteo hobe!
        for1(i, n) vis[i] = 0;
        DFSforG(n);
 
        if(from1 and fromN) ans = -1;
        else ans = -dis[n];
    }
    else ans = -dis[n];
 
    cout << ans << endl;
}
 
int main()
{
    #ifndef ONLINE_JUDGE
        fileRead
        fileWrite
    #endif
 
    FAST
    int tc = 1;
    // cin >> tc;
 
    for(int i = 1; i <= tc; i++){
        // cout << "Case " << i << ":\n";
        solve();
    }
}
