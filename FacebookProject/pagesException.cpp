#include "pagesException.h"


const char* pagesException::what() const
{
    switch (errorCode)
    {
    case ErrorCodePages::pageAlreadyLike:
        return "Page already liked";
    case ErrorCodePages::notFan:
        return "The user is not a fan of this page";
    default:
        return "Unknown error";
    }
}
