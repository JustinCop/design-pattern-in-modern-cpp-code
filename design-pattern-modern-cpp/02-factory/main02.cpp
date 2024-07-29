#include "factory.h"

int main()
{
    Factory* pFactory = nullptr;
    Phone* pPhone = nullptr;

    pFactory = new AppleFactory;

    pPhone = pFactory->produce_phone();
    pPhone->print_brand();

    delete pPhone;
    delete pFactory;
}