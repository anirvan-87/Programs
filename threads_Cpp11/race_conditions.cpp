#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

using namespace std;

class Wallet
{
		int mMoney;
		mutex _mutex;
	public:
		Wallet():mMoney(0){}
		int getMoney() const{ return mMoney;}
		void AddMoney(int money)
		{
			/* Either take a lock with the help of mutex and release it whenever 
			 * the critical section is over as shown below in the commented section
			 * or use the lock_guard() mechanism, it takes a lock using the mutex 
			 * passed as a parameter in its constructor when it is called and 
			 * releases/unlocks it whenever it goes out of scope or when the dtor 
			 * is called. */
			//_mutex.lock();
			lock_guard<mutex> lGuard(_mutex);
			for(int i=0;i<money;++i)
			{
				mMoney++;
			}
			//_mutex.unlock();
		}
};

int testMultithreadedWallet()
{
	Wallet walletObj;
	vector<thread> threads;
	threads.push_back(thread(&Wallet::AddMoney, &walletObj, 5000));
	for(int i=0;i<threads.size();++i)
	{
		threads.at(i).join();
	}
	return walletObj.getMoney();
}

int main()
{
	int val = 0;
	for(int k=0;k<5;k++)
	{
		if( (val = testMultithreadedWallet()) != 5000)
		{
			cout<<"Error at count "<<k<<" Money in wallet "<<val<<endl;
		}
		else
		{
			cout<<"Money successfully added to wallet by "<<k<<" th thread"<<endl;
		}
	}
	return 0;
}
