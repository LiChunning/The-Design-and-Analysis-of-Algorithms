#include <stdio.h> 
int Merge(int a[],int low, int mid, int high)// 合并函数
{
	int j, k, h;
	j = low;
	h = mid + 1;
	k = low;
	int b[8];
	while (j<=mid&&h<=high)	// 将左右两端数据进行比较，放入辅助数组中
	{
		if (a[j] < a[h])
			b[k++] = a[j++];
		else
			b[k++] = a[h++];
	}
	// 将剩余的数据加入到辅助数组中
	while (j <= mid)
	{
		b[k++] = a[j++];
	}
	while (h<=high)
	{
		b[k++] = a[h++];
	}
	for (k = low; k <= high; k++)// 将辅助数组的数据复制到原数组的对应位置上
	{
		a[k] = b[k];
	}
}

int MergeSort(int a[],int low,int high)	// 递归分组函数
{
	if (low < high)
	{
		int mid = (low + high) / 2;
		MergeSort(a,low, mid);
		MergeSort(a,mid + 1, high);
		Merge(a,low, mid, high);// 调用Merge函数，合并两组数据 
	}
}
int main (){
	int a[8] = {7,91,23,1,6,3,79,2};
	MergeSort(a,0,7);
	for(int i = 0; i < 8; i++){
		printf("%4d",a[i]);
	}
}
