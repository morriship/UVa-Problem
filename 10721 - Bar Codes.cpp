#include<bits/stdc++.h>
#define two(a) (1<<(a))
#define LINF (1ll<<61)
#define EPS (1e-14)
#define Lshift(a,b) (a<<b)
#define Rshift(a,b) (a>>b)
#define rep(a,b) for(a=0 ; a<b ; a++)
#define xrep(a,b,c) for(a=b ; a<c ; a++)
#define INF (1<<29)
#define GET(x) (mark[x>>5]>>(x&31)&1)
#define SET(x) (mark[x>>5]|=1<<(x&31))
#define maxL (10000000>>5)+1
#define mod 1000000007
typedef long long ll;
using namespace std;

ll dp[51][51];

int main() {
    int n, k, m, i, j, l;
    
    while (~scanf("%d%d%d", &n, &k, &m)) {
        memset(dp, 0, sizeof(dp));
        dp[1][1] = 1;
        xrep(i, 2, n+1) {
            xrep(j, 2, k+1) {
                for (l = i-1; l > max(0, i-m-1); l--) { dp[i][j] += dp[l][j-1]; }
            }
        }
        ll ans(0);
        for (i = n; i > max(0, n-m); i--) { ans += dp[i][k]; }
        cout << ans << endl;
    }
}
