#include "StatusException.h"


const char* StatusException::what() const
{
    switch (errorCode)
    {
    case ErrorCodeStatus::InvalidChoice:
        return "Invalid choice";
    default:
        return "Unknown error";
    }
}