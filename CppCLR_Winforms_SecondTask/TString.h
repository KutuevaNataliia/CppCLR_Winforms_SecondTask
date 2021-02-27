#pragma once
#include "TElement.h"
#include <string>

class TString :
    public TElement
{
private:
    std::string SomeString;
public:
    std::string getSomeString();
    void setSomeString(std::string value);
    _declspec(property(get = getSomeString, put = setSomeString)) int PSomeString;
    TString(std::string startString);
};

