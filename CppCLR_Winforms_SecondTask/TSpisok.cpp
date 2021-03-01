#include "pch.h"
#include "TSpisok.h"

void TSpisok::AddElement(TElement* someElement)
{
	someElement->Previous = Last;
	someElement->Next = nullptr;	
	if (First == nullptr)
	{
		Last = someElement;
		First = Last;
		First->Previous = nullptr;
		First->Next = nullptr;
		Last->Previous = nullptr;
		Last->Next = nullptr;
	}
	else {
		Last->Next = someElement;
		Last = someElement;
	}
}

void TSpisok::DeleteElement(TElement* someElement)
{
	if (someElement == First)
	{
		First = someElement->Next;
	}
	else {
		someElement->Previous->Next = someElement->Next;
	}		
	if (someElement == Last)
	{
		Last = someElement->Previous;
	}
	else
	{
		someElement->Next->Previous = someElement->Previous;
	}	
	delete someElement;
}

void TSpisok::Output(bool direct, System::Windows::Forms::ListBox^ list)
{
	list->Items->Clear();
	if (direct)
	{
		Current = First;
		while (Current != nullptr)
		{
			std::string tempStr = "";
			if (TNumber* givenNumber = dynamic_cast<TNumber*>(Current))
			{
				tempStr = std::to_string(givenNumber->PSomeNumber);
			}
			else if (TString* givenStr = dynamic_cast<TString*>(Current))
			{
				tempStr = givenStr->PSomeString;
			}
			System::String^ finalStr = gcnew System::String(tempStr.c_str());
			list->Items->Add(finalStr);
			Current = Current->Next;
		}
	}
	else {
		Current = Last;
		while (Current != nullptr)
		{
			std::string tempStr = "";
			if (TNumber* givenNumber = dynamic_cast<TNumber*>(Current))
			{
				tempStr = std::to_string(givenNumber->PSomeNumber);
			}
			else if (TString* givenStr = dynamic_cast<TString*>(Current))
			{
				tempStr = givenStr->PSomeString;
			}
			System::String^ finalStr = gcnew System::String(tempStr.c_str());
			list->Items->Add(finalStr);
			Current = Current->Previous;
		}
	}
}

void TSpisok::Sum(System::Windows::Forms::TextBox^ textNumber, System::Windows::Forms::TextBox^ textString)
{
	int sum = 0;
	std::string str = "";
	Current = First;
	while (Current != nullptr)
	{
		if (TNumber* number = dynamic_cast<TNumber*>(Current))
		{
			sum += number->PSomeNumber;
		}
		else if (TString* s = dynamic_cast<TString*>(Current))
		{
			str += s->PSomeString + ' ';
		}
		Current = Current->Next;
	}
	System::String^ finalStr = gcnew System::String(str.c_str());
	textString->Text = finalStr;
	System::String^ finalNumber = gcnew System::String((std::to_string(sum)).c_str());
	textNumber->Text = finalNumber;
}

TSpisok::TSpisok()
{
	First = nullptr;
	Last = nullptr;
	Current = nullptr;
}

TSpisok::~TSpisok()
{
	if (First != nullptr)
	{
		while (First->Next != nullptr)
		{
			DeleteElement(First->Next);
		}
		DeleteElement(First);
	}
}