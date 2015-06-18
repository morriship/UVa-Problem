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

char in[100000];

int a[10010], alen;

int main() {
    int k, i, flag(0);

    while (~scanf("%d", &k)) {
        cin.getline(in, 100);
        cin.getline(in, 100000);
        memset(a, 0, sizeof(a));
        int tmp(0), flag(1);
        for (i = alen = 0; in[i]; i++) {
            if (in[i] == ' ') {
                a[alen++] = tmp * flag;
                tmp = 0;
                flag = 1;
            }
            else if (in[i] == '-') { flag = -1; }
            else { tmp = tmp * 10 + in[i] - 48; }
        }
        if (i > 0 && in[i-1] != ' ') { a[alen++] = tmp * flag; }
        cout << "q(x):";
        rep(i, alen-1) {
            cout << ' ' << a[i];
            a[i+1] += a[i] * k;
        }
        cout << "\nr = " << a[alen-1] << '\n' << endl;
    }
}
