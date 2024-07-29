#pragma once
#include <iostream>

using namespace std;

// 1. simple factory
class Phone
{
public:
    virtual void print_brand() = 0;
};

class Apple :public Phone
{
public:
    virtual void print_brand() override
    {
        cout << "Apple phone" << endl;
    }
};

class Xiaomi :public Phone
{
public:
    virtual void print_brand() override
    {
        cout << "Xiaomi phone" << endl;
    }
};

// simple factory: need to modify the Factory code when new phone type added.
class Factory
{
public:
    Phone* produce_phone(int flag)
    {
        Phone* pPhone = nullptr;
        switch (flag)
        {
        case 1:
            pPhone = new Apple;
            break;
        case 2:
            pPhone = new Xiaomi;
            break;
        default:
            pPhone = nullptr;
            break;
        }
        return pPhone;
    }
};
