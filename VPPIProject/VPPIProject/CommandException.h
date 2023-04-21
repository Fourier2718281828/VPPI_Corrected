#ifndef COMMAND_EXCEPTION_
#define COMMAND_EXCEPTION_
#include <exception>

class CommandException : public std::exception
{
public:
	CommandException(const char* const msg) : std::exception(msg) {}
};


#endif // !COMMAND_EXCEPTION_

