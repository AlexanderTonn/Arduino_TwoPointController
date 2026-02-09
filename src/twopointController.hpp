#ifndef TWOPOINT_CONTROLLER_HPP
#define TWOPOINT_CONTROLLER_HPP

/**
 * @brief Two-Point Controller Class
 * 
 * A simple on-off controller that switches between two states based on
 * upper and lower thresholds around a setpoint.
 */
class TwoPointController {
public:
    /**
     * @brief Constructor for TwoPointController
     * 
     * @param setpoint The desired target value
     * @param hysteresis The difference between upper and lower switching points
     */
    TwoPointController(float setpoint, float hysteresis);
    
    /**
     * @brief Update the controller with a new measured value
     * 
     * @param currentValue The current measured value
     * @return true if output should be ON, false if output should be OFF
     */
    bool update(float currentValue);
    
    /**
     * @brief Set a new setpoint value
     * 
     * @param setpoint The new target value
     */
    void setSetpoint(float setpoint);
    
    /**
     * @brief Get the current setpoint value
     * 
     * @return The current setpoint
     */
    float getSetpoint() const;
    
    /**
     * @brief Set a new hysteresis value
     * 
     * @param hysteresis The new hysteresis value
     */
    void setHysteresis(float hysteresis);
    
    /**
     * @brief Get the current hysteresis value
     * 
     * @return The current hysteresis
     */
    float getHysteresis() const;
    
    /**
     * @brief Get the current output state
     * 
     * @return true if output is ON, false if output is OFF
     */
    bool getState() const;

private:
    float _setpoint;      // Target value
    float _hysteresis;    // Hysteresis band
    bool _state;          // Current output state (true = ON, false = OFF)
};

#endif // TWOPOINT_CONTROLLER_HPP
