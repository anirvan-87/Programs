#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, flag=0;
	cout<<"\n enter the number \n";
	cin>>n;
	int last = (int)sqrt(n) +1;
	for(int i=2;i<=last;++i)
	{
		if(n%i==0)
		{
			cout<<"\n Divisors =="<<i<<endl;
			flag=1;
		}
		else
			flag=0;
	}
	if(1==flag)
		cout<<"\n The number is prime \n";
	else
		cout<<"\n The number is not prime \n";
	return 0;
}	
