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
#define fileWrite freopen("output.txt", "w", stdout);

void print(int a[], int n){ // for testing or debugging
    for(int i=0;i<n;i++)cout<<a[i]<<" "; cout<<endl;
}

//--------------------------------------------------------------------------------

int a[500][500];
int dp[500][500];

int N;

int fun(int i, int j)
{
    if(dp[i][j]!=-1) return dp[i][j];
    
    if(i==0 and j==0) return a[0][0]; /// first value
    
    if(a[i][j] == 0) return 0;

    if(i>N-1){
            dp[i][j] = a[i][j] + max( fun(i-1, j) , fun(i-1, j+1) );
            return dp[i][j];
    }
    else {
        if(j==0){
            dp[i][j] = a[i][j] + fun(i-1, j);
            return dp[i][j];/// left corner value
        }
        else{
            dp[i][j] = a[i][j] + max( fun(i-1, j-1) , fun(i-1, j) );
            return dp[i][j];
        }
    }
}

int main()
{
    IOS;
    int tc; cin>>tc;
    int t=1;
    while(tc--)
    {
        cout<<"Case "<<t++<<": ";
        mem(dp, -1);
        mem(a,0);
        
        cin>>N;
        int n=N;
        
        int x=1, y=n-1;
        for0(i,2*n-1){
            if(i<n) {
                for0(j,x) cin>>a[i][j];
                x++;
            }
            else {
                for0(j,y) cin>>a[i][j];
                y--;
            }
        }
        
        cout<<fun(2*n-2,0)<<endl;
    }
}
