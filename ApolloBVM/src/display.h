#ifndef display_h
#define display_h 

#include "Arduino.h"
#include "SoftwareSerial.h"
#include <LiquidCrystal.h>
#include "nhd_0420d3z.h"

#include <stdint.h>

class Display {

  public:
    Display(uint8_t pin);  // NHD
    Display(uint8_t rs, uint8_t en, uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7);  // LCD

    void begin(int baud); // NHD
    void begin(int rows, int cols); // LCD

    // Methods for printing.
    void print(String st);
    void print(int val);
    void println(String st);
    
    // Methods for display adjustments.
    void setBacklight(uint8_t brightness);
    void clearDisplay();
    void setCursor(uint8_t cursor_position, uint8_t line);

    // Methods for underline.
    void underlineOn();
    void underlineOff();

    // Methods for blinking.
    void blinkingOn();
    void blinkingOff();

    // Methods for single character shifting.
    void moveCursorRight();
    void moveCursorLeft();

    // Methods for deleting characters.
    void backspace();
    void remove();

    // Helper function to pad integers to 2 digits.
    String zeroPad(int in);

  private:

    // Pointer to serial interface.
    NhdDisplay* nhd;
    LiquidCrystal* lcd;

    // Current row and column of the cursor.
    uint8_t _row;
    uint8_t _col;
};


#endif
