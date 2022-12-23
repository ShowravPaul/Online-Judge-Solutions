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
 
#define Y() cout << "YES" << endl
#define N() cout << "NO" << endl
 
///---------------------------------------------------------------------------------------
/// for debugging
 
#define printLine() cout << "----------" << endl;
 
#ifndef ONLINE_JUDGE
#define debug(x) cout << #x <<" "; _print(x); cout << endl;
#else
#define debug(x)
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
/// some useful functions
 
#define MAX 1000005
int prime[MAX];
vector<int> allPrimes;//primes
 
void sieve()
{
    memset(prime,0, sizeof(prime));//na dileo hobe. emniteo global array. so all element 0
    prime[0]=prime[1]=1;// 0 and 1 prime na
    for(int i = 4; i < MAX; i+= 2) prime[i] = 1;//2 prime, 4 theke suru kore ar baki sob even num prime na
    
    for(int i = 3; i*i < MAX; i+=2)
    {
        if(prime[i]==0)
        {
            for(int j = i*i; j < MAX; j+=i)
            prime[j]=1;
        }
    }
 
    for(int i = 2; i < MAX; i++)
        if(prime[i]==0)
            allPrimes.push_back(i);// sob prime rakhlam p vector e
 
}
 
vector<ll>findPrimeFactors(ll n)
{
    vector<ll> primeFactors;
    while (n%2== 0) primeFactors.push_back(2), n = n/2;
    for (ll i = 3; i*i <= n; i = i+2)
    {
        while (n%i == 0)
        {
            primeFactors.push_back(i);
            n = n/i;
        }
    }
    if (n > 2) primeFactors.push_back(n);
    return primeFactors;
}
 
vector<long long> allDivisiors(long long n){
    vector<long long>divisors;
    for(ll i=1; i*i<=n; i++){
        if(n%i==0){
            if(n/i==i) divisors.push_back(i);
            else divisors.push_back(i), divisors.push_back(n/i);
        }
    }
    return divisors;
}
 
bool isPrime(ll n)
{
    if(n==2 or n==3) return true;
    if(n%2==0) return false;
    for(ll i=3; i*i<=n; i+=2) if(n%i==0) return false;
    return true;
}
 
ll nsum(ll n){
    return (n*(n+1))/2;
}
 
ll power(ll n, ll p)
{
	if(p==0) return 1;
	if(p==1) return n;
	ll ans=1;
	while(p){
	    if(p&1) ans=ans*n;
        n=n*n;
        p=p/2;
	}
	return ans;
}
 
ll mpower(ll n, ll p, ll mod)
{
	if(p==-1) p=mod-2;
	if(p==0) return 1;
	if(p==1) return n;
	ll ans=1;
	while(p){
		if(p&1) ans=((ans%mod)*n)%mod;
        n=((n%mod)*(n%mod))%mod;
		p=p/2;
	}
	return ans;
}
 
bool isPalindrome(string s){
	int N = s.sz;
	for0(i,N/2){
		if(s[i]!=s[N-1-i]) return 0;
	}
	return 1;
}
 
ll stringToInt(string s){
	ll pow10=1;
	ll ans=0;
	forba(i, s.sz-1, 0){
		ans += (s[i]-'0')*pow10;
		pow10*=10;
	}
	return ans;
}
 
///---------------------------------------------------------------------------------------
// comparison structure to use customized set/vector
// example: 1st value choto hisabe and 2nd value boro hisabe rakhbe
// 1 2
// 4 3
// 4 1
 
struct compStruct {
    bool operator() (pair<int, int> const & a, pair<int, int> const & b) const
    {
    	if(a.ff != b.ff) return a.ff < b.ff;
    	return a.ss > b.ss;
    }
};
 
///---------------------------------------------------------------------------------------
/// bitmask related things
/// pos is 0 based index and starts from left to right: [32 31 30 ... ... ... 3 2 1 0]
 
ll onbit(ll N, ll pos){
    return N = N | (1<<pos);
}
ll offbit(ll N, ll pos){
    return N = N & ~(1<<pos);
    //or return N = N & !(1<<pos);
}
ll flipbit(ll N, ll pos){
    return N = N ^ (1<<pos);
}
bool checkbit(ll N, ll pos){
    return (bool)(N & (1<<pos));
}
 
/// for flipping use ^ with 1
/// For DP: state, transition, base, return, memorization
///---------------------------------------------------------------------------------------
ll mod=1e9+7;
 
void solve()
{
    ll k; cin>>k;
    // total = n*n C 2 
    for1(i,k){
    	ll tem = i*i;
    	ll total = tem*(tem-1) / 2;
    	ll baad = 2*2*(i-1)*(i-2);
    	cout<<total - baad<<endl;
    }
}
 
int main()
{
    // fileRead
    FAST
    int tc=1;
    // cin>>tc;
 
	for(int i=1; i<=tc; i++){
		// cout<<"Case "<<i<<": ";
		solve();
	}
}
