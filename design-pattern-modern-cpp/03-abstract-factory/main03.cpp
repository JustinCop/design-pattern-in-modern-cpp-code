#include "abstract-factory.h"

int main()
{
    Factory* pFactory = nullptr;
    Phone* pPhone = nullptr;
    cout << "====== China Factory ======" << endl;
    pFactory = new ChineFactory;
    pPhone = pFactory->produce_apple();
    pPhone->print_brand();
    delete pPhone;

    pPhone = pFactory->produce_xiaomi();
    pPhone->print_brand();
    delete pPhone;

    delete pFactory;
    cout << "====== US Factory ======" << endl;
    pFactory = new UsFactory;
    pPhone = pFactory->produce_apple();
    pPhone->print_brand();
    delete pPhone;

    pPhone = pFactory->produce_xiaomi();
    pPhone->print_brand();
    delete pPhone;

}