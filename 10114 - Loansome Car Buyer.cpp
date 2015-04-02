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

pair<int, double> deper[110];

int main() {
    int month, n, ind, i;
    double paid, loan, car, dep, pay;
    for (cin >> month; month >= 0; cin >> month) {
        cin >> paid >> loan >> n;
        pay = loan / month;
        rep(i, n) { cin >> deper[i].first >> deper[i].second; }
        deper[n].first = INF;
        if (!deper[0].first) { car = (paid + loan) * (1 - deper[0].second); }
        dep = deper[0].second;
        ind = 1;
        rep(i, month+1) {
            if (car + EPS >= loan) { break; }
            while (i+1 >= deper[ind].first) { dep = deper[ind++].second; }
            loan -= pay;
            car *= 1 - dep;
        }
        cout << i << " month" << (i^1 ? "s": "") << endl;
    }
}
