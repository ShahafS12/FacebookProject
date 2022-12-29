#include "FacebookException.h"


const char* FacebookException::what() const
{
    switch (errorcode)
    {
    case FacebookErrorCode::InvalidDate:
        return "Invalid data";
    case FacebookErrorCode::InvalidName:
        return "Users already friends";
    case FacebookErrorCode::InvalidValue:
        return "User was not in friend list";
    default:
        return "Unknown error";
    }
}