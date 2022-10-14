#include <bits/stdc++.h>
#define maxn 114514
#define mod 80112002
using namespace std;
int indeg[maxn], res[maxn];
vector<int> v[maxn];
int n, m;
bool vis[maxn];
void dfs(int x)
{
    //vis[x] = true;
    if (res[x]>0) return;
    if(v[x].size()==0) res[x]=1;
    for (int i = 0; i < v[x].size(); i++)
    {
        int y = v[x][i];
        //if (vis[y] == true)
        //continue;
        dfs(y);
        res[x]+=res[y];
        res[x]%=mod;
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        indeg[b]++;
    }
    memset(res, 0, sizeof(res));
    for (int i = 1; i <= n; i++)
    {
        if (indeg[i] == 0)
        {
            dfs(i);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (indeg[i] == 0)
        {
            ans += res[i];
            ans%=mod;
        }
    }
    cout<<ans<<endl;
    return 0;
}