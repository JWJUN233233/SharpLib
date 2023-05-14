#pragma once
#include "Excetion.h"
#include "ICollection.h"
namespace SharpLib {
    namespace Excetion {
        class OutOfIndexExcetion : public Excetion
        {
        public:
            OutOfIndexExcetion(String message, int collectionSize, int index);
            int GetCollectionSize();
            int GetIndex();
        private:
            int _collectionSize;
            int _index;
        };
    }
}
