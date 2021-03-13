#include<iostream>
#include<cstring>
using namespace std;
 
int n,m;
int map[101][101];
 
void prim()  //��С������ prim�㷨
{
    cout<<"prim:"<<endl;
    int lowcost[101];  //lowcost[i]�����е㵽i��ıߵ�Ȩֵ��Сֵ 
    int closest[101];  //closest[i]������е㵽i��ıߵ�Ȩֵ��С�ĵ� 
    bool s[101];
    s[1] = true;  //ѡ��1Ϊ����
    int i,j,k;
    for(i=2;i<=n;i++)  //��ʼ��
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
        for(j=2;j<=n;j++)  //����С��
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
            if((map[k][j]<lowcost[j])&&(!s[j]))  //�µĽ��С�����½���滻��ԭ���
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
