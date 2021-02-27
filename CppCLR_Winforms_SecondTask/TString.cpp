#include "pch.h"
#include "TString.h"

std::string TString::getSomeString()
{
	return SomeString;
}

void TString::setSomeString(std::string value)
{
	SomeString = value;
}

TString::TString(std::string startString)
{
	SomeString = startString;
}