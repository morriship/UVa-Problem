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

pair<int, int> in[100010], range[100010];
int now;

int check(int site, int ran) {
    int st(0), ed(now), mi, lim(site-ran);
    while (st < ed) {
        mi = (st+ed) >> 1;
        if (range[mi].first <= lim) { st = mi+1; }
        else { ed = mi; }
    }
    st--;
    if (range[st].second - site >= ran) { return 1; }
    return 0;
}

int bs(int site) {
    int st(0), ed(site<<1), mi;
    while (st < ed) {
        mi = (st+ed) >> 1;
        if (!check(site, mi)) { ed = mi; }
        else { st = mi+1; }
    }
    return max(0, st-1);
}

int main() {
    int t, tt, n, m, i, j, k;
    pair<int, int> tmp;

    scanf("%d", &tt);
    xrep(t, 1, tt+1) {
        scanf("%d%d", &n, &m);
        rep(i, n) {
            scanf("%d%d", &tmp.first, &tmp.second);
            in[i] = tmp;
        }
        sort(in, in+n);
        now = 0;
        range[now] = in[0];
        xrep(i, 1, n) {
            if (in[i].first == in[i-1].first) { range[now].second = max(range[now].second, in[i].second); }
            else {
                range[++now] = in[i];
                range[now].second = max(range[now].second, range[now-1].second);
            }
        }
        ++now;
        printf("Case %d:\n", t);
        rep(i, m) {
            int site;
            scanf("%d", &site);
            printf("%d\n", bs(site));
        }
    }
}
