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
	string in1,in2; //값이 클수도 있기 때문에 string 으로 입력; 

	for(int i=0;i<n;i++)
	{
		
		cin>>in1>>in2; 
		long long int re1=0,re2=0,dig=0;
		
		for(int i=0;i<in1.length();i++)	
		{
			dig=in1[i]-'0'; //대신 매 자리마다 0을 뺴줘야함; 
       		re1+=dig*pow(2,in1.length()-i-1); //0번째 자리부터 곱해서 더하기; 
		}
		
		for(int i=0;i<in2.length();i++) //같음; 
		{
			dig=in2[i]-'0';
       		re2+=dig*pow(2,in2.length()-i-1);
		}
		
		if(re1<re2) //만약 작다면 re가 잴 큰 숫자가 오게끔 하기 (계산하기 편함); 
		{
			int temp;
			temp=re1;
			re1=re2;
			re2=temp;
		}
		while(re1!=0&&re2!=0) //0이 아니면 계속 값을 구함 0 이면 끝이니깐 ; 
		{
			dig=re1%re2; //나누기 
			re1=re2; //2번째값 가져오기 
			re2=dig; // 두번쨰 값은 나눈값; 
		} // 뭔뜻이나면? EX:  11011,11000 -> 27,24  (dig = 27 % 24 = 3) (re1 = 24) (re2 = 3) (dig = 24 % 3 = 8) (re1 = 3) (re2 = 8) but re1 % re2 ==0 out of loop; 


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




