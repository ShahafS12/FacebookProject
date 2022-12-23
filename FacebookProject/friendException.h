#include <stdexcept>
#include <string>


enum class ErrorCode {InvalidData,alreadyFriends,notFriends,pageNotLiked,pageAlreadyLiked, selfFriend};

class friendException : public std::exception
{
	ErrorCode errorCode;
public:
	friendException(ErrorCode errorCode) : errorCode(errorCode) {}
	ErrorCode getErrorCode() const { return errorCode; }
	const char* what() const;
};