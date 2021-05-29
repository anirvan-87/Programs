#include <bits/stdc++.h>

using namespace std;

template<class A, class B>
auto findmin(A a, B b) -> decltype(a>b?a:b)
{
	return (a>b) ? a : b;
}
int main()
{
	/*auto x = 3.34;
	decltype(x) y = 1.2;

	cout<<typeid(x).name()<<endl;
	cout<<typeid(y).name()<<endl;*/

	cout<< findmin(5.245, 4) <<endl;
	cout<< findmin(3.4,5) <<endl;

	return 0;
}
