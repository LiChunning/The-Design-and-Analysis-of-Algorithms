#include<stdio.h>
#define N 100
int c1,c2;//装载量 
int n; //物品数目 
int w[N];//物品重量 
int flag[N]={0};//标记
int r=0;//总余量 
int cw=0;//当前重量
int bw=0;//最优解
int choose[N];//保存数组 
void backtrack(int i){
	int j;
	if(i>n){//到达叶节点 
		if(cw>bw){//更新最优值 
			bw=cw;
			for(j=1;j<=n;j++){
				choose[j]=flag[j];
			}
		}
		return ;
	}
	r-=w[i];//更新剩余容量 
	if(cw+w[i]<=c1){//左子树（加上此节点重量不超过c1） 
		cw+=w[i];//更新现有重量 
		flag[i]=1;//标记，即记录数据 
		backtrack(i+1);//递归 
		cw-=w[i];//恢复 
		flag[i]=0;
	}
	if(cw+r>bw){//右子树，如果现有重量加上剩余量不超过最优值时剪枝 
		backtrack(i+1);//递归 
	} 
	r+=w[i];//恢复余量 
}
int main()
{
	int i,sum=0;
	printf("请输入c1,c2装载量和物品数目："); 
	scanf("%d %d %d",&c1,&c2,&n);
	for(i=1;i<=n;i++){
		scanf("%d",&w[i]);
		r+=w[i]; 
		sum+=w[i]; 
	}
	backtrack(1);
	if(sum-bw<=c2){
		printf("能够将物品装下\nc1放的物品为：");
		for(i=1;i<=n;i++){
			if(choose[i]==1) printf("%d ",i);
		} 
		printf("\nc2放的物品为：");
		for(i=1;i<=n;i++){
			if(choose[i]==0) printf("%d ",i);
		} 
	} else{
		printf("不能放入所有物品\n"); 
	}
} 
