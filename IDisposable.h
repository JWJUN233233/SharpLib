#pragma once
namespace SharpLib 
{
	class IDisposable
	{
	public:
		virtual void Dispose() = 0;
	};
}
