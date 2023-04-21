#ifndef INVALID_CAST_EXCEPTION_
#define INVALID_CAST_EXCEPTION_
#include <exception>

class InvalidCastException : public std::exception
{
public:
	InvalidCastException(const char* const msg) : std::exception(msg) {}
};

#endif // !INVALID_CAST_EXCEPTION_



