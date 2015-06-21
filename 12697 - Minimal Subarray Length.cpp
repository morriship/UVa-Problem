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

int x;
ll now;
pair<int, int> que[500010];
int st, ed;

int main() {
    int t, n, tmp, ans, i, j;
    for (scanf("%d", &t); t ; t--) {
        scanf("%d%d", &n, &x);
        now = st = ed = 0;
        ans = INF;
        rep(i, n) {
            scanf("%d", &tmp);
            if (tmp >= x) { ans = 1; }
            if (tmp > 0) {
                now += tmp;
                que[ed++] = {tmp, i};
                while (now - que[st].first >= x) { now -= que[st++].first; }
                if (now >= x) { ans = min(ans, i - que[st].second + 1); }
            }
            else if (tmp < 0) {
                now += tmp;
                if (now <= 0) { ed = st = now = 0; }
                else {
                    while (-tmp >= que[ed-1].first) { tmp += que[--ed].first; }
                    que[ed-1].first += tmp;
                }
            }
        }
        if (ans == INF) { cout << -1 << endl; }
        else { cout << ans << endl; }
    }
}
