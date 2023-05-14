#include "OutOfIndexExcetion.h"
SharpLib::Excetion::OutOfIndexExcetion::OutOfIndexExcetion(String message, int collectionSize, int index) 
{
	SetMessage(message);
	_collectionSize = collectionSize;
	_index = index;
}

int SharpLib::Excetion::OutOfIndexExcetion::GetCollectionSize()
{
	return _collectionSize;
}

int SharpLib::Excetion::OutOfIndexExcetion::GetIndex()
{
	return _index;
}
