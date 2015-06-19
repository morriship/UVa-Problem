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

int cyc[10], nlen;
char m[111], n[111];

void init() {
    int i, j, k;
    rep(i, 10) {
        for (j = i*i%10, k = 1; j != i; j = j*i%10, k++);
        cyc[i] = k;
    }
}

int main() {
    int base, i;
    init();

    while (~scanf("%s%s", m, n)) {
        if (!m[1] && m[0] == '0' && !n[1] && n[0] == '0') { break; }
        if (!n[1] && n[0] == '0') {
            cout << 1 << endl;
            continue;
        }
        for (i = 0; m[i]; i++);
        for (nlen = 0; n[nlen]; nlen++);
        base = m[i-1] - 48;
        if (cyc[base] == 1) { cout << base << endl; }
        else if (cyc[base] == 2) {
            if (n[nlen-1]%2 == 0) { cout << base*base%10 << endl; }
            else { cout << base << endl; }
        }
        else {
            int count(0), ans(1);
            rep(i, nlen) { count = (count * 10 + n[i] - 48) % cyc[base]; }
            if (!count) { count = cyc[base]; }
            rep(i, count) { ans = ans * base % 10; }
            cout << ans << endl;
        }
        
    }
}
