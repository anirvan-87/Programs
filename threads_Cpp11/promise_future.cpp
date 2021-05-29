#include <iostream>
#include <thread>
#include <future>

using namespace std;

void initializer(promise<int> *promiseObj)
{
	cout<<"Setting the value in the promise object"<<endl;
	promiseObj->set_value(45);
}

int main()
{
	promise<int> PromiseObj;
	future<int> futureObj = PromiseObj.get_future();
	thread th(initializer, &PromiseObj);
	cout<<"The value set by promise object is: "<<futureObj.get()<<endl;
	th.join();
	return 0;
}
