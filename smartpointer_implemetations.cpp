********************************************************************************************************************

					smart pointers;
Question no-1;

***********************************************************************************************************************/
#include<iostream>
#include<vector>
using namespace std;
class test
{
	public:
	test():p(nullptr){}
	test(char *s):p(s){std::cout << s << std::endl;}
	void display(){cout<< p<<endl;}
	private:
	char *p;
};
class SP
{
	test *p;
	public:
	SP():p(nullptr){}
	SP(test *obj):p(obj){}
	~SP(){delete p;}
	test& operator* (){return *p;}
	test* operator-> (){return p;}	
};
int main()
{
	SP p(new test("hello")); p->display();
	return 0;
}

********************************************************************************************************************

					generic smart pointers;
Question no-2;

***********************************************************************************************************************/
#include<iostream>
#include<vector>
using namespace std;
class test
{
	public:
	test():p(nullptr){}
	test(char *s):p(s){std::cout << s << std::endl;}
	void display(){cout<< p<<endl;}
	private:
	char *p;
};
template <class T>
class SP
{
	T *p;
	public:
	SP():p(nullptr){}
	SP(T *obj):p(obj){}
	~SP(){delete p;}
	T& operator* (){return *p;}
	T* operator-> (){return p;}	
};
int main()
{
	SP<test> p(new test("hello")); p->display();
	return 0;
}


********************************************************************************************************************

					generic shared_ptr implementsions smart pointers;
Question no-3;

***********************************************************************************************************************/
#include<iostream>
#include<vector>
using namespace std;
class test
{
	public:
	test():p(nullptr){}
	test(char *s):p(s){std::cout << s << std::endl;}
	void display(){cout<< p<<endl;}
	private:
	char *p;
};
class RC 
{
	int count=0;
	public:
	RC():count(0){}
	void addref(){count++;}
	int release(){count--; return count;}
};
template <class T>
class SP
{
	T *p; RC *ref;
	public:
	SP():p(nullptr),ref(nullptr)
	{
		ref = new RC();
		ref->addref();
	}
	SP(T *obj):p(obj),ref(nullptr)
	{
		ref = new RC();
		ref->addref();
	}
	SP(const SP<T> &Obj):p(Obj.p),ref(Obj.ref)
	{
		ref = new RC();
		ref->addref();
	}
	~SP()
	{
		if(ref->release() == 0)
		{
			delete p; delete ref;
		}	
		
	}
	T& operator* (){return *p;}
	T* operator-> (){return p;}	
};
int main()
{
	SP<test> p(new test("hello")); p->display();
	return 0;
}

********************************************************************************************************************

					generic unique_ptr implementsions smart pointers;
Question no-3;

***********************************************************************************************************************/
#include<iostream>
#include<vector>
using namespace std;
class test
{
	public:
	test():p(nullptr){}
	test(char *s):p(s){std::cout << s << std::endl;}
	void display(){cout<< p<<endl;}
	private:
	char *p;
};
template <class T>
class SP
{
	T *p;
	public:
	SP():p(nullptr)
	{}
	SP(T *obj):p(obj)
	{}
//	SP(const SP<T> &Obj):p(Obj.p) = delete;
//	{}
	SP(SP<T> &&Obj):p(move(Obj.p))
	{
	    std::cout << "move constructor" << std::endl;
	    Obj.p = nullptr;
	}
	~SP()
	{
		delete p;
	}
	T& operator* (){return *p;}
	T* operator-> (){return p;}	
};
int main()
{
	SP<test> p(new test("hello"));
	SP<test> p1 = move(p);
	//p->display();
	p1->display();
	return 0;
}
********************************************************************************************************************

					generic unique_ptr implementsions smart pointers;
Question no-3;

***********************************************************************************************************************/
#include<iostream>
#include<vector>
using namespace std;
class test
{
	public:
	test():p(nullptr){}
	test(char *s):p(s){std::cout << s << std::endl;}
	void display(){cout<< p<<endl;}
	private:
	char *p;
};
class RC 
{
	int count=0;
	public:
	RC():count(0){}
	void addref(){count++;}
	int release(){count--; return count;}
};
template <class T>
class SP
{
	T *p;
	public:
	SP():p(nullptr)
	{
		
	}
	SP(T *obj):p(obj)
	{
	
	}
//	SP(const SP<T> &Obj):p(Obj.p) = delete;
//	{
//		
//	}
	SP(SP<T> &&Obj):p(Obj.p)
	{
	    std::cout << "move constructor" << std::endl;
	    Obj.p = nullptr;
	}
	SP& operator =(SP<T> &&Obj) 
	{
	    if(&Obj == this)
	        return *this;
	    delete p;
	    p = new T;
	    p = Obj.p;
	    Obj.p = nullptr;
	    std::cout << "move assignment operator " << std::endl;
	   return *this;
	}
	~SP()
	{
			delete p;
	}
	T& operator* (){return *p;}
	T* operator-> (){return p;}	
};
SP<test> generateResource()
{
	SP<test> res(new test("hi"));
	return res; // this return value will invoke the move constructor
}
int main()
{
    SP<test> mainres = generateResource(); // move constructor not calling
	SP<test> mainres1; mainres1 = generateResource();
	
	//p->display();
	//p2->display();
	return 0;
}
