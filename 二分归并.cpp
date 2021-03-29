#include <stdio.h> 
int Merge(int a[],int low, int mid, int high)// �ϲ�����
{
	int j, k, h;
	j = low;
	h = mid + 1;
	k = low;
	int b[8];
	while (j<=mid&&h<=high)	// �������������ݽ��бȽϣ����븨��������
	{
		if (a[j] < a[h])
			b[k++] = a[j++];
		else
			b[k++] = a[h++];
	}
	// ��ʣ������ݼ��뵽����������
	while (j <= mid)
	{
		b[k++] = a[j++];
	}
	while (h<=high)
	{
		b[k++] = a[h++];
	}
	for (k = low; k <= high; k++)// ��������������ݸ��Ƶ�ԭ����Ķ�Ӧλ����
	{
		a[k] = b[k];
	}
}

int MergeSort(int a[],int low,int high)	// �ݹ���麯��
{
	if (low < high)
	{
		int mid = (low + high) / 2;
		MergeSort(a,low, mid);
		MergeSort(a,mid + 1, high);
		Merge(a,low, mid, high);// ����Merge�������ϲ��������� 
	}
}
int main (){
	int a[8] = {7,91,23,1,6,3,79,2};
	MergeSort(a,0,7);
	for(int i = 0; i < 8; i++){
		printf("%4d",a[i]);
	}
}
