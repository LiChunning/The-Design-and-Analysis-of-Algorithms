#include <iostream>
using namespace std;

class Time{
	public:
		int ID;
		int duration;
};
int main() {
	int m;		//m̨����
	int n;		//n������
	int time;	//��¼��С����ʱ��
	
	cout << "�����������Ŀ��";
	cin >> m;
	
	cout << "��������ӹ���������";
	cin >> n;
	
	int *machine = new int[m];		//��¼ÿ�������Ĵ���ʱ��
	Time *t = new Time[n];		// ��¼ÿ������Ĵ���ʱ��
	
	cout << "����������ӹ������ID������ʱ��:" << endl;
	
	for(int i = 0; i < n; i++){
		cin >>t[i].ID >> t[i].duration;
		cout << "ID:" << t[i].ID << ",time:" << t[i].duration << endl;
	}
		
	
	Time tmp;
	
	for(int i = 0; i < n-1; i++)
		for(int j = 0; j < n-i-1; j++)
		{
			if(t[j].duration < t[j+1].duration)
			{
				tmp = t[j];
				t[j] = t[j+1];
				t[j+1] = tmp;
			}
		}
	
	time = t[0].duration;
	int min;
	int min_pos;
	
	if(n>m)
	{
		for(int i = 0; i < m; i++)		//ÿ��������ֵһ��
		{
			machine[i] = t[i].duration;
			cout << "����" << t[i].ID << "���䵽����" << i << endl; 
		}
			
		
		for(int i = m; i < n; i++)		//����ʣ�µ�n-m����ҵ�����Ѿ��������Сʱ��Ļ���
		{
			min = machine[0];
			min_pos = 0;
			
			for(int j = 1; j < m; j++)
			{
				if(machine[j] < min)
				{
					min = machine[j];
					min_pos = j;
				}
			}
			machine[min_pos] += t[i].duration;
			cout << "����" << t[i].ID << "���䵽����" << min_pos << endl;
			if(time < machine[min_pos])
				time = machine[min_pos];
		 } 
	}
	cout << "������̴���ʱ���ǣ�" << time << endl;
	return 0;
}

