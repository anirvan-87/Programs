#include <iostream>
#include <vector>

using namespace std;

/*void printvector(vector<int> v)
{
	for(int i=0;i<v.size()-1;i++)
		cout<<v[i]<<endl;
}
int main()
{
	vector<int> v;
	printvector(v);
	return 0;
}*/
template<typename T>
T op(T a, T b)
{
	return a-b;
}

int main()
{
	cout<<op(1,2)<<" "<<op(2.0,3.0)<<" "<<op<int>(2.0,3.0)<<" "<<op(2.0,3)<<endl;
	return 0;
}
