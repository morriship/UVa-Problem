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

double lim[] = {56.0, 45.0, 25.0};
double in[4];

int main() {
    int i, t, sum(0);

    for (scanf("%d", &t); t; t--) {
        rep(i, 4) { scanf("%lf", &in[i]); }
        rep(i, 3) { if (in[i] > lim[i]) { break; } }
        if ((i == 3 || in[0] + in[1] + in[2] <= 125.0) && in[3] <= 7.0 && ++sum) { printf("1\n"); }
        else {printf("0\n"); }
    }
    printf("%d\n", sum);
}
