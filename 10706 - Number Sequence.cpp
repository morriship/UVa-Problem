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

ll a[40000], b[40000], c[40000];
int x10[] = {10, 100, 1000, 10000, 100000}, len;

void init() {
    int i(1), ind(0), count(1);
    a[0] = b[0] = c[0] = 0;
    for (; c[i-1] < 2147483647L; i++) {
        if (i >= x10[ind]) {
            ++count;
            ++ind;
        }
        a[i] = count;
        b[i] = b[i-1] + a[i];
        c[i] = c[i-1] + b[i];
    }
    len = i;
}

int bs(int ind, ll x[]) {
    int ft(0), ed(len), mi;
    
    while (ft < ed) {
        mi = (ft+ed) >> 1;
        if (x[mi] >= ind) { ed = mi; }
        else { ft = mi + 1; }
    }
    return ft-1;
}

int solv(int now, int ind) {
    int c(log10(now)+1-ind);
    while(c--) { now /= 10; }
    return now % 10;
}

int main() {
    int i, j, t, ind;
    init();

    for (scanf("%d", &t); t; t--) {
        scanf("%d", &ind);
        ind -= c[bs(ind, c)];
        int tmp = bs(ind, b);

        printf("%d\n", solv(tmp+1, ind-b[tmp]));
    }
}
