#pragma once
class ObjectPoolable
{
protected:
	virtual bool IsSatisfiedCondition() = 0;
};