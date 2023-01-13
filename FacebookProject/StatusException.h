#include <stdexcept>
#include <string>


enum class ErrorCodeStatus { InvalidChoice};

class StatusException : public std::exception
{
	ErrorCodeStatus errorCode;
public:
	StatusException(ErrorCodeStatus errorCode) : errorCode(errorCode) {}
	ErrorCodeStatus getErrorCode() const { return errorCode; }
	const char* what() const;
};