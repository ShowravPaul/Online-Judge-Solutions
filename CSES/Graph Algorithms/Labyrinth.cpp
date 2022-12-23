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
ll mod = 1e9+7;
const ll N = 1000 + 5;
 
ll n, m;
ll a,b,c,d;
char g[N][N];
ll vis[N][N];
pair<ll, ll> parent[N][N];
ll ok = 0;
 
ll X[4] = {0, 0, 1, -1};
ll Y[4] = {1, -1, 0, 0};
 
bool isValid(ll x, ll y) {
    if(x == n || y == m) return false;
    if(x == -1 || y == -1) return false;
    if(vis[x][y]) return false;
    if(g[x][y] == '#') return false;
    return true;
}
 
void BFS(ll xx, ll yy) {
    queue<pair<ll, ll>> q;
    q.push({xx, yy});
    vis[xx][yy] = 1;
    parent[xx][yy] = {-1, -1};
 
    while(!q.empty()) {
        ll x = q.front().ff;
        ll y = q.front().ss;
        q.pop();
 
        for0(i, 4) {
            ll A = x + X[i];
            ll B = y + Y[i];
            if(isValid(A, B)) {
            	vis[A][B] = 1;
            	parent[A][B] = {x, y};
            	pll tem = {A,B};
            	q.push({A, B});
 
            	if(g[A][B] == 'B') {ok = 1; return;}
            }
        }
    }
}
 
void solve()
{
	cin >> n >> m;
 
	for0(i, n) {
		for0(j, m) {
			char x; cin >> x;
			g[i][j] = x;
			vis[i][j] = 0;
			if(x == 'A') a = i, b = j;
			if(x == 'B') c = i, d = j;
		}
	}
 
	BFS(a, b);
 
	if(!ok) {cout << "NO" << endl; return;}
 
	string ans = "";
	pair<ll, ll> x = {c, d};
	// watch(parent[c][d])
 
	while(!(x.ff == a && x.ss == b)) {
		pll R = {x.ff, x.ss+1};
		pll L = {x.ff, x.ss-1};
		pll U = {x.ff-1, x.ss};
		pll D = {x.ff+1, x.ss};
 
		pll p = parent[x.ff][x.ss];
		if(p == R) ans += 'L';
		else if(p == L) ans += 'R';
		else if(p == U) ans += 'D';
		else ans += 'U';
 
		x = parent[x.ff][x.ss];
	}
 
	reverse(all(ans));
	cout << "YES\n" << ans.size() << endl << ans << endl;
}
 
int main()
{
    #ifndef ONLINE_JUDGE
        fileRead
        fileWrite
    #endif
 
    FAST
    int tc=1;
    // cin>>tc;
 
    for(int i=1; i<=tc; i++){
        // cout<<"Case "<<i<<": ";
        solve();
    }
}
