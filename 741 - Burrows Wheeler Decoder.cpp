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

string in;
int _next[310];
pair<char, int> _rank[310];

int main() {
    int i, j, st, now, first(1);

    while (cin >> in >> st && st) {
        if (first) { first = 0; }
        else { puts(""); }
        rep(i, in.length()) { _rank[i] = {in[i], i}; }
        sort(_rank, _rank+in.length());
        rep(i, in.length()) { _next[i] = _rank[i].second; }
        now = --st;
        while (true) {
            printf("%c", _rank[now].first);
            now = _next[now];
            if (now == st) { break; }
        }
        puts("");
    }
}
