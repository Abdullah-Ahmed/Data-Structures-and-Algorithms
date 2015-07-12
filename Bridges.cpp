#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#define space " "
#define ast "***"
#define dbg(n) cout<<"Debug "<<n<<endl
#define loop(i,s,e) for(int i = s ;i < e ; i++)
#define lop(i,e) for(int i = 0 ;i < e ; i++)
#define readfilefo(filename) freopen(filename,"r",stdin)
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(a)  a.begin() , a.end()
#define error(x) cerr << #x << " = " << (x) <<endl
#define Error(a,b) cerr<<"( "<<#a<<" , "<<#b<<" ) = ( "<<(a)<<" , "<<(b)<<" )\n";
#define errop(a) cerr<<#a<<" = ( "<<((a).x)<<" , "<<((a).y)<<" )\n";
#define coud(a,b) cout<<fixed << setprecision((b)) << (a)
#define L(x)  ((x)<<1)
#define R(x)  (((x)<<1)+1)
#define f first
using namespace std;
typedef pair<int,int> ii ;
ii links[10000];
int timer = 0;
vector<int> a[10000];
int index = 0;
int dfslow[10000] = {0},dfsnum[10000],dfsparent[10000];

void bridges(int u){
	dfslow[u] = dfsnum[u] = timer++;
	for(int i = 0 ;i < a[u].size() ; i++){
		if(dfsnum[a[u][i]] == -1){
			dfsparent[a[u][i]] = u;
			bridges(a[u][i]);
			if(dfslow[a[u][i]] > dfsnum[u])
				links[index] = {u,a[u][i]},index++;
			dfslow[u] = min(dfslow[u],dfslow[a[u][i]]);
		}else if(a[u][i] != dfsparent[u])
		dfslow[u] = min(dfslow[u],dfsnum[a[u][i]]);
	}
}

int main(int argc, char const *argv[]){
int n;
while(cin >> n){
timer = index = 0;
lop(i,n) dfsnum[i] = -1,dfslow[i] = 0,dfsparent[i] = 0,a[i].clear();
lop(i,n){
	cin >> x;
	char c;
	cin >>c>>y>>c;
	lop(j,y) cin >>z,a[x].push_back(z);
}
lop(i,n)
if(dfsnum[i] == -1)
       bridges(i);
     cout<<index <<"Bridges"<<endl;
   lop(i,index)
        cout<<links[i].f<<" - "<<links[i].s<<endl;
    } 
	return 0;
}

