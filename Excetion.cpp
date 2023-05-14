#include "Excetion.h"

SharpLib::Excetion::Excetion::Excetion()
{
	_message = _T("");
}

SharpLib::Excetion::Excetion::Excetion(String message)
{
	_message = message;
}

SharpLib::String SharpLib::Excetion::Excetion::GetMessage()
{
	return _message;
}

void SharpLib::Excetion::Excetion::SetMessage(String message)
{
	_message = message;
}
