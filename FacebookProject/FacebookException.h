#include <stdexcept>
#include <string>
enum class FacebookErrorCode { InvalidDate, InvalidName,InvalidValue, ErrorOpeningFile};

class FacebookException : public std::exception
{
	FacebookErrorCode errorcode;
public:
	FacebookException(FacebookErrorCode _errorcode) : errorcode(_errorcode) {}
	FacebookErrorCode getErrorCode() const { return errorcode; }
	const char* what() const;
};
