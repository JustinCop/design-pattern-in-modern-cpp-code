#pragma once
#include <iostream>

using namespace std;

class Phone
{
public:
    virtual void print_brand() = 0;
};

// Each type of phone has different mutation
// Apple
class UsApple :public Phone
{
public:
    virtual void print_brand() override
    {
        cout << "US Apple phone" << endl;
    }
};

class CnApple : public Phone
{
public:
    virtual void print_brand() override
    {
        cout << "CN Apple phone" << endl;
    }
};
// Xiaomi
class UsXiaomi :public Phone
{
public:
    virtual void print_brand() override
    {
        cout << "US Xiaomi phone" << endl;
    }
};

class CnXiaomi :public Phone
{
public:
    virtual void print_brand() override
    {
        cout << "CN Xiaomi phone" << endl;
    }
};


// Multi-dimension
//
// --------------------------
// |          |  CN  |  US  |
// |  Apple   |      |      |
// |  Xiaomi  |      |      |



class Factory
{
public:
    // factory: Add factory for each specific phone
    virtual Phone* produce_apple() = 0;
    virtual Phone* produce_xiaomi() = 0;
};

// when new country added, add a new factory
class UsFactory :public Factory
{
public:
    virtual Phone* produce_apple() override
    {
        return new UsApple;
    }
    virtual Phone* produce_xiaomi() override
    {
        return new UsXiaomi;
    }
};

class ChineFactory : public Factory
{
    virtual Phone* produce_apple() override
    {
        return new CnApple;
    }
    virtual Phone* produce_xiaomi() override
    {
        return new CnXiaomi;
    }
};


//// Additionally, we can switch the dimension
//class Factory
//{
//public:
//    // factory: Add factory for each specific phone
//    virtual Phone* produce_CN_phone() = 0;
//    virtual Phone* produce_US_phone() = 0;
//};
//
//// when new phone added (e.g. samesung), add a factory
//class AppleFactory :public Factory
//{
//public:
//    virtual Phone* produce_CN_phone() override
//    {
//        return new CnApple;
//    }
//    virtual Phone* produce_US_phone() override
//    {
//        return new UsApple;
//    }
//};
//
//class XiaomiFactory :public Factory
//{
//    virtual Phone* produce_CN_phone() override
//    {
//        return new CnXiaomi;
//    }
//
//    virtual Phone* produce_US_phone() override
//    {
//        return new UsXiaomi;
//    }
//};