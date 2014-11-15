#include<bits/stdc++.h>
using namespace std;
#define INF (1<<29)
#define EPS (1e-7)
#define two(a) (1<<(a))
#define rep(a,b) for(a=0 ; a<b ; ++a)
#define xrep(a,b,c) for(a=b ; a<c ; ++a)
#define sca(t) scanf("%d",&t)
#define scal(t) scanf("%lld",&t)

char in[5011];

int main() {
    long long a, b;
    while (cin >> a >> b) {
        cin.getline(in, 10);
        cin.getline(in, 5011);

        long long index(0), cost(0);
        int i;
        for (i = 0; in[i]; i++) {
            if (in[i] == 'B') {
                cost += (i - index);
                index++;
            }
        }
        cost *= a - b;
        int j(i);

        for (i = 0; j > i; i++) {
            if (in[i] == 'W') {
                for (j--; in[j] == 'W' && j > i; j--);
                long long temp = (j - i) * (a - b) - a;
                if (temp < 0) { break; }
                cost -= temp;
            }
        }
        cout << cost << endl;
    }
}
