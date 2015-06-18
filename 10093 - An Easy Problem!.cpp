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

int ch[300];
char in[100000], ind;

void init() {
    int i, j;
    rep(i, 10) { ch[i+48] = i; }
    for (j = 'A'; j <= 'Z'; j++, i++) { ch[j] = i; }
    for (j = 'a'; j <= 'z'; j++, i++) { ch[j] = i; }
}

int check(int base) {
    int sum(0), div(base-1);
    for (int i = ind; in[i]; i++) { sum = (sum * base + ch[in[i]]) % div; }
    return sum == 0;
}

int main() {
    int i, j, k, st;
    init();

    while (cin >> in) {
        if (in[0] == '+' || in[0] == '-') { ind = 1; }
        else { ind = 0; }
        st = 1;
        for (i = ind; in[i]; i++) { st = max(st, ch[in[i]]); }
        for (i = st+1; i <= 62; i++) { if (check(i)) { break; } }
        if (i <= 62) { cout << i << endl; }
        else { cout << "such number is impossible!" << endl; }
    }
}
