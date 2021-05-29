#include <iostream>
#include <thread>

using namespace std;

void callback_t(int *p)
{
	cout<<"\n The value of p in this thread === "<<*p<<endl;
	chrono::milliseconds dura(1000);
	this_thread::sleep_for(dura);
	*p = 20;
}
int main()
{
	int *p = new int();
	*p = 10;
	thread t1(callback_t, p);
	chrono::milliseconds dura(1000);
	this_thread::sleep_for(dura);
	thread t2(callback_t, p);
	cout<<"\n The value of p in main thread === "<<*p<<endl;
	t1.detach();
	t2.detach();
	delete p;
	p = nullptr;
	return 0;
}
