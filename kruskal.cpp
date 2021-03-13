#include<iostream>
#include<cstring>
using namespace std;
 
int pre[101];
int u[101],v[101],edge[101];  //u,v分别为两个点，edge为两个点之间的边
int m,n;
int find(int x)
{
    int root = x;
    while(pre[root]!=root)
        root = pre[root];
    //路径压缩
    int i,j;
    i = x;
    while(pre[i]!=root)
    {
        j = i;
        i = pre[i];
        pre[j] = root;
    }
    return root;
}
 
void kruskal()  //最小生成树，Kruskal算法
{
    cout<<"Kruskal:"<<endl;
    int i,total,min,minnum,fu,fv;
    total = n-1;
    while(total>0)
    {
        min = 10000000;
        for(i=1;i<=m;i++)  //找最小值
        {
            if(u[i] == -1||v[i] == -1)
                continue;
            if(edge[i]<min)
            {
                min = edge[i];
                minnum = i;
            }
        }
        fu = find(u[minnum]);
        fv = find(v[minnum]);
        if(fu!=fv)  //不连通,就连接两个点
        {
            cout<<u[minnum]<<","<<v[minnum]<<":"<<edge[minnum]<<endl;
            pre[fu] = fv;
            total--;
        }
        edge[minnum] = 100000000;  //改变已经找到的最小值
        u[minnum] = -1;
        v[minnum] = -1;
    }
}
 
int main()
{
    cin>>n>>m;
    int i,a,b,tem;
    for(i=1;i<=n;i++)
        pre[i] = i;
    for(i=1;i<=m;i++)
    {
        cin>>a>>b;
        cin>>tem;
        u[i] = a;
        v[i] = b;
        edge[i] = tem;
    }
    kruskal();
    return 0;
}
