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


pair<int, int> in[20001];
multiset<int> xset;

int main() {
    int t, tt, i, j, k, n, x, y, st, pre, ans;
    cin >> tt;
    xrep(t, 1, tt+1) {
        xset.clear();
        scanf("%d", &n);
        ans = n;
        rep(i, n) {
            scanf("%d%d", &x, &y);
            in[i] = {x, y};
        }
        sort(in, in+n);
        st = pre = 0;
        rep(i, n) {
            if (pre != in[i].first) {
                for (; st < i; st++) {
                    if (in[st].second > in[i].first) { xset.insert(in[st].second); }
                }
                pre = in[i].first;
            }
            auto it = xset.begin();
            while (it != xset.end() && *it <= in[i].first) {
                auto bak = it++;
                xset.erase(bak);
            }
            it = xset.lower_bound(in[i].second+1);
            if (it != xset.end()) {
                ans--;
                xset.erase(it);
            }
        }
        cout << "Case " << t << ": " << ans  << endl;
    }
}
