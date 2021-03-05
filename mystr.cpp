#include <iostream>
using namespace std;

class mystr 
{
    char *buf;
    int sz;
    public:
    mystr():buf(nullptr),sz(0){}
    mystr(char *p)
    {
        sz = Size(p);
        buf = new char[sz];
        for (int i =0; *p; p++,i++)
        {
            buf[i] = *p;
        }
        buf[sz] = '\0';
        std::cout << buf<< std::endl;
    }
    int Size(char *s)
    {
        int count=0;
        while(*s++) 
            count++;
        return count;
    }
    mystr(const mystr &c)
    {
        int n = c.sz;
        buf = new char[n];
        for (int i = 0; i < n ; i++)
        {
            buf[i] = c.buf[i]; // buf = c.buf; this will also work 
        }
        buf[n] = '\0';
        std::cout << "this->buf : "<< this->buf << std::endl; 
    }
    mystr& operator =(const mystr &a)
    {
        if(&a == this)
            return *this;
        delete buf;
        buf = new char[a.sz];
        buf = a.buf;
        std::cout << "this->buf : "<< this->buf << std::endl;
        return *this;
    }
    friend bool operator== (const mystr &obj, const mystr &obj1)
    {
       for (int i = 0; i < obj.sz ; i++)
       {
           if(obj.buf[i] != obj1.buf[i])
           {
               return false;
           }
       }
        return true;
    }
    void display()
    {
        std::cout << buf << std::endl;
    }
};
int main()
{
    mystr str2;
    mystr str("hello");
    mystr str1 = str;
    str2 = str1;
    str.display();
    str1.display();
    str2.display();
    if(str == str1)
    {
        std::cout << "==" << std::endl;
    }
    
    return 0;
}
