// http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=61
// 125 - Numbering Paths


#include<iostream>
#include<sstream>
#include<vector>
#include<map>
#include<string>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<queue>
#include<stack>
#define INF (1<<29)
#define EPS (1e-7)
#define two(a) (1<<(a))
#define rep(a,b) for(a=0 ; a<b ; ++a)
#define xrep(a,b,c) for(a=b ; a<c ; ++a)
#define sca(t) scanf("%d",&t)
#define scal(t) scanf("%lld",&t)
typedef long long ll;
using namespace std;


int dist[40][40],xd[40][40];

int main(){
	int n,m,i,j,k,l,x,y,t(0);
	while(cin >> m){
		memset(dist,0,sizeof(dist));
		memset(xd,0,sizeof(xd));
		n=-INF;
		rep(i,m){
			scanf("%d%d",&x,&y);
			dist[x][y]=xd[x][y]=1;
			n=max(n,max(x,y));
		}
		n++;
		rep(l,2) rep(k,n) rep(i,n) rep(j,n) if(dist[i][k] && dist[k][j]){
			if(dist[i][k]+dist[k][j]>n) dist[i][j]=n;
			else dist[i][j]=max(dist[i][j],dist[i][k]+dist[k][j]);
		}
		rep(i,n) rep(j,n) if(dist[i][j]==n) dist[i][j]=-1;
		rep(k,n) rep(i,n) rep(j,n) if(xd[i][k] && xd[k][j] && ~dist[i][j]){
			xd[i][j]+=xd[i][k]*xd[k][j];
		} 
		printf("matrix for city %d\n",t++);
		rep(i,n){
			if(~dist[i][0]) cout << xd[i][0];
			else cout << -1;
			xrep(j,1,n){
				if(~dist[i][j]) cout << ' ' << xd[i][j];
				else cout << ' ' << -1;
			}
			cout << endl;
		}
	}
}
