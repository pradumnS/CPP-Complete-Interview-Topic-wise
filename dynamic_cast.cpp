#include<iostream>
using namespace std;

class base
{
	public:
	base(){std::cout << "base" << std::endl;}
	virtual void f(){}
};
class derive : public base
{
	public:
	derive(){std::cout << "derive" << std::endl;}
	virtual void f(){}
};
class derive1 : public derive
{
	public:
	derive1(){std::cout << "derive1" << std::endl;}
	virtual void f(){}
};
int main()
{
	base *bp,*bp1,*bp2,*bp3,*bp4;
	derive *dp,*dp1,*dp2,*dp3,*dp4,*dp5,*dp6,*dp7;
	derive1 *d_p,*d_p1,*d_p2;
	
	bp = new derive();
	dp = dynamic_cast<derive*>(bp); // this will work base pointer to derive
	if(dp)
	{
	    std::cout << "dp" << std::endl;
	}
	
	bp1 = new derive1();
	dp1 = dynamic_cast<derive*>(bp1); // this will work base pointer to derive
	if(dp1)
	{
	    std::cout << "dp1" << std::endl;
	}
	
	dp2 = new derive1();
	d_p = dynamic_cast<derive1*>(dp2); // this will work drive pointer to derive1
	if(d_p)
	{
	    std::cout << "d_p" << std::endl;
	}
	
	bp2 = new base();
	dp3 = dynamic_cast<derive*>(bp2); // this will not work base pointer(an object of type base) to derive
	if(dp3)
	{
	    std::cout << "dp3" << std::endl;
	}
	//dp3->f();   this will give segmentation fault
	
	dp4 = new derive();
	d_p2 = dynamic_cast<derive1*>(bp2); // this will not work base pointer(an object of type derive) to derive
	if(d_p2)
	{
	    std::cout << "d_p3" << std::endl;
	}
	
	return 0;
}

/***********************************************************************************************************
2nd:
*******************************************************************************************************************/
#include<iostream>
#include<vector>
using namespace std;
class base 
{
    char *P;
    public:
    virtual void f(){std::cout << "virtual f() " << std::endl;}
    base(){std::cout << "base" << std::endl;}
    base(char *p):P(p){std::cout << P << std::endl;}
};
class derive : public base 
{
    int n;
    public:
    virtual void f(){std::cout << "virtual f() for derive " << std::endl;}
    derive():n(0){std::cout << "derive" << std::endl;}
    derive(int no):n(no){std::cout << "n" << std::endl;}
};
int main()
{
    base bp,*bp1,*bp2;
    derive dp, *dp1,*dp2;
    base *bp3 = new derive();
    derive *dp3 = new derive();
    bp1 = dynamic_cast<base*>(dp3);
    if(bp1)
    {
        std::cout << "dp3 successful" << std::endl;
    }
    dp.f();
    
    bp1 = dynamic_cast<base*>(&dp);
    if(bp1)
    {
        std::cout << "bp1 successful" << std::endl;
    }
    dp.f();
    
    dp1 = dynamic_cast<derive*>(bp3);
    if(dp1)
    {
        std::cout << "dp1 because virtual" << std::endl;
    }
    return 0;
}





