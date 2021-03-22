#include<stdio.h> 
int main(){
 	int a[10]={4,8,10,15,22,30,35,55,60,68};
 	int x;
 	printf("输入一个要查找的数:");
 	scanf("%d",&x);
 	int l=0,r=9,mid;
	while(l<=r){
    	mid=(l+r)/2;
    	if (a[mid]<x) l=mid+1;
    	else if (a[mid]>x) r=mid-1;
    	else {
			printf("j的下标为：%d",mid+1);
			return 0;
		}
	}
	printf("j=0");
}
