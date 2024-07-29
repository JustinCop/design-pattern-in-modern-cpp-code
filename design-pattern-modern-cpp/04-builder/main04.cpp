#include "builder.h"

int main()
{
    Car* myCar = nullptr;
    Builder* myBuilder = nullptr;
    Director* carDirector = nullptr;

    // If the customer want's different type of car, just switch the builder
    //myBuilder = new TruckBuilder;
    myBuilder = new TrainBuilder;
    
    carDirector = new Director(myBuilder);
    // start building
    carDirector->build_logic();

    myCar = myBuilder->get_car();

    cout << "====== car info ======" << endl;
    cout << myCar->get_shell() << endl;
    cout << myCar->get_engine() << endl;
    cout << myCar->get_whell() << endl;
    cout << "======================" << endl;

    delete myCar;
    delete carDirector;
    delete myBuilder;
}

