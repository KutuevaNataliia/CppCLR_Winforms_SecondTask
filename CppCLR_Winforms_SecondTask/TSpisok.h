#pragma once
//#include "TElement.h"
#include "TNumber.h"
#include "TString.h"
#include <string>


class TSpisok
{
public:
	TElement* First;
	TElement* Last;
	TElement* Current;
	void AddElement(TElement* someElement);
	void DeleteElement(TElement* someElement);
	void Output(bool direct, System::Windows::Forms::ListBox^ list);
	TSpisok();
	~TSpisok();
};

