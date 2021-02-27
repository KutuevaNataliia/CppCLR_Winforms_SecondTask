#pragma once
class TElement
{
public:
	TElement* Previous;
	TElement* Next;
	TElement();
	virtual ~TElement();
};

