#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>

using namespace std;

class Application
{
	bool Data_loaded;
	mutex m_mutex;
	condition_variable cond_var;
	public:
		Application():Data_loaded(false){}
		bool get_data_loaded()
		{
			return Data_loaded;
		}
		void data_loading()
		{
			this_thread::sleep_for(chrono::milliseconds(1000));
			cout<<"Loading data from XML file"<<endl;
			lock_guard<mutex> lguard(m_mutex);
			Data_loaded = true;
			cond_var.notify_one();
		}
		void maintask()
		{
			cout<<"Doing some handshaking"<<endl;
			/* When we want to lock a mutex we create a local variable of type
			 * unique_lock and pass the mutex as a parameter. So when the 
			 * unique_lock gets created the constructor takes a lock on the 
			 * mutex and when it goes out of scope or if any exception is 
			 * thrown the destructor is called and the mutex is unlocked.
			 */
			unique_lock<mutex> u_lock(m_mutex);
			/* It causes the current thread to block until the condition variable
			 * is notified or a spurious wakeup occurs, optionally looping until
			 * some predicate is satisfied, in this case it is the Data_loaded 
			 * variable which is returned via the get_data_loaded(). Generally 
			 * the predicate should be in the form of bool pred();
			 * The parameters for wait are: 1.) unique_lock, 2.) predicate*/
			cond_var.wait(u_lock, bind(&Application::get_data_loaded, this));
			cout<<"Start processing the data"<<endl;
		}
};

int main()
{
	Application app;
	thread thread1(&Application::maintask, &app);
	thread thread2(&Application::data_loading, &app);
	thread2.join();
	thread1.join();
	return 0;
}
