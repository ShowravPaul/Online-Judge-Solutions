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
vpll g[N];
ll dis[N];
ll vis[N];
 
void BFS(ll src) {
    priority_queue<pll>pq;
    pq.push({-0, src}); // cost and node
    dis[src] = 0;
 
    while(pq.sz) {
        ll cost = -pq.top().ff; // 1 theke u er dis
        ll u = pq.top().ss;
        pq.pop();
 
        if(vis[u]) continue;
        vis[u] = 1;
 
        for(auto v : g[u]) {
            ll newDis = cost + v.ff; // 1 theke v er dis valo? naki u hoye 1 theke v er dis valo?
            if(dis[v.ss] > newDis) { // distance update
                dis[v.ss] = newDis;
                pq.push({-newDis, v.ss});
            }
        }
    }
}
 
void solve() {
    cin >> n >> m;
 
    for0(i, m) {
        ll u, v, d; 
        cin >> u >> v >> d;
        g[u].pb({d, v}); // one way road and {cost,node} pair
    }
 
    for1(i, n) dis[i] = INF, vis[i] = 0;
 
    BFS(1);
 
    for1(i, n) cout << dis[i] << " ";
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
