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

ll in[1001];

int main() {
    int n, i, k, j, t, tt, now;
    for (cin >> t, tt = 1; tt <= t; tt++) {
        pair<int, int> ans(0, 0);
        scanf("%d%d%d", &n, &i, &k);
        rep(j, n) { scanf("%lld", in+j); }
        now = 0;
        rep(j, n) {
            if (in[j] < now) { ans.second++; }
            else if (in[j] < now + i) { now = in[j]; }
            else {
                ans.first++;
                now = in[j] + k;
            }
        }
        cout << "Case " << tt << ": " << ans.first << ' ' << ans.second << endl;
    }
}
