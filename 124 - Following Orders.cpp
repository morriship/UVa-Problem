// http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=60
// 124 - Following Orders

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

vector<int> edge[200];
int use[200],can[200],n;
char ans[30];

void go(int dep){
	if(dep==n){
		cout << ans << endl;
		return;
	}
	for(int i='a' ; i<='z' ; i++){
		if(can[i] && !use[i]){
			for(int j=0 ; j<edge[i].size() ; j++) use[edge[i][j]]--;
			can[i]=0;
			ans[dep]=i;
			go(dep+1);
			can[i]=1;
			for(int j=0 ; j<edge[i].size() ; j++) use[edge[i][j]]++;
		}
	}
}

int main(){
	int i,j,k,t(0);
	char in[2000],c,cc;
	while(cin.getline(in,2000)){
		if(t) cout << endl;
		else t=1;
		memset(use,0,sizeof(use));
		memset(can,0,sizeof(can));
		istringstream ss(in);
		n=0;
		while(ss >> c) can[c]=true,edge[c].clear(),n++;
		cin.getline(in,2000);
		istringstream s2(in);
		while(s2 >> c >> cc){
			edge[c].push_back(cc);
			use[cc]++;
		}
		
		memset(ans,0,sizeof(ans));
		go(0);
	}
}
