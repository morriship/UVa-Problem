#include<iostream>
#include<sstream>
#include<vector>
#include<map>
#include<string>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<queue>
#include<stack>
#define INF (1<<29)
#define EPS (1e-10)
#define two(a) (1<<(a))
#define lshift(a,b) (a<<b)
#define rshift(a,b) (a>>b)
#define rep(a,b) for(a=0 ; a<b ; ++a)
#define xrep(a,b,c) for(a=b ; a<c ; ++a)
#define sca(t) scanf("%d",&t)
#define scal(t) scanf("%lld",&t)
typedef long long ll;
using namespace std;

int book[30][4];

int main() {
    int i,j,n,page,now;
    for (cin >> n; n; cin >> n) {
        page = n / 4 + (n % 4 ? 1 : 0);
        memset(book, 0, sizeof(book));
        
        now = 1;
        for (i = 0; i < page; i++) {
            if (now <= n) { book[i][1] = now++; }
            if (now <= n) { book[i][2] = now++; }
        }
        for (i = page - 1; i >= 0; i--) {
            if (now <= n) { book[i][3] = now++; }
            if (now <= n) { book[i][0] = now++; }
        }
        cout << "Printing order for " << n << " pages:" << endl;
        for (i = 0; i < page; i++) {
            if (book[i][0] || book[i][1]) {
                cout << "Sheet " << i + 1 << ", front: ";
                if (book[i][0]) { cout << book[i][0]; }
                else { cout << "Blank"; }
                cout << ", ";
                if (book[i][1]) { cout << book[i][1] << endl; }
                else { cout << "Blank" << endl; }
            }
            if (book[i][2] || book[i][3]) {
                cout << "Sheet " << i + 1 << ", back : ";
                if (book[i][2]) { cout << book[i][2]; }
                else { cout << "Blank"; }
                cout << ", ";
                if (book[i][3]) { cout << book[i][3] << endl; }
                else { cout << "Blank" << endl; }
            }
        }
    }
}
