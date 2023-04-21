#ifndef ISERIALIZER_
#define ISERIALIZER_
#include "ISerializable.h"
#include <fstream>

class ISerializer
{
public:
	template<typename T>
	using ptr = ISerializable::ptr<T>;
public:
	virtual void serialize(std::ofstream&, const ISerializable&) const = 0;
	virtual ptr<ISerializable> deserialize(std::ifstream&) = 0;
};

#endif // !ISERIALIZER_
