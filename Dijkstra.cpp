#include <stdio.h>
int main()
{
	int e[10][10],dis[10],book[10],i,j,n,m,a,b,c,u,v,min;
	int inf = 99999999;
	//读入顶点数n，边数m
	scanf("%d %d",&n,&m);
	//初始化
	for(i = 1; i <= n; i++){
		for(j = 1; j <= n; j++){
			if(i == j) e[i][j] = 0;
			else e[i][j] = inf;
		}
	}
	//读入边
	for(i = 1; i <= m; i++){
		scanf("%d %d %d",&a,&b,&c);
		e[a][b] = c;
	}
	//初始化dis数组 ，1顶点到其余各个顶点的初始化
	for(i = 1; i <= n; i++)
		dis[i] = e[1][i];
	//初始化book数组
	for(i=1;i<=n;i++)  
        book[i]=0;  
    book[1]=1;
    //Dijkstra算法
    for(i=1;i<=n-1;i++)
    {
        //找到离1号顶点最近的顶点
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

    //输出最终的结果
    printf("Dijkstra算法：\n");
    for(i=1;i<=n;i++)
        printf("%d ",dis[i]);
    return 0;
} 
