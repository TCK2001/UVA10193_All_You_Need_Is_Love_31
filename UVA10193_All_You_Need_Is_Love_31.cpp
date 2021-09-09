/*
5
11011
11000
11011
11001
111111
100
1000000000
110
1010
100
Sample Output
Pair #1: All you need is love!
Pair #2: Love is not all you need!
Pair #3: Love is not all you need!
Pair #4: All you need is love!
Pair #5: All you need is love!
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;


int main()
{
	int n;
	cin>>n;
	string in1,in2; //���� Ŭ���� �ֱ� ������ string ���� �Է�; 

	for(int i=0;i<n;i++)
	{
		
		cin>>in1>>in2; 
		long long int re1=0,re2=0,dig=0;
		
		for(int i=0;i<in1.length();i++)	
		{
			dig=in1[i]-'0'; //��� �� �ڸ����� 0�� �������; 
       		re1+=dig*pow(2,in1.length()-i-1); //0��° �ڸ����� ���ؼ� ���ϱ�; 
		}
		
		for(int i=0;i<in2.length();i++) //����; 
		{
			dig=in2[i]-'0';
       		re2+=dig*pow(2,in2.length()-i-1);
		}
		
		if(re1<re2) //���� �۴ٸ� re�� �� ū ���ڰ� ���Բ� �ϱ� (����ϱ� ����); 
		{
			int temp;
			temp=re1;
			re1=re2;
			re2=temp;
		}
		while(re1!=0&&re2!=0) //0�� �ƴϸ� ��� ���� ���� 0 �̸� ���̴ϱ� ; 
		{
			dig=re1%re2; //������ 
			re1=re2; //2��°�� �������� 
			re2=dig; // �ι��� ���� ������; 
		} // �����̳���? EX:  11011,11000 -> 27,24  (dig = 27 % 24 = 3) (re1 = 24) (re2 = 3) (dig = 24 % 3 = 8) (re1 = 3) (re2 = 8) but re1 % re2 ==0 out of loop; 


		cout<<"Pair #"<<i+1<<" : ";
		if(re1>=re2)
		{
			if(re1!=1)
			{
				cout<<"All you need is Love!"<<endl;
			}
			else
			{
				cout<<"Love is not all you need!"<<endl;
			}
		}
	}
return 0;
}




