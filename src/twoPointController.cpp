#include "twoPointController.hpp"

auto twoPointController::control(const int16_t current, const int16_t on, const int16_t off ) -> bool
{
    bool result = false;

    if (current <= off && mPrevState)
    {
        result = true;
        return result;
    }
    
    if (current >= off && mPrevState)
    {
        result = false;
        mPrevState = result;
        return result; 
    }

    if (current <= on && !mPrevState)
    {
        result = true;
        mPrevState = result;
    }

    return result;
}