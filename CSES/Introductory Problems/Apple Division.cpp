#include<bits/stdc++.h>
using namespace std;
 
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx,avx2,fma")
 
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef vector<pii> vpii;
typedef vector<pil> vpil;
typedef vector<pli> vpli;
typedef set<int> si;
typedef set<ll> sll;
 
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
 
 
//______________________________________________________\\
 
ll findMinDiff(int a[], int i, ll currentSum, ll totalSum){
	if(i==0) return abs( (totalSum - currentSum) - currentSum );
	
	return min( findMinDiff(a, i-1, currentSum+a[i-1], totalSum), findMinDiff(a, i-1, currentSum, totalSum) );
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    int tc = 1;
    //cin>>tc;
    while(tc--)
    {
    	int n; cin>>n; 
    	int a[n];
    	ll totalSum=0;
    	for0(i,n) cin>>a[i], totalSum+=a[i];
    	
    	ll currentSum=0;
    	ll ans = findMinDiff(a, n, currentSum, totalSum);
    	
    	cout<<ans;
    	
    }
}
