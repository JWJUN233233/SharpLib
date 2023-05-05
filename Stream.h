#pragma once
#include "IDisposable.h"
#include "Array.h"
#include "types.h"
using SharpLib::Collection::Array;
namespace SharpLib::IO {
	enum SeekOrigin
	{
		Begin,
		Current,
		End
	};
	class Stream : public IDisposable
	{
	public:
		Stream() {}
		virtual void Close() = 0;
		virtual void Flush() = 0;
		virtual bool GetCanRead() = 0;
		virtual int ReadByte() = 0;
		virtual int Read(Array<byte>* buffer, int offset, int count) = 0;
		virtual bool GetCanSeek() = 0;
		virtual int Seek(int offset, SeekOrigin origin) = 0;
		virtual bool GetCanWrite() = 0;
		virtual void WriteByte(byte value) = 0;
		virtual void Write(Array<byte> buffer, int offset, int count) = 0;
		virtual int GetLength() = 0;
		virtual void SetLength(int value) = 0;
		virtual int GetPostion() = 0;
		virtual void SetPostion(int postion) = 0;
	};
	class MemoryStream : public Stream
	{
	public:
		MemoryStream();
		~MemoryStream();
		void Close();
		void Flush();
		bool GetCanRead();
		int ReadByte();
		int Read(Array<byte>* buffer, int offset, int count);
		bool GetCanSeek();
		int Seek(int offset, SeekOrigin origin);
		bool GetCanWrite();
		void WriteByte(byte value);
		void Write(Array<byte> buffer, int offset, int count);
		int GetLength();
		void SetLength(int value);
		int GetPostion();
		void SetPostion(int postion);
		void Dispose();
		Array<byte> ToArray();
	private:
		Array<byte>* _buffer;
		int _postion;
		bool _isDisposed;
	};
}
