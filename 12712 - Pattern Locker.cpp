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
#define mod 10000000000007ll
typedef long long ll;
using namespace std;

ll ans, tmp;

int main() {
    int t, tt, i, l, m, n;

    for (scanf("%d", &t), tt=1; tt <= t; tt++) {
        scanf("%d%d%d", &l, &m, &n);
        l *= l;
        ans = 0;
        tmp = 1;
        for (i = l; i > l-n; i--) {
            tmp = tmp * i % mod;
            if (i <= l-m+1) { ans = (ans + tmp) % mod; }
        }
        cout << "Case " << tt << ": " << ans << endl;
    }
}
