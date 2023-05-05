#include "Stream.h"
#include<iostream>
#pragma once
namespace SharpLib::IO {
	SharpLib::IO::MemoryStream::MemoryStream()
	{
		_buffer = new Array<byte>();
		_postion = 0;
		_isDisposed = false;
	}
	MemoryStream::~MemoryStream()
	{

	}
	void MemoryStream::Close()
	{
		delete _buffer;
		_postion = null;
		_isDisposed = true;
	}
	void MemoryStream::Flush()
	{
		_buffer->SetLength(0);
	}
	bool MemoryStream::GetCanRead()
	{
		return true;
	}
	int MemoryStream::ReadByte()
	{
		byte tmp = _buffer->operator[](_postion);
		_postion++;
		return tmp;
	}
	int MemoryStream::Read(Array<byte>* buffer, int offset, int count)
	{
		int readedLen = 0;
		for (int i = 0; i < count;i++) {
			if (_postion < GetLength()) {
				(*buffer)[offset + i] = _buffer->operator[](_postion);
				readedLen++;
				_postion++;
			}
		}
		return readedLen;
	}
	bool MemoryStream::GetCanSeek()
	{
		return true;
	}
	int MemoryStream::Seek(int offset, SeekOrigin origin)
	{
		return 0;
	}
	bool MemoryStream::GetCanWrite()
	{
		return true;
	}
	void MemoryStream::WriteByte(byte value)
	{
		_buffer->SetLength(_postion + 1);
		_buffer->operator[](_postion) = value;
		_postion++;
	}
	void MemoryStream::Write(Array<byte> buffer, int offset, int count)
	{

	}
	int MemoryStream::GetLength()
	{
		return _buffer->GetLength();
	}
	void MemoryStream::SetLength(int value)
	{
		_buffer->SetLength(value);
	}
	int MemoryStream::GetPostion()
	{
		return _postion;
	}
	void MemoryStream::SetPostion(int postion)
	{
		_postion = postion;
	}
	void MemoryStream::Dispose()
	{
		Close();
	}
	Array<byte> MemoryStream::ToArray()
	{
		return *_buffer;
	}
}