/********************************************************************************************************************
       multithreading: 
**********************************************************************************************************************/
/********************************************************************************************************************
Question no-1: odd even in sequence 
***********************************************************************************************************************/
#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
#include <chrono>
using namespace std;
mutex mtx;
condition_variable cVar;
int var = 0;
void even()
{
	for(int i=0; i<10; i++)
	{
		if(var%2==0)
		{
		    //std::this_thread::sleep_for (std::chrono::seconds(1));
			this_thread::sleep_for(chrono::milliseconds(10));
			unique_lock<mutex>lck(mtx);
			cout<<var<<endl;
			cVar.notify_one();
						
		}var++;
	}

}
void odd()
{
	for(int i=0; i<10; i++)
	{
		if(var%2==1)
		{
			unique_lock<mutex>lck(mtx);
			cVar.wait(lck);
			cout<<var<<endl;
						
		}var++;
	}
}
int main()
{
	thread t(even);
	thread t1(odd);
	t.join();
	t1.join();
	return 0;
}
