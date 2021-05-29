#include <iostream>
#include <memory>

using namespace std;

class Test
{
	public:
		Test()
		{
			cout<<"\n Created ";
		}

		void greet()
		{
			cout<<"\n Hello ";
		}

		~Test()
		{
			cout<<"\n Deleted";
		}
};

class ABC
{
	private:
		unique_ptr<Test[]> test;
	public:
		ABC():test(new Test[2]){
		}

		~ABC()
		{
		}
};

int main()
{
	ABC abc;
	return 0;
}
