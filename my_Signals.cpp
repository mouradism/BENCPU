#include "my_Signals.h"

int my_Signals::updateSignals(int& Data)
{
    this->Data = Data;
    return this->Data;
}

int my_Signals::getSignalsData()
{
    return this->Data;
}
