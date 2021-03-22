#include<stdio.h>
 int main(){
 	int a[10]={4,8,10,15,22,30,35,55,60,68};
 	int x;
 	printf("输入一个要查找的数:");
 	scanf("%d",&x);
 	for(int i = 0;i < 10; ++i){
 		if(a[i] == x){
		 	printf("j的下标为：%d",i+1);
	        return 0;
		 }		 
	 }
	 printf("j=0");
 }
