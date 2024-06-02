#include "Iterator.h"
#include "FAT16.h"
//---------------------------------------------------------------------------

#ifndef FAT16IteratorH
#define FAT16IteratorH
#endif
//---------------------------------------------------------------------------

class FAT16Iterator :
    public Iterator<Cluster>
{
private:
	FS* fat16;
    unsigned int Count;
    unsigned int Cursor;
public:
    FAT16Iterator(FS* fsItem) :Iterator(fsItem->ClusterCount()) {
        fat16 = fsItem;
        Count = fat16->ClusterCount();
        Cursor = 0;
    }
    void First() { Cursor = 0; }
    void Next() { Cursor++; }
    bool IsDone() const { return (Cursor >= Count); }
    Cluster GetCurrent();
};
