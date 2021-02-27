#pragma once
#include "TElement.h"

class TNumber :
    public TElement
{
private:
    int SomeNumber;
    
public:
    int getSomeNumber();
    void setSomeNumber(int value);
    _declspec(property(get = getSomeNumber, put = setSomeNumber)) int PSomeNumber;
    TNumber(int startValue);
};

