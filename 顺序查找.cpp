#include<stdio.h>
 int main(){
 	int a[10]={4,8,10,15,22,30,35,55,60,68};
 	int x;
 	printf("����һ��Ҫ���ҵ���:");
 	scanf("%d",&x);
 	for(int i = 0;i < 10; ++i){
 		if(a[i] == x){
		 	printf("j���±�Ϊ��%d",i+1);
	        return 0;
		 }		 
	 }
	 printf("j=0");
 }
