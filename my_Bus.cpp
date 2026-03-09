#include "my_Bus.h"

int my_Bus::updateBus(int& Data)
{
    this->Data = Data;
    return this->Data;
}

int my_Bus::getBusData()
{
    return this->Data;
}
