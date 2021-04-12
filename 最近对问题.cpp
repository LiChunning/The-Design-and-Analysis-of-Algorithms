#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;

struct point
{
    double x,y;
};
double Distance(point a,point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
bool sortX(point a,point b)//按x升序
{
    return a.x<b.x;
}
bool sortY(point a,point b)//按y升序
{
    return a.y<b.y;
}

double closestPoint(point s[],int left,int right,point c[])
{
    double d1,d2,d3,d;
    int mid,i,j,index;
    double x1,y1,x2,y2;
    point P[right-left+1],temp1[2],temp2[2],temp3[2];
    if(right-left==1)//情况1：n=2 
	{
        c[0].x=s[left].x;
		c[0].y=s[left].y;
        c[1].x=s[right].x;
		c[1].y=s[right].y;
        return Distance(s[left],s[right]);
    }
    if(right-left==2)//情况2:n=3 
	{            
        d1=Distance(s[left],s[left+1]);
        d2=Distance(s[left+1],s[right]);
        d3=Distance(s[left],s[right]);
        if((d1<d2)&&(d1<d3))
		{
            c[0].x=s[left].x;
			c[0].y=s[left].y;
            c[1].x=s[left+1].x;
			c[1].y=s[left+1].y;
            return d1;
        }
        else if(d2<d3)
		{
            c[0].x=s[left+1].x;
			c[0].y=s[left+1].y;
            c[1].x=s[right].x;
			c[1].y=s[right].y;
            return d2;
        }
        else
		{
            c[0].x=s[left].x;
			c[0].y=s[left].y;
            c[1].x=s[right].x;
			c[1].y=s[right].y;
            return d3;
        }
    }
    //情况3：n>3
    mid=(left+right)/2;
    d1=closestPoint(s,left,mid,c);//P1集合 
    temp1[0]=c[0];
    temp1[1]=c[1];
    d2=closestPoint(s,mid+1,right,c);//Pr集合 
    temp2[0]=c[0];
    temp2[1]=c[1];
    if(d1<d2)
	{
        d=d1;
        c[0]=temp1[0];
        c[1]=temp1[1];
    }
    else
	{
        d=d2;
        c[0]=temp2[0];
        c[1]=temp2[1];
    }
    index=0;
    for(i=mid;(i>=left)&&((s[mid].x-s[i].x)<d);i--)
    {
    	P[index++]=s[i];
	}	
    for(i=mid+1;(i<=right)&&((s[i].x-s[mid].x)<d);i++)
    {
    	P[index++]=s[i];
	} 
    sort(P,P+index,sortY);
    for(i=0;i<index;i++)
	{
        for(j=j+1;j<index;i++)
		{
            if((P[j].y-P[i].y)>=d)
                break;
            else 
			{
                d3=Distance(P[i],P[j]);
                if(d3<d)
				{
                    c[0].x=P[i].x;
					c[0].y=P[i].y;
                    c[1].x=P[j].x;
					c[1].y=P[j].y;
                    d=d3;
                }
            }
        }
    }
    return d;
}
int main()
{
    point p[100];
    int n;
    double dmin;
    cout<<"输入点的个数:"<<endl;
    cin>>n;
    cout<<"输入点集:"<<endl;
    for(int i=0;i<n;i++)
    {
    	cin>>p[i].x>>p[i].y;
	}  
    sort(p,p+n,sortX);
    point index[2];
    dmin=closestPoint(p,0,n-1,index); 
    cout<<"最小距离为：\n"<<dmin;
    return 0;
}


