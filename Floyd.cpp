#include<stdio.h> 

int main() 
{
	int e[10][10],k,i,j,n,m,a,b,c;
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
	//Floyd�㷨
	for(k = 1; k <= n; k++)
	for(i = 1; i <= n; i++)
	for(j = 1; j <= n; j++)
	if(e[i][j] > e[i][k] + e[k][j])
		e[i][j] = e[i][k] + e[k][j];
	//���
	printf("Floyd:\n");
	for(i = 1; i <= n; i++){
		for(j = 1; j <= n; j++){
			printf("%4d",e[i][j]);
		}
		printf("\n");
	}	 
	
	return 0;
}

