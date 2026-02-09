#pragma once

#include <Arduino.h>

class twoPointController 
{
    private:
    bool mPrevState;

    public: 

    auto control(const int16_t current, const int16_t on, const int16_t off ) -> bool;

};