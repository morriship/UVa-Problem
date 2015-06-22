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

pair<int, int> in[30];
int ilen;

int main() {
    int n, i, ans;
    pair<int, int> tmp;

    for (scanf("%d", &n); n; n--) {
        ilen = ans = 0;
        while (scanf("%d%d", &tmp.first, &tmp.second) && (tmp.first || tmp.second)) { in[ilen++] = tmp; }
        sort(in, in+ilen);
        int ed = INF;
        rep(i, ilen) {
            if (ed <= in[i].first) {
                ans++;
                ed = in[i].second;
            }
            else { ed = min(ed, in[i].second); }
        }
        cout << ans+1 << endl;
    }
}
