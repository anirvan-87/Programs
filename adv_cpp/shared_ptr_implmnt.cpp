#include <iostream>
using namespace std;

class Counter
{
	private:
		unsigned int m_count;
	public:
		Counter():m_count(0){}
		Counter(const Counter &)=default;
		Counter& operator=(const Counter &)=default;

		//Destructor
		~Counter(){}

		//Pre-increment operator
		void operator++()
		{
			m_count++;
		}
		//Pre-decrement operator
		void operator--()
		{
			m_count--;
		}
		//Post increment operator
		void operator++(int)
		{
			m_count++;
		}
		//Post decrement operator
		void operator--(int)
		{
			m_count--;
		}
		unsigned int getcount()
		{
			return m_count;
		}
		void reset_count()
		{
			m_count=0;
		}
		//Overloading '<<' operator
		friend ostream &operator<<(ostream &os, const Counter &count)
		{
			os<<"Counter value: "<<count.m_count<<endl;
			return os;
		}
};

template<typename T>
class Shared_ptr
{
	private:
		T *m_ptr;
		Counter *m_counter;
	public:
		explicit Shared_ptr(T *ptr = nullptr)
		{
			m_ptr=ptr;
			m_counter = new Counter();
			if(ptr)
			{
				m_counter++;
			}
		}

		Shared_ptr(Shared_ptr<T> *ptr)
		{
			m_ptr = ptr;
			m_counter = ptr.counter;
			(*m_counter)++;
		}

		unsigned int use_count()
		{
			return m_counter->getcount();
		}

		T& operator*()
		{
			return *m_ptr;
		}

		T* operator->()
		{
			return m_ptr;
		}

		T* get()
		{
			return m_ptr;
		}

		unsigned int use_count()
		{
			return m_counter->getcount();
		}

		~Shared_ptr()
		{
			(*m_counter)--;
			if(m_counter->getcount() == 0)
			{
				delete m_ptr;
				m_counter->reset_count();
			}
		}

		friend ostream& operator<<(ostream &os, const Shared_ptr<T> &ptr)
		{
			os<<"Address pointed to: "<<ptr.get()<<endl;
			os<<*(ptr.m_counter)<<endl;
			return os;
		}
};

int main()
{
	Shared_ptr<int> ip(new int[51]);
	*ip=101;
	Shared_ptr<int> ip1 = ip;
	cout<<*ip<<endl;
	cout<<ip1<<endl;
	return 0;
}
