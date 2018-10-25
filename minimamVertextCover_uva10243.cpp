/*
Md Hafizul islam
minimum vertxt cover and dp program
*/
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
#define Max 1002
int dp[Max][Max];
int par[Max]={0};
vector <vi> g;
int dfs(int u,int isgrad)
{
    if(g[u].size()==0) return 1;
    if(dp[u][isgrad]!=-1) return dp[u][isgrad];
    int sum=0;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(v!=par[u]){
            par[v]=u;
            if(!isgrad)
                sum += dfs(v,1);
            else sum += min(dfs(v,0),dfs(v,1));
        }
    }
    return dp[u][isgrad] = sum+isgrad;
}
int main()
{
    int v,n,m,i;

    while(scanf("%d",&n)&&n){
        g.assign(n+2,vi());
        memset(dp,-1,sizeof dp);
        for(i=1;i<=n;i++){
            scanf("%d",&m);
            while(m--){
                scanf("%d",&v);
                g[i].push_back(v);
            }
        }
        cout<<min(dfs(1,1),dfs(1,0))<<endl;
    }

    return 0;
}
