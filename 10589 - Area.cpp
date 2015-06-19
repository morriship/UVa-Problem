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

int check(double x, double y, double a) {
    if (x * x + y * y > a * a + EPS) { return 0; }
    if (x * x + (y-a) * (y-a) > a * a + EPS) { return 0; }
    if ((x-a) * (x-a) + y * y > a * a + EPS) { return 0; }
    if ((x-a) * (x-a) + (y-a) * (y-a) > a * a + EPS) { return 0; }
    return 1;
}

int main() {
    int n, i, m;
    double a, x, y;
    while (scanf("%d%lf", &n, &a) && n) {
        m = 0;
        rep(i, n) {
            scanf("%lf%lf", &x, &y);
            m += check(x, y, a);
        }
        printf("%.5lf\n", (a * a * m / n) + EPS);
    }
}
