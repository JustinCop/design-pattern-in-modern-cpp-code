// https://bbs.huaweicloud.com/blogs/397606

#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std;

class SingletonPattern
{
public:
    static SingletonPattern* GetInstance()
    {
        lock_guard<mutex> guard(mux);
        if (m_pInstance == nullptr)
        {
            m_pInstance = new SingletonPattern;
        }
        return m_pInstance;
    }

    static int GetCount() { return count; }

private:
    SingletonPattern() 
    {
        count++;
        
        this_thread::sleep_for(chrono::seconds(2)); 

        cout << "private constructor" << endl;
    }
    static SingletonPattern* m_pInstance;
    static int count;
    static mutex mux;
};
int SingletonPattern::count = 0;
//// 1. lazy singleton: create the instance when first used.
// problem: will create multiple instance when multi-thread is used.
//SingletonPattern* SingletonPattern::m_pInstance = nullptr;

//// 2. hungry singleton: create the instance at the begining.
//SingletonPattern* SingletonPattern::m_pInstance = SingletonPattern::GetInstance();

// 3. Use mutex for lazy mode.
mutex SingletonPattern::mux;
SingletonPattern* SingletonPattern::m_pInstance = nullptr;

int main()
{
    SingletonPattern* p1;
    SingletonPattern* p2;

    thread t1([&p1] { p1 = SingletonPattern::GetInstance(); });
    thread t2([&p2] { p2 = SingletonPattern::GetInstance(); });
    
    t1.join();
    t2.join();

    cout << p1 << endl;
    cout << p2 << endl;

    cout << SingletonPattern::GetCount();

    return 0;
}