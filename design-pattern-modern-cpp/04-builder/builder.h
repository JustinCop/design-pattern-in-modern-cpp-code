#pragma once
#include <string>
#include <iostream>
using namespace std;

// The final product: car
class Car
{
public:
    void set_shell(string shell)
    {
        this->shell = shell;
    }
    void set_engine(string engine)
    {
        this->engine = engine;
    }
    void set_whell(string whell)
    {
        this->whell = whell;
    }
    
    string get_shell()
    {
        return this->shell;
    }
    string get_engine()
    {
        return this->engine;
    }
    string get_whell()
    {
        return this->whell;
    }
private:
    string shell;
    string engine;
    string whell;
};

// The base class of builder
class Builder
{
public:
    virtual void build_shell() = 0;
    virtual void build_engine() = 0;
    virtual void build_whell() = 0;
    virtual Car* get_car()
    {
        return m_car;
    }

protected:
    Car* m_car;

};



// Two types of builder
class TruckBuilder :public Builder
{
public:
    TruckBuilder()
    {
        m_car = new Car;
    }
    virtual void build_shell() override
    {
        m_car->set_shell("Truck's shell");
    }
    virtual void build_engine() override
    {
        m_car->set_engine("Truck's engine");
    }
    virtual void build_whell() override
    {
        m_car->set_whell("Truck's engine");
    }
};


class TrainBuilder :public Builder
{
public:
    TrainBuilder()
    {
        m_car = new Car;
    }
    virtual void build_shell() override
    {
        m_car->set_shell("Train's shell");
    }
    virtual void build_engine() override
    {
        m_car->set_engine("Train's engine");
    }
    virtual void build_whell() override
    {
        m_car->set_whell("Train's engine");
    }
};

// The director who takes charge of the builder logic
class Director
{
public:
    Director(Builder* pBuilder)
    {
        m_pBuilder = pBuilder;
    }

    // The building logic
    void build_logic()
    {
        cout << "Build shell first\t" << endl;
        m_pBuilder->build_shell();

        cout << "Build engine then\t" << endl;
        m_pBuilder->build_engine();

        cout << "Finally build whell\t" << endl;
        m_pBuilder->build_whell();
    }

private:
    Builder* m_pBuilder;
};