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
#define maxL (1100>>5)+1
#define mod 1000000007
int mark[maxL];
typedef long long ll;
using namespace std;

int prime[180], plen;

ll dp[3][180];

void init() {
    register int i, j, k;
    SET(1);
    int n = 1000;
    for (i = 2; i <= n; i++) {
        if (!GET(i)) {
            prime[plen++] = i;
            for (k = n/i, j = i*k; k >= i; k--, j -= i) { SET(j); }
        }
    }
}

int main() {
    int t, n, a, b, i, j;
    init();

    for (cin >> t; t; t--) {
        cin >> n >> a >> b;
        memset(dp, 0, sizeof(dp));
        for (i = 0; i < plen && prime[i] <= a; i++) {
            while (a % prime[i] == 0) {
                dp[0][i]++;
                a /= prime[i];
            }
        }
        for (i = 0; i < plen && prime[i] <= b; i++) {
            while (b % prime[i] == 0) {
                dp[1][i]++;
                b /= prime[i];
            }
        }
        for (i = 2; i <= n; i++) {
            rep(j, plen) { dp[i%3][j] = dp[(i-1)%3][j] + dp[(i-2)%3][j]; }
        }
        rep(i, plen) {
            if (dp[n%3][i]) { cout << prime[i] << ' ' << dp[n%3][i] << endl; }
        }
        cout << endl;
    }
}
