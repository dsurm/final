#pragma once
#include "Iterator.h"
#include "Cluster.h"
template<class Type>
class Decorator :
    public Iterator<Type>
{
protected:
    Iterator<Type>* It;
public:
    Decorator(Iterator<Type>* it) {
        It = it;
    }
    virtual void First() { It->First(); }
    virtual void Next() { It->Next(); }
	virtual bool IsDone() const { return It->IsDone(); }
	virtual Type GetCurrent() { return It->GetCurrent(); }
	~Decorator() { delete It; }
};
