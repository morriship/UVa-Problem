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

char in[100];
int ans[30], t;
vector<pair<int, int> > num;
vector<int> trace;

int cmp(const pair<int, int> &a, const pair<int, int> &b) { return a > b; }

void go2(int now, int sum) {
    for (int i = now; i < num.size(); i++) {
        int tmp(sum + num[i].first);
        int dist(tmp - t), j;

        rep(j, trace.size()) {
            pair<int, int> &p = num[trace[j]];
            if (p.first <= dist) { break; }
            ans[p.second]++;
        }
        if (!j) { continue; }
        go2(i+1, tmp);
    }
}

int go(int now, int sum, int re) {
    if (sum + re < t) { return 0; }
    else if (sum >= t) {
        go2(now, sum);
        return 1; 
    }

    int rex(re), ret(0);
    for (int i = now; rex; i++) {
        trace.push_back(i);
        rex -= num[i].first;
        int tmp(go(i+1, sum+num[i].first, rex));
        ans[num[i].second] += tmp;
        ret += tmp;
        trace.pop_back();
    }
    return ret;
}


int main() {
    int i, j, tmp;

    while (cin.getline(in, 100)) {
        memset(ans, 0, sizeof(ans));
        num.clear();
        for (i = 0; in[i] == ' '; i++);
        for (t = tmp = 0; in[i] != ' '; i++) { t = t * 10 + in[i] - 48; }
        for (i++; in[i-1]; i++) {
            if (in[i] == ' ' || in[i] == '\0') {
                if (tmp) {
                    num.push_back({tmp, num.size()});
                    tmp = 0;
                }
            }
            else { tmp = tmp * 10 + in[i] - 48; }
        }
        int re(0);
        sort(num.begin(), num.end(), cmp);
        rep(i, num.size()) { re += num[i].first; }
        go(0, 0, re);
        cout << ans[0];
        xrep(i, 1, num.size()) { cout << ' ' << ans[i]; }
        cout << endl;
    }
}
