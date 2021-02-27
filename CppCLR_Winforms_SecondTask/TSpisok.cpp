#include "pch.h"
#include "TSpisok.h"

void TSpisok::AddElement(TElement* someElement)
{
	someElement->Previous = Last;
	someElement->Next = nullptr;
	Last = someElement;
}

void TSpisok::DeleteElement(TElement* someElement)
{
	if (someElement == First && someElement == Last)
	{
		First = nullptr;
		Last = nullptr;
	}
	else {
		if (someElement == First)
		{
			First = someElement->Next;
			someElement->Next->Previous = nullptr;
		}
		else {
			someElement->Previous->Next = someElement->Next;
			if (someElement == Last)
			{
				Last = someElement->Previous;
			}
			else
			{
				someElement->Next->Previous = someElement->Previous;
			}
		}
	}	
	delete someElement;
}

void TSpisok::Output(bool direct, System::Windows::Forms::ListBox^ list)
{
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
	list->Update();
}

TSpisok::TSpisok()
{
	First = nullptr;
	Last = nullptr;
	Current = nullptr;
}

TSpisok::~TSpisok()
{
	Current = First;
	while (Current != nullptr)
	{
		DeleteElement(Current);
		Current = Current->Next;
	}
}