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


int main() {
    double n, m;
    int a, b, t, tt;

    for (scanf("%d", &tt), t = 1; t <= tt; t++) {
        scanf("%lf%lf%d%d", &n, &m, &a, &b);
        double ans = (m - n) * (a + b) / b + n;
        if (ans < 0 || ans > 10) { printf("Case #%d: Impossible\n", t); }
        else { printf("Case #%d: %.2lf\n", t, ans + EPS); }
    }
}
