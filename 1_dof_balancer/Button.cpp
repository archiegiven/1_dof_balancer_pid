/**
 * Button.h
 * 
 * This is a simple library to implement a push button
 * Implemented as object-oriented to practice building libraries for more complex hardware
 * 
 * @author Archibald Given (linkedin.com/archie-given)
 * @copyright 2024 Archibald Given
 */


#ifndef BUTTON_H
#define BUTTON_H

#include <Arduino.h>

/**
 * @class Button
 * @brief Simple library for a push button
 */
class Button {
public:
    /**
     * @brief Constructor to initialize button
     * @param pin the input pin the button is attached to
     * @param type input type for button, defaults to INPUT, can also specify INPUT_PULLUP to use a pullup resistor input, or INPUT_PULLDOWN to use a pulldown resistor input
     */
    Button(uint8_t pin, int type);

    /**
     * @brief Attach an interrupt to the button press
     * @param mode mode for the interrupt (RISING, FALLING, CHANGE)
     */
    void attachToggledInterrupt(int mode);

    /**
     * @brief Returns the state of the button, initial state is false
     */
    byte getToggledState();

    /**
     * @brief ISR handler
     */
    static void handleInterrupt();

private:
    uint8_t _pin; ///< The pin number for the button
    byte _toggledState; ///< To toggle the state to turn button on or off
    unsigned long _debounceDuration; ///< Minimum debounce period in millis
    unsigned long _lastTimeStateChanged; ///< Last time button state changed in millis

    static Button* _instance; ///< Static instance pointer for ISR access
    void buttonToggleInterrupt(); ///< Actual interrupt handling function
};

#endif
