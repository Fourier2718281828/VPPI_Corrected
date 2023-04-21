#ifndef DECERIALIZE_EXCEPTION_
#define DECERIALIZE_EXCEPTION_
#include <exception>

class DecerializeException : public std::exception
{
public:
	DecerializeException(const char* const msg) : std::exception(msg) {}
};

#endif // !DECERIALIZE_EXCEPTION_
