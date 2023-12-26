#include <bits/stdc++.h>

using namespace std;

struct mys
{ 
    double d = 123.212;
    vector<string> vec{"andar", "vector", "bahar", "vector"};
};

mutex mu;
condition_variable c1;
mutex mu2;
void shared_print(string msg, int id)
{
    // lock(mu, mu2);
     lock_guard<mutex> guard(mu, adopt_lock);
    // lock_guard<mutex> guard2(mu2, adopt_lock);
    //mu.lock();
    unique_lock ul(mu, defer_lock);
    unique_lock ul(mu);
 //   cout << "not locked" << endl;
    //ul.lock();
    cout << msg << " " << id << endl;
    
    ul.unlock();
    cout << "notifyin ..." << endl;
    c1.notify_one();
    //mu.unlock();
}

void shared_print2(string msg, int id)
{
 //   lock(mu, mu2);
  //  lock_guard<mutex> guard2(mu2, adopt_lock);
   // lock_guard<mutex> guard(mu, adopt_lock);
   unique_lock ul(mu);
   cout << "waiting .." << endl;
    c1.wait(ul);
    //mu.lock();
    cout << "unblocked ... " << endl;
    cout << msg << " " << id << endl;
    //mu.unlock();
    ul.unlock();
}

void f1(string msg)
{
    for(int i = 0; i < 100; ++i)
        shared_print(msg, i);
}

void f2(string msg)
{
    for(int i = 0; i > -100; --i)
        shared_print2(msg, i);
}

function<int(int, const string&, mys&)> ff = [](int n, const string& s, mys& m){ 
    cout << __PRETTY_FUNCTION__ << endl;
    cout << " passed string " << s;
    cout << " passed struct double " << m.d;
    for(const auto& sv : m.vec)
        cout << sv << ", ";
    cout << endl;
    cout << " to thread " << this_thread::get_id() << endl;
    return n * n; };

int main()
{
 
 {
    thread a([](){
            cout << "sleeping" << endl;
            this_thread::sleep_for(std::chrono::seconds(5));
            cout << "woke" << endl; });
    cout << "main thread" << endl;
    a.join();
    cout << "returning" << endl;

    return 0;
 }
    mys ms;
    //ms.d = 12;
    //ms.vec = {"12", "23"};
    string s1 = "Nirmal";
    thread t4;
    thread tf(ff, 2, s1, ref(ms));
     thread tf2(ff, 44, string("this is threadddd"), ref(ms));
//    thread t1(f1, "thread 1");
 //   thread t2(f2, "thread 2");
    // for(int i = 1000; i < 1500; ++i)
    //     shared_print("from main :", i);
    //cout <<  "t1 : " << t1.get_id() << endl;
    //cout <<  "t2 : " << t2.get_id() << endl;
    cout << "HWC : " <<     thread::hardware_concurrency() << endl;
    cout << "main tid : " <<     this_thread::get_id() << endl;

    tf.join();
    tf2.join();

   // t1.join();
    //t2.join();

    return 0;
}