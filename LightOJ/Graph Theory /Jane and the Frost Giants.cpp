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
const ll N = 200 + 5;
ll n, m;
char g[N][N];
ll fireTime[N][N];
ll ans = INF;
ll vis[N][N];
ll X[4] = {1, -1, 0, 0};
ll Y[4] = {0, 0, 1, -1};

void clear(bool makeINF) {
    for0(i, n) {
        for0(j, m) {
            if(makeINF and g[i][j] != '#') fireTime[i][j] = INF;
            vis[i][j] = 0;
        }
    }
}

bool isValidForFire(ll x, ll y) {
    if(x == n or x == -1 or y == -1 or y == m) return false;
    if(vis[x][y]) return false;
    if(g[x][y] == '#') return false;
    return true;
}

void fireBFS(vpll f) {

    // a que: BFS er moddhe visited, parent, distance update ei kaaj gula ki loop er baire korbo naki vetore?
    // ans: loop er moddhe
    // karon: kaaj repeted hoy onk. karon visited na korei queue te rakhle ta ektu pore onno keu ese jokhon dekhe visited na tokhon abar queue te rakhle
    // ar queue theke niye kaaj korar somoy to amra checko kori na je visited kina, tai same jinis 2 bar queue te rakhle tar kaaj 2 bar kora hocche
    // eivabe kaaj repeat hoy tai loop er moddhei ei sob kaaj kora ucit
    // DFS eo loop er moddhe kaaj korar try korbo, tobe DFS e maybe problem hobe na. karon oikhane kaaj shuru korar sathe sathe visited hoye jay.
    // queue te mainly kaaj jomaya rakha hoy pore korbe bole. kintu loop er baire kaajgula korle kaaj repeated hoite pare!
    // lightoj Jane and the Frost Giants korte gia shikhlam

    // sob f theke distance gula same frequencey te sprade hobe
    // tai sob queue te rekhe then every F theke BFS cholbe
    queue<pair<pair<ll, ll>, ll> > q;
    for(auto t: f) q.push({{t.ff, t.ss}, 0}), vis[t.ff][t.ss] = 1, fireTime[t.ff][t.ss] = 0;

    while(q.sz) {       
        ll presentX = q.front().ff.ff;
        ll presentY = q.front().ff.ss;
        ll presentD = q.front().ss;
        q.pop();

        for0(i, 4) {
            ll newX = presentX + X[i], newY = presentY + Y[i];
            if(isValidForFire(newX, newY)) {
                vis[newX][newY] = 1;
                q.push({{newX, newY}, presentD + 1});
                fireTime[newX][newY] = presentD + 1;
            }
        }
    }
}

void personDFS(ll x, ll y, ll d) {
    queue<pair<pair<ll, ll>, ll> > q;
    q.push({{x, y}, 0});

    vis[x][y] = 1;

    while(q.sz) {
        ll presentX = q.front().ff.ff;
        ll presentY = q.front().ff.ss;
        ll presentD = q.front().ss;
        q.pop();

        for0(i, 4) {
            ll newX = presentX + X[i], newY = presentY + Y[i];
            if(newX == n or newX == -1 or newY == -1 or newY == m) ans = min(ans, presentD + 1);
            if(!vis[newX][newY] and g[newX][newY] != '#' and g[newX][newY]) {
                if(presentD + 1 < fireTime[newX][newY]) {
                    vis[newX][newY] = 1;
                    q.push({{newX, newY}, presentD + 1});
                }
            }
        }
    }
}

void solve()
{
    cin >> n >> m;
    ll px, py;
    vpll f;
    for0(i, n) {
        for0(j, m) {
            cin >> g[i][j];
            if(g[i][j] == 'J') px = i, py = j;
            if(g[i][j] == 'F') f.pb({i, j});
        }
    }

    // clear
    clear(1);
    ans = INF;

    // fireTime from every fire source
    clear(0);
    fireBFS(f);

    // personDFS run
    clear(0);
    personDFS(px, py, 0);

    if(ans == INF) cout << "IMPOSSIBLE\n";
    else cout << ans << endl;
}

int main()
{
    #ifndef ONLINE_JUDGE
        fileRead
        fileWrite
    #endif

    FAST
    int tc=1;
    cin>>tc;

    for(int i=1; i<=tc; i++){
        cout<<"Case "<<i<<": ";
        solve();
    }
}
