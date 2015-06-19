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
#define mod 11
typedef long long ll;
using namespace std;

char in[100];

int main() {
    int now, count, i, j;

    while (cin.getline(in, 100)) {
        int st, ed, sum(0), sumx(0);
        for (st = 0; in[st] == ' '; st++);
        for (ed = st; in[ed]; ed++);
        for (; ed > st && (!in[ed] || in[ed] == ' '); ed--);

        for (i = st, now = 0, count = 0; i <= ed; i++) {
            if ((in[i] < '0' || in[i] > '9') && in[i] != ' ' && in[i] != '-' && in[i] != 'X') { break; }
            else {
                if (count < 9 && in[i] >= '0' && in[i] <= '9') {
                    count++;
                    sum += in[i] - 48;
                    sumx += sum;
                }
                else if (count == 9 && (in[i] >= '0' && in[i] <= '9' || in[i] == 'X')) {
                    int tmp(in[i] - 48);
                    if (in[i] == 'X') { tmp = 10; }
                    sumx += sum + tmp;
                    if (sumx % mod) { break; }
                    count++;
                }
                else if (in[i] == '-' || in[i] == ' ') {}
                else { break; }
            }
        }
        for (j = st; in[j] && j <= ed; j++) { cout << in[j]; }
        if (i <= ed || count != 10) { cout << " is incorrect." << endl; }
        else { cout << " is correct." << endl; }
    }
}
