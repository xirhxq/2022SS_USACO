#include<iostream>
#define maxn 20
using namespace std;

void dfs(int x){//输出表示x的表达式
//	cout<<"["<<x<<"]";
    if(x==0){
        cout<<"0";
        return;
    }

    if(x==1){
        cout<<"2(0)";
        return;
    }

    if(x==2){
        cout<<"2";
        return;
    }


    int cnt=0,digit[maxn];
    //...一些操作把x拆分成2^a+2^b+2^c...
    while(x){
        if(x%2) digit[cnt++]=1;
        else digit[cnt++]=0;
        x/=2;
    }
    //digit[0]--digit[cnt-1]就是最终的结果
    bool flag=false;
    for(int i=cnt-1;i>=0;i--){
        if(digit[i]==1){
            if(flag) cout<<"+";
            flag=true;
            //要拆分出来一个2^i
            //表达式里面有一项为 2(i的表达式)
            if(i==1) cout<<2;
            else {
                cout<<"2(";
                dfs(i);
                cout<<")";
            }
        }
    }
}

int main(){
    int n;
    cin>>n;
    dfs(n);
    return 0;
}