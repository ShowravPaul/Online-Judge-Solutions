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
ll n, m, k;
vpll g[N];
ll dis[N][10 + 5];
 
// visited use korle kaaj hoy na. example:
// 5 6 3
// 1 2 3
// 1 4 2
// 2 3 1
// 2 4 1
// 3 4 1
// 4 5 1
 
void Dijkstra(ll s) {
    priority_queue<pll>q; // cost node
    q.push({-0, s});
    
    for1(i, n) {
        for0(j, k+5) dis[i][j] = INF;
    }
    dis[s][0] = 0;
 
    while(q.sz) {
        ll u = q.top().ss;
        ll costTillU = -q.top().ff; // u porjonto aste best dis
        q.pop();
 
        if(costTillU > dis[u][k-1]) continue;
        // no vis array. jevabe jekhane jaite pare jabe 
        // kintu distance first k tar moddhe thaka lagbe
 
        for(auto v : g[u]) {
            ll costUV = v.ff;
            ll node = v.ss;
 
            // ei node e asar k ta value er moddhe eita ki ekta hoite pare?
            // hoile last value baad diye eita rakhbo
            if(dis[node][k-1] > costTillU + costUV) {
                ll newCost = costTillU + costUV;
 
                dis[node][k-1] = newCost;
                sort(dis[node], dis[node] + k); // array nichi tai eivabe sort
 
                q.push({-newCost, node});
            }
        }
    }
}
 
void solve()
{
    // idea : dijkstra er motoi. kintu every node e value mark korte korte jabo. 
    // oi node e k ta value mark kore rakhbo. 
    // oi node e jaite best k ta distance ke mark kore rakhbo. 
    // eivabe korle dis[4] e 4 no node e jabar best k ta distance pabo
    // initially sob dis INF thakbe
    // prob e bola ache minimum k ta diff route achei
 
    // every time dekhbo mark kora value gular moddhe aste parbe kina, 
    // parle niye nibo ar sobceye max dis er ta baad
 
    cin >> n;
    cin >> m;
    cin >> k;
 
    for0(i, m) {
        ll x, y, z;
        cin >> x >> y >> z;
        g[x].pb({z, y});
    }
 
    Dijkstra(1);
 
    for0(i, k) cout << dis[n][i] << " ";
    cout << endl;
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
