#include "pch.h"
#include "TNumber.h"

int TNumber::getSomeNumber()
{
	return SomeNumber;
}

void TNumber::setSomeNumber(int value)
{
	SomeNumber = value;
}

TNumber::TNumber(int startValue)
{
	SomeNumber = startValue;
}


