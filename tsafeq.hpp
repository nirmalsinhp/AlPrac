#include <bits/stdc++.h>
#include <thread>
#include <condition_variable>
using namespace std;

template <typename T>
class TSQ
{
    public:

    TSQ() = default;
    TSQ(const TSQ& oth)
    {
        lock_guard<mutex> lk(oth.mx)
        dq = oth.dq;
    }

    TSQ& operator=(const TSQ& oth) = delete;
    
    size_t size()
    {
        lock_guard<mutex> lk(mx);
        return dq.size();
    }

    bool isEmpty()
    {
        lock_guard<mutex> lk(mx);
        return (dq.size() == 0);
    }

    void push(const T& val)
    {
        {
            lock_guard<mutex> lk(mx);
            dq.push(val);
        }
        cd.notify_one();
    }

    void push(T&& val)
    {
        {
            lock_guard<mutex> lk(mx);
            dq.push(move(val));
        }
        cd.notify_one();
    }

    void wait_and_pop(T& val)
    {
        unique_lock<mutex> ul(mx);
        cd.wait(ul, [](){ return !dq.empty();})
        val = dq.front();
        ul.unlock();
    }

    void try_and_pop(T& val)
    {
        if(dq.empty())
            return false;
        lock_guard<mutex> lg(mx);
        val = dq.front();
    }

    shared_ptr<T> wait_and_pop()
    {
        unique_lock<mutex> ul(mx);
        cd.wait(ul, [](){ return !dq.empty();})
        auto res = make_shared<T>(dq.front());
        ul.unlock();
        return res;
    }

    void try_and_pop(T& val)
    {
        lock_guard<mutex> lg(mx);
        if(dq.empty())
            return false;
        val = dq.front();
        dq.pop();
    }

    shared_ptr<T> try_and_pop()
    {
        lock_guard<mutex> lg(mx);
        if(dq.empty())
            return nullptr;
        auto res = make_shared<T>(dq.front());
        dq.pop();
        return res;
    }

    private:
    mutable mutex mx;
    condition_variable cd;
    queue<T> dq;
};