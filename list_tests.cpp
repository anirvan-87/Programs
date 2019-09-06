#include <iostream>
#include <list>

using namespace std;
class ABC
{
	public:
		void display()
		{
			cout<<"ABC::display()"<<endl;
		}
};
int main()
{
	list<ABC *> l;
	ABC *abc = new ABC();
	ABC *Abc = new ABC();
	ABC *aBc = new ABC();
	ABC *abC = new ABC();
	l.push_back(abc);
	l.push_back(Abc);
	l.push_back(aBc);
	l.push_back(abC);
	l.remove(abc);
	cout<<l.size()<<endl;
	return 0;
}
