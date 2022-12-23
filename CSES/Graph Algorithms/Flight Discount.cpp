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
const ll N = 100000 + 5;
ll n, m;
vpll gFrom1[N], gFromN[N];
ll disFrom1[N], disFromN[N];
 
void DijkstraFrom1(ll s) {
    priority_queue<pll>q; // cost node
    q.push({-0, s});
 
    vll vis(N);
 
    for1(i, n) disFrom1[i] = INF;
    disFrom1[s] = 0;
 
    while(q.sz) {
        ll u = q.top().ss;
        q.pop();
 
        if(vis[u]) continue;
        vis[u] = 1;
 
        for(auto v : gFrom1[u]) {
            ll cost = v.ff;
            ll node = v.ss;
            if(disFrom1[node] > disFrom1[u] + cost) {
                disFrom1[node] = disFrom1[u] + cost;
                q.push({-disFrom1[node], node});
            }
        }
    }
}
 
void DijkstraFromN(ll s) {
    priority_queue<pll>q; // cost node
    q.push({-0, s});
 
    vll vis(N);
 
    for1(i, n) disFromN[i] = INF;
    disFromN[s] = 0;
 
    while(q.sz) {
        ll u = q.top().ss;
        q.pop();
 
        if(vis[u]) continue;
        vis[u] = 1;
 
        for(auto v : gFromN[u]) {
            ll cost = v.ff;
            ll node = v.ss;
            if(disFromN[node] > disFromN[u] + cost) {
                disFromN[node] = disFromN[u] + cost;
                q.push({-disFromN[node], node});
            }
        }
    }
}
 
struct Edge
{
    ll u, v, cost;
};
vector<Edge> E;
 
void solve()
{
    // idea: 1 theke all node er short dis using Dijkstra
    // n theke all node er short dis using Dijkstra
    // take every edge[u v cost] and to this:  
    // dis of (1 to u) + cost / 2 + dis of (v to n)
    // after doing this for every edges, the min will be ans
    // soja kothay: u porjonoto aste min koto lage? ei edge er half nibo + ei edge theke n porjonoto jaite min koto lage?
    // ei 3 tar sum hobe ekta ans
 
    cin >> n;
    cin >> m;
 
    for1(i, m) {
        ll x, y, z; 
        cin >> x >> y >> z;
        gFrom1[x].pb({z, y});
        gFromN[y].pb({z, x}); // reverse graph
        E.pb({x, y, z});
    }
 
    DijkstraFrom1(1);
    DijkstraFromN(n);
 
    ll ans = INF;
    for(auto t : E) {
        ll x = disFrom1[t.u] + t.cost / 2 + disFromN[t.v];
        ans = min(ans, x);
    }
 
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
