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
#define jor(a) !(a&1) //jor means EVEN number
#define bjor(a) (a&1) //bjor means ODD number

#define all(a)  a.begin(), a.end()
#define mem(arr, b) memset(arr, b, sizeof(arr)) //memset only for -1 and 0
//fill(a, a+n, 5) //fill for any value

#define for0(i,b) for(int i=0;i<(b);i++)
#define for1(i,b) for(int i=1;i<=(b);i++)
#define forab(i,a,b) for(int i=(a);i<=(b);i++)
#define forba(i,b,a) for(int i=(b);i>=(a);i--)
#define rep(i,a,b,c) for(int i=(a);i!=(b);i+=(c))

#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define fileRead freopen("input.txt", "r", stdin);
#define fileWrite freopen("output.txt", "w", stdout);

void printIntArray(int a[], int n){ // for testing or debugging
    for(int i=0;i<n;i++)cout<<a[i]<<" "; cout<<endl;
}
void printLLArray(ll a[], ll n){ // for testing or debugging
    for(int i=0;i<n;i++)cout<<a[i]<<" "; cout<<endl;
}

#define watch(x) cout << (#x) << " is " << (x) << endl;

//-------------------------------------------------------------------

int r[25], g[25], b[25]; // 0 1 2
int n;
int dp[25][3];

int f(int pos, int prev){
	if(pos==n) return 0;
	if(dp[pos][prev]!=-1) return dp[pos][prev];
	
	int ans=1e9;
	
	if(prev==0){
		ans = min(ans, g[pos]+f(pos+1, 1));
		ans = min(ans, b[pos]+f(pos+1, 2));
	}
	else if(prev==1){
		ans = min(ans, r[pos]+f(pos+1, 0));
		ans = min(ans, b[pos]+f(pos+1, 2));
	}
	else if(prev==2){
		ans = min(ans, g[pos]+f(pos+1, 1));
		ans = min(ans, r[pos]+f(pos+1, 0));
	}
	
	return dp[pos][prev] = ans;
}

void solve()
{
	mem(dp, -1);
	cin>>n;
	for0(i,n) cin>>r[i]>>g[i]>>b[i];
	
	int R = r[0]+f(1, 0);
	int G = g[0]+f(1, 1);
	int B = b[0]+f(1, 2);
	
	cout<<min({R,G,B})<<endl;
}

int main()
{
    FAST
    //fileRead
    int tc = 1;
    cin>>tc;
    int testCase=1;
    while(tc--)
    {
    	cout<<"Case "<<testCase++<<": ";
    	solve();
    }
}

