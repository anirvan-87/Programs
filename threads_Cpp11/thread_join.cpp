#include <iostream>
#include <thread>

bool do_continue = false;
using namespace std;

class DoWork
{
	public:
		void operator()()
		{
			cout<<this_thread::get_id()<<endl;
			while(!do_continue)
			{
				cout<<"Working"<<endl;
				this_thread::sleep_for(chrono::milliseconds(1000));
			}
		}
};

class ThreadRAII
{
	thread &th;
	public:
		ThreadRAII(thread &tObj):th(tObj)
		{
			cout<<"ThreadRAII constructor called and now joining the thread"<<endl;
			if(th.joinable())
			{
				th.join();
			}
		}
		~ThreadRAII()
		{
			cout<<"ThreadRAII destructor called and now detaching the thread"<<endl;
			if(th.joinable())
			{
				th.detach();
			}
		}
};

int main()
{
	thread worker((DoWork()));
	ThreadRAII wrapperObj(worker);
	cin.get();
	cout<<this_thread::get_id()<<endl;
	do_continue=true;
	return 0;
}
