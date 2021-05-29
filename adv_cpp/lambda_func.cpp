/*This program will have the implementation of function pointers and then move to lambda to check it.*/
#include <bits/stdc++.h>

using namespace std;

void Print(int a)
{
	cout<<"Value ==="<<a<<endl;
}

int main()
{
	/* This is a function pointer which represents or which has the capability to 
	 * point or represent a function with a void return type and an integer as a 
	 * parameter.*/
	//void (*display)(int);

	/* Now display starts ponting to the Print() as it meets the criteria of the 
	 * type of function that can be pointed to by display function pointer.*/
	//display = Print;

	auto x=10;
	//display(x);
	
	/* Implementing Lambda function:*/
	/* Lambda functions are implemented when there is a need to implement function
	 * pointers*/
	//[captures](params)trailing-return-type{body}
	/*Check geeksforgeeks.com for more information*/
	vector<int> v1 = {1,4,7,9,10};
	vector<int> v2 = {2,6,8,11,12};
	auto pushinto = [&] (int m)
	{
		v1.push_back(m);
		v2.push_back(m);
	};

	pushinto(15);
	int N=5;
	vector<int>::iterator p = find_if(v1.begin(), v1.end(), [N](int i){
			return i>N;
			});

	cout<<"\n The First number greater than 5 are: "<< *p<<endl;
	return 0;
}
