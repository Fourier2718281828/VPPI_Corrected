#ifndef ISERIALIZABLE_
#define ISERIALIZABLE_
#include <fstream>
#include <memory>

class ISerializable
{
public:
	template<typename T>
	using ptr = std::unique_ptr<T>;
public:
	virtual ~ISerializable() = default;
public:
	virtual void serialize(std::ofstream&) const = 0;
	virtual void deserialize(std::ifstream&) = 0;
};

#endif // !ISERIALIZABLE_
