//#include <iostream>
//#include <cstdio>
//using namespace std;
//const int MAX_SIZE = 100;
//
//void matrixChain(int p[], int n) {
//	int m[MAX_SIZE][MAX_SIZE] = {0}, s[MAX_SIZE][MAX_SIZE];  //m[i][i]��ʼ��Ϊ0�����ڴ洢�˷��������м�ֵ  s[][]���ڴ洢����λ�õ��±�
//	int i,j;
//	for (int r = 2; r <= n; r++) {  //rΪ��ǰ�����ģ
//		for (i = 1; i <= n - r + 1; i++) {  //�����������
//
//			j = i + r - 1;  //�����յ���������
//			m[i][j] = m[i + 1][j] + p[i - 1] * p[i] * p[j];
//			s[i][j] = i;
//
//			//������ͬ����λ�ã��洢��С�ĳ˷���������λ���±�
//			for (int k = i + 1; k <= j - 1; k++) {
//				int temp = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
//				if (temp < m[i][j]) {
//					m[i][j] = temp;
//					s[i][j] = k;
//				}
//			}
//		}
//	}
//	cout<<m[i][j]<<endl;
//}
//
//int main() {
//	int n,p[MAX_SIZE];  //n��ʾ�������  p[]��ʾ��������������
//	printf("�������:");
//	scanf("%d", &n);
//	printf("��������������:");
//	for (int i = 0; i <= n; i++)  //n��������n+1��������
//		scanf("%d", &p[i]);
//
//	//���ú���������
//	matrixChain(p, n);
//}
#include <iostream>
using namespace std;
#include <time.h>
#include <stdlib.h>
#include <string.h>
int n;
int* data;
int** m;
int** s;
// init
void getData() {
    n = 5;
    data = new int[n+1]();
    data[0]=10; data[1]=6;data[2]=30;data[3]=20;data[4]=7;data[5]=5;
    m = new int*[n+1];
    s = new int*[n+1];
    printf("n=%d\n",n);
    printf("<");
    for (int i = 0; i <= n; i++) {
        if (i==n) {
            printf("%d>",data[i]);
        }
        else
            printf("%d,",data[i]);
        m[i] = new int[n+1]();
        s[i] = new int[n+1]();
    }
}
// ���� r ����ӡ����
void printR() {
    for (int k = 1; k <= n; k++) {
        printf("r=%d\n",k);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < n+1; j++) {
                if ((j-i+1) == k) {
                    printf("m[%d,%d]=%d\n",i,j,m[i][j]);
                }
            }
        }
    }
    for (int k = 2; k <= n; k++) {
        cout << "r=" << k;
        for (int i = 1; i < n+1; i++) {
            for (int j = 1; j < n+1; j++) {
                if ((j-i+1) == k) {
                    printf("s[%d,%d]=%d\n",i,j,s[i][j]);
                }
            }
        }
    }
}

void matrixChain(int* data,int n) { //����
    int i,j,k,t;
    for (int i = 0; i < n+1; i++){
        for (int j = 0; j < n+1; j++) {
            s[i][j] = i;
        }
    }
    printR();
    for(int r = 2; r <= n; r++) {       //rΪ��ǰ�����ģ�����������⻮��
        for(i = 1; i <= (n-r+1); i++) { //i����㲻�ϱ仯������r��
            j = i + r -1;               //��ͬ�յ�
            m[i][j] = m[i+1][j] + data[i-1]*data[i]*data[j];  //����ΪAi(Ai+1....Aj)
            s[i][j] = i;                                      //���Ԫ�� = ���� ��¼�ָ�λ��
            for(k = i + 1; k <= j - 1; k++) {                 //��ͬ�Ļ���λ��
                t = m[i][k] + m[k+1][j] + data[i-1]*data[k]*data[j]; //ǰ���+�����+�������
                if (t < m[i][j]) {
                    m[i][j] = t;
                    s[i][j] = k;
                }
            }
        }
    }
}

int recurMatrixChain(int* data,int i, int j) {//�ݹ�
    if (i == j) { // �ݹ鵽��С��Ԫ
        m[i][j] = 0;
        s[i][j] = i;
        return m[i][j];
    }
    m[i][j] = 1 << 30;  //�����
    s[i][j] = i;        //��i�ָ�
    for (int k=i; k<=j-1;k++) { // ��i��j-1��ʼ�ݹ飬����Сֵ��Ȼ�������������
        int q = recurMatrixChain(data, i, k) + recurMatrixChain(data, k+1, j) + data[i-1]*data[k]*data[j]; //data[0]*data[k]*data[j]
        if (q < m[i][j]) {
            m[i][j] = q;
            s[i][j] = k;
        }
    }
    return m[i][j];
}
// ��ӡ����
void printProcess(int start, int end) {
    if (start == end)
        return;
    printProcess(start, s[start][end]);
    printProcess(s[start][end]+1, end);
    printf("(A%d*A%d)",start,end);
    if (start != 1 || end !=n) {
        printf("->");
    }
}
// ��ӡ����
void printOrder(int start, int end) {
    if (start == end) {
       // printf("A");
        cout << "A"<< end;
        return;
    }
    printf("(");
    printOrder(start, s[start][end]);
    printf("*");
    printOrder(s[start][end]+1, end);
    printf(")");
}
void printResult() {
    cout << endl << "result : " << m[1][n] << endl;
    printOrder(1, n);
    cout << endl;
    printProcess(1, n);
}
int main() {
    getData();
    //matrixChain(data, n);
    recurMatrixChain(data, 1, n);
    printR();
    printResult();
    getchar();
    return 0;
}
