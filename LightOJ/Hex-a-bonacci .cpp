#include<bits/stdc++.h>
using namespace std;

int a, b, c, d, e, f,n;
int dp[10000+5];
long long fn( int n ) {
    if( n == 0 ) return a;
    if( n == 1 ) return b;
    if( n == 2 ) return c;
    if( n == 3 ) return d;
    if( n == 4 ) return e;
    if( n == 5 ) return f;
    if(dp[n]!=-1) return dp[n];
    dp[n] = (fn(n-1) + fn(n-2) + fn(n-3) + fn(n-4) + fn(n-5) + fn(n-6)) % 10000007;
    return dp[n];
}

int main(){
    //fileRead;
    int t; cin>>t;
    int caseNo=0;
    while(t--)
    {
        memset(dp, -1, sizeof(dp));
        scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &n);
        int tem = fn(n) % 10000007;
        printf("Case %d: %d\n", ++caseNo, tem);
    }
}


