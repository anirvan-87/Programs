#include <bits/stdc++.h>

using namespace std;

class String
{
	public:
		String() = default;
		String(const char* other_str)
		{
			cout<<"Parameterized constructor"<<endl;
			size = strlen(other_str);
			data = new char[size];
			memcpy(data, other_str, size);
		}
		/* This copy constructor is the problematic stuff. Everytime we create an object 
		 * the copy constructor is called and it starts allocating memory on the heap.
		 * So if we create an array of objects then for each object a separate memory 
		 * on the heap is created, which we can imagine as to the amount of extra work
		 * that has been done. */
		String(const String &other)
		{
			cout<<"Copy constructor"<<endl;
			size = other.size;
			data = new char[size];
			memcpy(data, other.data, size);
		}
		/* To avoid the above problem we create a move constructor and it will move the 
		 * memory occupancy from the existing rvalue reference "other" in this case.
		 * Shallow copying is done here instead of Deep copy in copy constructor by
		 * rewiring the pointers. */
		String(String &&other) noexcept
		{	
			cout<<"Move constructor"<<endl;
			size = other.size;
			data = other.data;

			/* Take care of the data and size parameters else the destructor will destroy it 
			 * when going out of scope.*/
			other.data = nullptr;
			other.size = 0;
		}
		String& operator=(String&& other) noexcept
		{
			cout<<"Move assignment operator"<<endl;
			if(this != &other)
			{
				delete [] data;
				data = other.data;
				size = other.size;
				
				/* Same reason as above operation in move constructor.*/
				other.data = nullptr;
				other.size = 0;
			}
			return *this;
		}
		~String()
		{
			cout<<"Destroyed"<<endl;
			delete [] data;
			size = 0;
		}
		void print()
		{
			if(size>0)
			{
				for(uint16_t i=0;i<size;i++)
				{
					cout<<data[i];
				}
				cout<<"\n";
			}
		}
	private:
		char *data;
		uint16_t size;
};

class Employee
{
	public:
		Employee(const String& name):emp_name(name){
			//Copy constructor for the String class will be called here from the initializer list.
		}
		Employee(String&& name):emp_name(std::move(name)){
			//Move constructor called here by using the move operator which in turn creates an Rvalue reference.
		}
		void Printname()
		{
			emp_name.print();
		}
	private:
		String emp_name;
};

int main()
{
	Employee emp(String("Anirvan Roy Choudhury"));
	emp.Printname();

	String src = "Anirvan";
	String dest;

	dest = std::move(src);
	dest.print();

	return 0;
}

