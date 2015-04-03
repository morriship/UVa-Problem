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
int mark[maxL];
int primes[100000], plen(0);
typedef long long ll;
using namespace std;

void init() {
    int i, j, k, n(1000000);
    SET(1);
    for (i = 2; i <= n; i++) {
        if (!GET(i)) { primes[plen++] = i; }
        for (k = n/i, j = i*k; k >= i; k--, j -= i) { SET(j); }
    }
}

int isPrimes(int now) {
    int i, nn(sqrt(now)+EPS);
    if (now <= 1000000) { return !GET(now); }
    for (i = 0; i < plen && primes[i] <= nn; i++) {
        if (now % primes[i] == 0) { return 0; }
    }
    return 1;
}

int main() {
    int u, l, pre, maxn, minx;
    ll i;
    pair<int, int> a, b;
    init();
    while (cin >> l >> u) {
        pre = -1;
        maxn = -1;
        minx = u;
        for (i = l; i <= u; i++) {
            if (isPrimes(i)) {
                if (~pre) {
                    if (i - pre > maxn) {
                        maxn = i - pre;
                        a.first = pre;
                        a.second = i;
                    }
                    if (i - pre < minx) {
                        minx = i - pre;
                        b.first = pre;
                        b.second = i;
                    }
                }
                pre = i;
            }
        }
        if (!~maxn) { puts("There are no adjacent primes."); }
        else { printf("%d,%d are closest, %d,%d are most distant.\n", b.first, b.second, a.first, a.second); }
    }
}
