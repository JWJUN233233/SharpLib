#pragma once
#include "types.h"
#include "String.h"
namespace SharpLib {
	namespace Excetion {
		class Excetion
		{
		public:
			Excetion();
			Excetion(String message);
			String GetMessage();
		private:
			String _message;
		protected:
			void SetMessage(String message);
		};
	}
}
