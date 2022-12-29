#include <stdexcept>
#include <string>


enum class ErrorCodePages { pageAlreadyLike, notFan };

class pagesException : public std::exception
{
	ErrorCodePages errorCode;
public:
	pagesException(ErrorCodePages errorCode) : errorCode(errorCode) {}
	ErrorCodePages getErrorCode() const { return errorCode; }
	const char* what() const;
};