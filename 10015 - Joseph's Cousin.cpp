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
#define maxL (40000>>5)+1
#define mod 1000000007
typedef long long ll;
using namespace std;

int mark[maxL];
int pri[4000], plen(0);
vector<int> no;

void init() {
    int i, j, k, n(40000);
    SET(1);
    for (i = 2; i <= n && plen < 3550; i++) {
        if (!GET(i)) { pri[plen++] = i; }
        for (k = n/i, j = i*k; k >= i; k--, j -= i) { SET(j); }
    }
}

int main() {
    int i, n, now;

    init();
    while (scanf("%d", &n) && n) {
        no.clear();
        rep(i, n) { no.push_back(i+1); }
        now = 0;
        rep(i, n-1) {
            now = (now + pri[i] - 1) % no.size();
            no.erase(no.begin() + now);
        }
        cout << no[0] << endl;
    }
}
