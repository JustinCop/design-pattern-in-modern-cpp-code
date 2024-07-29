#pragma once
#include <iostream>

using namespace std;

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

// factory: Add factory for each specific phone
class Factory
{
public:
    virtual Phone* produce_phone() = 0;
};

class AppleFactory :public Factory
{
public:
    virtual Phone* produce_phone() override
    {
        return new Apple;
    }
};

class XiaomiFactory :public Factory
{
    virtual Phone* produce_phone() override
    {
        return new Xiaomi;
    }
};