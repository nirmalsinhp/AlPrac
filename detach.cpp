#include <bits/stdc++.h>
#include <iostream>
#include <chrono>
#include <thread>
 
int independentThread() 
{
    std::cout << "Starting concurrent thread.\n";
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout << "Exiting concurrent thread.\n";
    return 1;
}
 
void threadCaller() 
{
    using namespace std::literals;
    std::cout << "Starting thread caller.\n";
    std::thread t(independentThread);
    t.detach();
    std::this_thread::sleep_for(1s);
    std::cout << "Exiting thread caller.\n";
}
 
int main() 
{
    threadCaller();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    using namespace std;
    auto fut = async(launch::deferred,   [](){ cout << " thread deferred :" << this_thread::get_id() << endl;
                                                return this_thread::get_id(); });
    
    cout << "main t : " << this_thread::get_id() << endl;
    auto ttid = fut.get();
    auto fut1 = async([](){ cout << " thread default :" << this_thread::get_id() << endl;
                                                return this_thread::get_id(); });
    
    auto ttid1 = fut1.get();

    auto fut2 = async(launch::async, [](){ cout << " thread async :" << this_thread::get_id() << endl;
                                                return this_thread::get_id(); });
    
    auto ttid2 = fut2.get();

    thread t11([](){cout << "11" << endl;});
    t11.join();
    // t11.join(); calling join again is UB, throws exception in this case. calls terminate
    atomic<int> ix(0);
    atomic<double> id(1.1);
    ix = ix + 1;
    ix = ix * 2;
    //id.notify_all()
    // id = id++; no operations
    cout << ix << endl;
    vector<int> vecv{1,2,2,3};
    auto vecm = move(vecv);
    cout << vecv.empty() << endl;
    vecv.push_back(2);
    cout << vecv.empty() << endl;

    return 0;

}