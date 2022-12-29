#include "FacebookException.h"


const char* FacebookException::what() const
{
    switch (errorcode)
    {
    case FacebookErrorCode::InvalidDate:
        return "Invalid date";
    case FacebookErrorCode::InvalidName:
        return "Invalid name";
    case FacebookErrorCode::InvalidValue:
        return "Invalid values";
    default:
        return "Unknown error";
    }
}