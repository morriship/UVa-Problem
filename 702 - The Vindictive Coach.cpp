#include<bits/stdc++.h>
#define two(a) (1<<(a))
#define LINF (1ll<<61)
#define EPS (1e-14)
#define Lshift(a,b) (a<<b)
#define Rshift(a,b) (a>>b)
#define rep(a,b) for(a=0 ; a<b ; a++)
#define xrep(a,b,c) for(a=b ; a<c ; a++)
#define INF (1<<29)
#define swap(a,b) ( (a^=b) , (b^=a) , (a^=b) )
#define min(a,b) ( a < b ? a : b )
#define max(a,b) ( a > b ? a : b )
#define GET(x) (mark[x>>5]>>(x&31)&1)
#define SET(x) (mark[x>>5]|=1<<(x&31))
#define maxL (10000000>>5)+1
#define mod 1000000007
typedef long long ll;
using namespace std;

ll dp[30][30][2];

int main() {
    int n, m, i, j, k;
    while (cin >> n >> m) {
        memset(dp, 0, sizeof(dp));
        if (m == 1 && n <= 2) { dp[n-1][0][1] = 1; }
        else if (m ==1) { dp[n-1][1][0] = 1; }
        else {
            rep(i, m-1) { dp[n-1][i][1] = 1; }
        }
        for (i = n-2; i > 0; i--) {
            for (j = 0; j < i; j++) {
                ll &tmp = dp[i][j][0];
                for (k = 0; k <= j; k++) { tmp += dp[i+1][k][1]; }
                ll &tmp2 = dp[i][j][1];
                for (k = j+1; k <= i; k++) { tmp2 += dp[i+1][k][0]; }
            }
        }
        cout << dp[0][0][0] + dp[0][0][1] + dp[1][0][0] + dp[1][0][1] << endl;
    }
}
