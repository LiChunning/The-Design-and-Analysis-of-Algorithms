#include <iostream>
using namespace std;

class Time{
	public:
		int ID;
		int duration;
};
int main() {
	int m;		//m台机器
	int n;		//n个任务
	int time;	//记录最小处理时间
	
	cout << "请输入机器数目：";
	cin >> m;
	
	cout << "请输入待加工任务数：";
	cin >> n;
	
	int *machine = new int[m];		//记录每个机器的处理时间
	Time *t = new Time[n];		// 记录每个任务的处理时间
	
	cout << "请输入各待加工任务的ID、处理时间:" << endl;
	
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
		for(int i = 0; i < m; i++)		//每个机器赋值一次
		{
			machine[i] = t[i].duration;
			cout << "任务" << t[i].ID << "分配到机器" << i << endl; 
		}
			
		
		for(int i = m; i < n; i++)		//对于剩下的n-m个作业，找已经处理的最小时间的机器
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
			cout << "任务" << t[i].ID << "分配到机器" << min_pos << endl;
			if(time < machine[min_pos])
				time = machine[min_pos];
		 } 
	}
	cout << "机器最短处理时间是：" << time << endl;
	return 0;
}

