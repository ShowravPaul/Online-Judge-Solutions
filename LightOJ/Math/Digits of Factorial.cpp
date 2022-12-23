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
#define mem(arr, b) memset(arr, b, sizeof(arr)) //memset only for -1 and 0
//fill(a, a+n, 5) //fill for any value
 
#define for0(i,b) for(int i=0;i<(b);i++)
#define for1(i,b) for(int i=1;i<=(b);i++)
#define forab(i,a,b) for(int i=(a);i<=(b);i++)
#define forba(i,b,a) for(int i=(b);i>=(a);i--)
#define rep(i,a,b,c) for(int i=(a);i!=(b);i+=(c))
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fileRead freopen("input.txt", "r", stdin);
 
void print(int a[], int n){ // for testing or debugging
    for(int i=0;i<n;i++)cout<<a[i]<<" "; cout<<endl;
}
 
//-----------------------------------------------------------------------
 
double a[1000000+5];
 
void solve()
{
    // main idea: log10n / log10b + 1
    //https://shahidul-brur.blogspot.com/2017/05/lightoj-1045-digits-of-factorial.html
 
    int n; cin>>n;
    int b; cin>>b;
    if(a[n]==0) cout<< 1 <<endl;
    else{
        int ans = a[n] / log10((double)b) + 1;
        cout<< ans <<endl;
    }
   
}
 
//-----------------------------------------------------------------------
 
int main()
{
    //IOS;
    //fileRead
    int tc = 1;
    cin>>tc;
    int t=1;
    for(int i=1;i<=1000000; i++){
        a[i] = log10((double)i) + a[i-1];
    }
    while(tc--)
    {
        cout<<"Case "<<t<<": "; t++;
        solve();
    }
}
