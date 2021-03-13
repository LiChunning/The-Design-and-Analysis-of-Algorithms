#include<iostream>
#include<cstring>
using namespace std;
 
int n,m;
int map[101][101];
 
void prim()  //最小生成树 prim算法
{
    cout<<"prim:"<<endl;
    int lowcost[101];  //lowcost[i]存树中点到i点的边的权值最小值 
    int closest[101];  //closest[i]存放树中点到i点的边的权值最小的点 
    bool s[101];
    s[1] = true;  //选择1为树顶
    int i,j,k;
    for(i=2;i<=n;i++)  //初始化
    {
        lowcost[i] = map[1][i];
        s[i] = false;
        closest[i] = 1;
    }
    int min;
    for(i=1;i<n;i++)
    {
        min = 100000;
        k = 1;
        for(j=2;j<=n;j++)  //找最小边
        {
            if((lowcost[j]<min)&&(!s[j]))
            {
                min = lowcost[j];
                k = j;
            }
        }
        cout<<closest[k]<<","<<k<<":"<<min<<endl;
        s[k] = true;
        for(j=2;j<=n;j++)
        {
            if((map[k][j]<lowcost[j])&&(!s[j]))  //新的结点小，用新结点替换掉原结点
            {
                lowcost[j] = map[k][j];
                closest[j] = k;
            }
        }
    }
}
 
int main()
{
    cin>>n>>m;
    int i,a,b,tem;
    memset(map,0x3f,sizeof(map));  
    for(i=1;i<=m;i++)
    {
        cin>>a>>b;
        cin>>tem;
        map[a][b] = tem;
        map[b][a] = tem;
    }
    prim();
    return 0;
}
