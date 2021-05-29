#include <bits/stdc++.h>

using namespace std;
class Test
{
	public:
		Test()
		{
			cout<<"\n Created";
		}
		void greet()
		{
			cout<<"\n Hello ";
		}
		~Test()
		{
			cout<<"\n Destroyed";
		}
};

int main()
{
	shared_ptr<Test> ptest1(nullptr);
	{
		shared_ptr<Test> ptest2 = make_shared<Test>();
		ptest1 = ptest2;
		auto p1 = ptest2;
	}
	cout<<"\n Finished";

#if 0
	//Basic functionality and working of shared_ptr.
	
	shared_ptr<int> p1 = make_shared<int>();
	*p1 = 100;
	cout<<"\n The value of p1 is: "<< *p1;

	//Shows the reference count
	cout<<"\n Reference count for p1 = "<<p1.use_count();

	//Making second pointer point to first pointer
	shared_ptr<int> p2(p1);

	cout<<"\n Reference count for p1 = "<<p1.use_count();
	cout<<"\n Reference count for p2 = "<<p2.use_count();

	//Comparison of p1 and p2
	if(p1 == p2)
	{
		cout<<"\n Both p1 and p2 are same "<<endl;
	}

	cout<<"\n Resetting p1 "<<endl;

	p1.reset();

	cout<<"\n Reference count for p1 = "<<p1.use_count();

	//Resetting the pointer will make its reference count to 0.
	
	if(p1==nullptr)
	{
		cout<<"\n p1 is now set to null";
	}

	cout<<"\n Resetting p1 again to a new memory"<<endl;

	p1.reset(new int(500));

	cout<<"\n Reference count for p1 = "<<p1.use_count();

	//Resetting the pointer will make its reference count to 1.
	
	if(p1==nullptr)
	{
		cout<<"\n p1 is now set to null";
	}

	p1 = nullptr;

	//Now checking the reference count of p1 after setting it to nullptr
	cout<<"\n Reference count for p2 = "<<p1.use_count();

	if(!p1)
	{
		cout<<"\n p1 is NULL"<<endl;
	}
#endif
	return 0;
}

