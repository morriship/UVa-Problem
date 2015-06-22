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

unordered_map<int, double> xmap;
double d, s, a;

double solv(int now) {
    double ret(0);
    while (!(now&1)) {
        now >>= 1;
        ret += d;
    }
    auto it = xmap.find(now);
    if (it == xmap.end()) {
        double tmp((solv(now+1)+a+solv(now-1)+s)/2+EPS);
        xmap[now] = tmp;
        return tmp + ret;
    }
    return it->second + ret;
}


int main() {
    int t, n, i;

    for (scanf("%d", &t); t; t--) {
        scanf("%d%lf%lf%lf", &n, &d, &s, &a);
        xmap.clear();
        xmap[1] = d+s+a;
        printf("%.3lf\n", solv(n));
    }
}
