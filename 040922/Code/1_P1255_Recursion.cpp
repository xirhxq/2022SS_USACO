#include<cstdio>
#include<cstring>
#define maxn 300
using namespace std;

int res[5050][maxn + 10];
bool vis[5050];

void cal(int x){
    if (vis[x]) return;
    if (x == 1 || x == 2) {
        vis[x] = true;
        res[x][0] = x;
        return;
    }
    cal(x - 1);
    cal(x - 2);
    vis[x] = true;
    for (int i = 0; i < maxn; i++){
        res[x][i] += (res[x - 1][i] + res[x - 2][i]);
        res[x][i + 1] += (res[x][i]) / 10000;
        res[x][i] %= 10000;
    }
}

int main(){
	int n;
	scanf("%d", &n);
    memset(vis, false, sizeof(vis));
    memset(res, 0, sizeof(res));
    cal(n);
    bool flag = false;
    for (int i = maxn - 1; i >= 0; i--){
        if (flag) {
            printf("%04d", res[n][i]);
        }
        else if (res[n][i] > 0) {
            printf("%d", res[n][i]);
            flag = true;
        }
    }
    if (!flag) printf("0");
	return 0;
}

