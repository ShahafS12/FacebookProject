#include "friendException.h"


const char* friendException::what() const
{
    switch (errorCode)
    {
    case ErrorCode::InvalidData:
        return "Invalid data";
    case ErrorCode::alreadyFriends:
        return "Users already friends";
    case ErrorCode::notFriends:
        return "User was not in friend list";
    case ErrorCode::pageNotLiked:
        return "Page not prevously liked";
    case ErrorCode::pageAlreadyLiked:
        return "Page already liked";
    case ErrorCode::selfFriend:
        return "User can't be friend with itself";
    default:
        return "Unknown error";
    }
}
