#include<stdio.h>
#define N 100
int c1,c2;//װ���� 
int n; //��Ʒ��Ŀ 
int w[N];//��Ʒ���� 
int flag[N]={0};//���
int r=0;//������ 
int cw=0;//��ǰ����
int bw=0;//���Ž�
int choose[N];//�������� 
void backtrack(int i){
	int j;
	if(i>n){//����Ҷ�ڵ� 
		if(cw>bw){//��������ֵ 
			bw=cw;
			for(j=1;j<=n;j++){
				choose[j]=flag[j];
			}
		}
		return ;
	}
	r-=w[i];//����ʣ������ 
	if(cw+w[i]<=c1){//�����������ϴ˽ڵ�����������c1�� 
		cw+=w[i];//������������ 
		flag[i]=1;//��ǣ�����¼���� 
		backtrack(i+1);//�ݹ� 
		cw-=w[i];//�ָ� 
		flag[i]=0;
	}
	if(cw+r>bw){//�����������������������ʣ��������������ֵʱ��֦ 
		backtrack(i+1);//�ݹ� 
	} 
	r+=w[i];//�ָ����� 
}
int main()
{
	int i,sum=0;
	printf("������c1,c2װ��������Ʒ��Ŀ��"); 
	scanf("%d %d %d",&c1,&c2,&n);
	for(i=1;i<=n;i++){
		scanf("%d",&w[i]);
		r+=w[i]; 
		sum+=w[i]; 
	}
	backtrack(1);
	if(sum-bw<=c2){
		printf("�ܹ�����Ʒװ��\nc1�ŵ���ƷΪ��");
		for(i=1;i<=n;i++){
			if(choose[i]==1) printf("%d ",i);
		} 
		printf("\nc2�ŵ���ƷΪ��");
		for(i=1;i<=n;i++){
			if(choose[i]==0) printf("%d ",i);
		} 
	} else{
		printf("���ܷ���������Ʒ\n"); 
	}
} 
