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

///-------------------------------------------------------------------
/// some useful functions

vector <ll> findPrimeFactors(ll n)
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
    ll limit=sqrt(n+1);
    for(ll i=1; i<=limit; i++){
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
		if(p&1) ans=(ans*n)%mod;
        n=(n*n)%mod;
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

/// for flipping use ^ with 1

///-------------------------------------------------------------------

ll countInFact(ll N, ll x){
    ll i=1;
    ll ans=0;
    while(1){
        if(power(x,i)>N) return ans;
        ans += N/power(x,i), i++;
    }
}

void solve()
{
    ll n,r; cin>>n>>r;
    ll p,q; cin>>p>>q;

//    count 5 and 2, for making 10

//    p^q er jnno
//    prime factorize p, 12 hoile 2 2 3, ekhon 12^2 hoile 2 2 3 2 2 3 mane map akare likhle
//    12^1 = 2-2, 3-1
//    12^2 = 2-4, 3-2
//    12^3 = 2-6, 3-3
//    mane prime factorize kore just power ta gun dilei hobe
    ll two=0, five=0;
    while(p%2==0) p/=2, two++;
    two*=q;

    while(p%5==0) p/=5, five++;
    five*=q;

//    factorial er jnno
//    n!, r!, (n-r)!
    ll factFiveR=countInFact(r,5), factFiveN=countInFact(n,5), factFiveN_R=countInFact(n-r,5);
    ll factTwoR=countInFact(r,2), factTwoN=countInFact(n,2), factTwoN_R=countInFact(n-r,2);

    factFiveN -= factFiveN_R;
    factFiveN -= factFiveR;

    factTwoN -= factTwoN_R;
    factTwoN -= factTwoR;

    ll totalTwo = two + factTwoN;
    ll totalFive = five + factFiveN;

    cout<<min(totalTwo, totalFive)<<endl;
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

