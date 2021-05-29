#include <iostream>
#include <thread>
#include <chrono>

bool do_continue = false;

using namespace std;

//Ways to create threads in c++11
//1.) Using function pointers
void Do_work()
{
	cout<<this_thread::get_id()<<endl;
	while(!do_continue)
	{
		cout<<"Working"<<endl;
		this_thread::sleep_for(chrono::seconds(1));
	}
}

//2.) Using Function Objects
class Dowork
{
	public:
		void operator()()
		{
			cout<<this_thread::get_id()<<endl;
			while(!do_continue)
			{
				cout<<"Working"<<endl;
				this_thread::sleep_for(chrono::seconds(1));
			}
		}
};
int main()
{
	//thread worker(Do_work); /*For function pointers */
	//thread worker((Dowork())); /*For function objects */
	thread worker([]{               /*using lambda functions*/
			cout<<this_thread::get_id()<<endl;
			while(!do_continue)
			{
				cout<<"Working"<<endl;
				this_thread::sleep_for(chrono::seconds(1));
			}
		});
	cin.get();
	cout<<this_thread::get_id()<<endl;
	do_continue=true;
	worker.detach();
	return 0;
}
