#include "twopointController.hpp"

/**
 * @brief Constructor for TwoPointController
 * 
 * Initializes the controller with a setpoint and hysteresis value.
 * The controller starts in the OFF state.
 * 
 * @param setpoint The desired target value
 * @param hysteresis The difference between upper and lower switching points
 */
TwoPointController::TwoPointController(float setpoint, float hysteresis)
    : _setpoint(setpoint), _hysteresis(hysteresis), _state(false) {
}

/**
 * @brief Update the controller with a new measured value
 * 
 * The controller uses hysteresis to prevent rapid switching:
 * - If current value falls below (setpoint - hysteresis/2), output turns ON
 * - If current value rises above (setpoint + hysteresis/2), output turns OFF
 * 
 * @param currentValue The current measured value
 * @return true if output should be ON, false if output should be OFF
 */
bool TwoPointController::update(float currentValue) {
    float lowerThreshold = _setpoint - (_hysteresis / 2.0f);
    float upperThreshold = _setpoint + (_hysteresis / 2.0f);
    
    if (currentValue < lowerThreshold) {
        _state = true;  // Turn ON
    } else if (currentValue > upperThreshold) {
        _state = false; // Turn OFF
    }
    // If currentValue is between thresholds, maintain current state
    
    return _state;
}

/**
 * @brief Set a new setpoint value
 * 
 * @param setpoint The new target value
 */
void TwoPointController::setSetpoint(float setpoint) {
    _setpoint = setpoint;
}

/**
 * @brief Get the current setpoint value
 * 
 * @return The current setpoint
 */
float TwoPointController::getSetpoint() const {
    return _setpoint;
}

/**
 * @brief Set a new hysteresis value
 * 
 * @param hysteresis The new hysteresis value
 */
void TwoPointController::setHysteresis(float hysteresis) {
    _hysteresis = hysteresis;
}

/**
 * @brief Get the current hysteresis value
 * 
 * @return The current hysteresis
 */
float TwoPointController::getHysteresis() const {
    return _hysteresis;
}

/**
 * @brief Get the current output state
 * 
 * @return true if output is ON, false if output is OFF
 */
bool TwoPointController::getState() const {
    return _state;
}
