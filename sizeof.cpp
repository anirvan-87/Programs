#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	int abc[10] = {1,2,3,4,5,6,7,8,9,10};
	cout<<"sizeof abc ==="<<sizeof(abc)<<endl;
	cout<<"sizeof ----- ==="<<sizeof("-----")<<endl;
	int len = strlen("\t\t");
	cout<<"sizeof not known ==="<<len<<endl;
	cout<<"sizeof string ==="<<strlen(" S")<<endl;
	return 0;
}
