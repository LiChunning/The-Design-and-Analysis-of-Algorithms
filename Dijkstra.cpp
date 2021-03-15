#include <stdio.h>
int main()
{
	int e[10][10],dis[10],book[10],i,j,n,m,a,b,c,u,v,min;
	int inf = 99999999;
	//���붥����n������m
	scanf("%d %d",&n,&m);
	//��ʼ��
	for(i = 1; i <= n; i++){
		for(j = 1; j <= n; j++){
			if(i == j) e[i][j] = 0;
			else e[i][j] = inf;
		}
	}
	//�����
	for(i = 1; i <= m; i++){
		scanf("%d %d %d",&a,&b,&c);
		e[a][b] = c;
	}
	//��ʼ��dis���� ��1���㵽�����������ĳ�ʼ��
	for(i = 1; i <= n; i++)
		dis[i] = e[1][i];
	//��ʼ��book����
	for(i=1;i<=n;i++)  
        book[i]=0;  
    book[1]=1;
    //Dijkstra�㷨
    for(i=1;i<=n-1;i++)
    {
        //�ҵ���1�Ŷ�������Ķ���
        min=inf;
        for(j=1;j<=n;j++)
        {
            if(book[j]==0 && dis[j]<min)
            {
                min=dis[j];
                u=j;
            }
        }
        book[u]=1;
        for(v=1;v<=n;v++)
        {
            if(e[u][v]<inf)
            {
                if(dis[v]>dis[u]+e[u][v])
                    dis[v]=dis[u]+e[u][v];
            }
        }
    }

    //������յĽ��
    printf("Dijkstra�㷨��\n");
    for(i=1;i<=n;i++)
        printf("%d ",dis[i]);
    return 0;
} 
