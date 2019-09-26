#include <iostream>
#include <string>
#include <sstream>
#include <queue>
#include <vector>
#include <map>
#include <iterator>

using namespace std;

int main()
{
	string input;
	cout<<"\n Enter the input";
	getline(cin,input);
/*	std::istringstream iss(input);
	std::vector<string> result(std::istream_iterator<string>{iss}, std::istream_iterator<string>());*/
	vector<string> result;
	for(int i=0;i<input.size();i++)
		cout<<input[i]<<endl;
	for(int i=0;i<result.size();i++)
		cout<<result[i]<<endl;
	map<string,int> m;
	m.insert(make_pair<string,int>("0",0));
	m.insert(make_pair<string,int>("1",1));
	m.insert(make_pair<string,int>("2",2));
	m.insert(make_pair<string,int>("3",3));
	m.insert(make_pair<string,int>("4",4));
	m.insert(make_pair<string,int>("5",5));
	m.insert(make_pair<string,int>("6",6));
	m.insert(make_pair<string,int>("7",7));
	m.insert(make_pair<string,int>("8",8));
	m.insert(make_pair<string,int>("9",9));
	m.insert(make_pair<string,int>("A",10));
	m.insert(make_pair<string,int>("B",11));
	m.insert(make_pair<string,int>("C",12));
	m.insert(make_pair<string,int>("D",13));
	m.insert(make_pair<string,int>("E",14));
	m.insert(make_pair<string,int>("F",15));
	std::queue<int> binput;
	int num;
	for(int i=0;i<result.size();i++)
	{
		cout<<"\n enter for parsing"<<endl;
		cout<<"result[i]=== "<<result[i]<<endl;
		cout<<"m[result[i]]=== "<<m[result[i]]<<endl;
		num = m[result[i]];
		cout<<num<<endl;
		while(num)
		{
			cout<<num%2;
			binput.push(num%2);
			binput.front();
			num=num/2;
			
		}
	}
	unsigned int arr[]={1,0,1,1}, res=0;
	while (!binput.empty()) 
	{ 
        	cout << '\t' << binput.front(); 
	} 
	cout << '\n'; 
	cout<<"size=== "<<binput.size()<<endl;
	for (int i=0;i<binput.size();i++)
	{
		cout<<"queue === "<<binput.front()<<endl;
		res = (2 * res) + binput.front();
		cout<<"res === "<<res<<endl;
		binput.pop();
	}
	cout<<"\n result ==  "<<res<<endl;
	return 0;
}	
