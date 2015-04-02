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
#define mod 1000000007
typedef long long ll;
using namespace std;


int primes[1000000], plen;
void init() {
    int i, ii(2), j;
    primes[0] = 2, primes[1] = 3;
    plen = 2;
    for (i = 5; i < 10000000; i += ii, ii ^= 6) {
        for (j = 0; primes[j] * primes[j] <= i; j++) { if (i % primes[j] == 0) break; }
        if (i % primes[j]) { primes[plen++] = i; }
    }
}

int bs(int target) {
    int st(0), ed(plen-1), mi;
    while (st < ed) {
        mi = Rshift(st+ed, 1);
        if (primes[mi] >= target) { ed = mi; }
        else { st = mi+1; }
    }
    return st - 1;
}

int main() {
    int n, i, j;
    init();
    while (cin >> n) {
        if (n < 8 && puts("Impossible.")) { continue; }
        if ((n & 1) && (n -= 5)) { cout << 2 << ' ' << 3; }
        else if (n -= 4) { cout << 2 << ' ' << 2; }
        for (i = 0, j = bs(n); i < j; j--) {
            while (primes[i] + primes[j] < n) { i++; }
            if (primes[i] + primes[j] == n) { break; }
        }
        if (i <= j) { cout << ' ' << primes[i] << ' ' << primes[j] << endl; }
    }
}
