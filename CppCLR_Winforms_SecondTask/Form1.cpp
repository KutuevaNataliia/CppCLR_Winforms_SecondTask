#include "pch.h"
//#include "Form1.h"
//
//namespace CppCLRWinformsProjekt
////namespace CppCLR_Winforms_SecondTask
//{
//	Form1::Form1()
//	{
//		MySpisok = new TSpisok();
//	}
//
//	System::Void Form1::button1_Click(System::Object^ sender, System::EventArgs^ e)
//	{
//		System::String^ newStr = textBox1->Text;
//
//		using namespace Runtime::InteropServices;
//		const char* chars =
//			(const char*)(Marshal::StringToHGlobalAnsi(newStr)).ToPointer();
//		std::string finalStr = chars;
//		Marshal::FreeHGlobal(IntPtr((void*)chars));
//
//		TElement* newElement;
//		std::string::const_iterator it = finalStr.begin();
//		while (it != finalStr.end() && std::isdigit(*it))
//		{
//			++it;
//		}
//		if (!finalStr.empty() && it == finalStr.end())
//		{
//			TNumber* newNumber = new TNumber(std::stoi(finalStr));
//			newElement = newNumber;
//		}
//		else {
//			TString* newString = new TString(finalStr);
//			newElement = newString;
//		}
//		MySpisok->AddElement(newElement);
//	}
//}
