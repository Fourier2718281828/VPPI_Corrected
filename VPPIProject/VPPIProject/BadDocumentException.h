#pragma once
#ifndef BAD_DOC_EXCEPTION_
#define BAD_DOC_EXCEPTION_
#include <exception>

class BadDocumentException : public std::exception
{
public:
	BadDocumentException(const char* const msg) : std::exception(msg) {}
};

#endif // !BAD_DOC_EXCEPTION_



