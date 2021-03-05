********************************************************************************************************************
Question no-1: producer-consumer 
***********************************************************************************************************************/
#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
#include <chrono>
#include<vector>
using namespace std;
mutex mtx;
condition_variable cVar;
vector<int>v;
int buffer = 50;
bool flag = false;
void producer(int var)
{
	while(var)
	{
		unique_lock<mutex>lck(mtx);
		cVar.wait(lck,[](){return v.size() < buffer;})
		v.push_back(var);
		cout<<" "<<var--;
		cVar.unlock();
		cVar.notify_one();
	}	

}
void consumer()
{
	while(true)
	{
		unique_lock<mutex>lck(mtx);
		cVar.wait(lck,[](){return v.size() > 0;})
		int v = v.back();
		v.pop_back();
		cout<<"var consumed "<< v <<endl;
		lck.unlock();
		cVar.notify_one();
	}
}
int main()
{
	thread t(producer, 10);
	thread t1(consumer);
	t.join();
	t1.join();
	return 0;
}

