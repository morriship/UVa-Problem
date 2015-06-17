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
typedef unsigned long long ull;
using namespace std;

char in[70];
char ch[300];
int ans[70];
int need[70];

void init() {
    ch['p'] = 'n';
    ch['n'] = 'p';
}

void rev(int k) {
    for (int i = 0; i < k-i-1; i++) { swap(in[i], in[k-i-1]); }
}

int main() {
    int t, k, i, j;
    ull tar, now;
    init();

    for (cin >> t; t; t--) {
        ll _tar;
        cin >> k >> in >> _tar;
        if (_tar >= 0) { tar = _tar; }
        else { 
            tar = -(_tar+1);
            tar++;
            rep(i, k) in[i] = ch[in[i]];
        }

        rev(k);
        memset(ans, 0, sizeof(ans));
        memset(need, 0, sizeof(need));
        now = Lshift(2ull, k-1);
        for (i = 0; tar; i++) {
            if (tar & 1) { need[i] = 1; }
            tar >>= 1;
        }
        for (i = 0; i < k; i++) {
            if (need[i] == 2) { need[i+1]++; }
            else if (need[i] == 1 && in[i] == 'n') {
                need[i+1]++;
                ans[i] = 1;
            }
            else if (need[i] == 1) { ans[i] = 1; }
        }
        for (i = k; i < 70; i++) { if (need[i]) break; }
        if (i < 70) { cout << "Impossible" << endl; }
        else {
            for (i = k-1; i >= 0; i--) { cout << ans[i]; }
            cout << endl;
        }
    }
}
