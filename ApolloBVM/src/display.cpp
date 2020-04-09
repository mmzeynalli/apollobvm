#include "display.h"

// For NHD display
Display::Display(uint8_t pin):
  _row(0),
  _col(0) {
  
  nhd = new NhdDisplay(pin);
  lcd = NULL;

}

// For LiquidCrystal Display
Display(uint8_t rs, uint8_t en, uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7):
  _row(0),
  _col(0) {

  lcd = new LiquidCrystal(rs, en, d4, d5, d6, d7);
  nhd = NULL;
}

// Start Serial connection with default baud (NHD)
void Display::begin(int baud) 
{

  if (NULL != nhd)
    _serial_ptr->begin(9600);
  else if (NULL != lcd)
    Serial.println("LCD displays need 2 arguments (width and height) instead of 1");
}

// Start screen with given rows and cols (LCD)
void Display::begin(int rows, int cols) 
{

  if (NULL != lcd)
    lcd.begin(rows, cols);
  else if (NULL != lcd)
    Serial.println("NHD displays need 1 argument (RX) instead of 2");
}

// Print string on screen
void Display::print(String st) 
{

  if (NULL != nhd)
    nhd->print(st);
  else if (NULL != lcd)
    lcd->print(st);
}

// Print value on screen
void Display::print(int val) 
{
  
  if (NULL != nhd)
    nhd->print(String(st));
  else if (NULL != lcd)
    lcd->print(String(st));
}

// Print string on screen with newline
void Display::println(String st) 
{
  
  if (NULL != nhd)
    nhd->println(String(st));
  else if (NULL != lcd)
    lcd->println(String(st));
}

// Set brightness of background (NHD)
void Display::setBacklight(byte brightness) 
{

  if (NULL != nhd)
    nhd->setBacklight();
  else if (NULL != lcd)
    Serial.println("LiquidCrystal Displays cannot set backlight brightness");
  
}

// Clear all characters from display
void Display::clearDisplay() 
{

  if (NULL != nhd)
    nhd->clearDisplay();
  else if (NULL != lcd)
    lcd->clear();
}

// Set cursor to given position
void Display::setCursor(byte col, byte row) 
{

  if (NULL != nhd)
    nhd->setCursor(col, row);
  else if (NULL != lcd)
    lcd->setCursor(col, row);
}

// Turn on underline of cursor
void Display::underlineOn() 
{
  
  if (NULL != nhd)
    nhd->underlineOn();
  else if (NULL != lcd)
    lcd->cursor();
}

// Turn off underline of cursor
void Display::underlineOff() 
{

  if (NULL != nhd)
    nhd->underlineOff();
  else if (NULL != lcd)
    lcd->noCursor();
}

// Turn on blinking of cursor
void Display::blinkingOn() 
{

  if (NULL != nhd)
    nhd->blinkingOn();
  else if (NULL != lcd)
    lcd->blink();
}

// Turn on blinking of cursor
void Display::blinkingOff() 
{

  if (NULL != nhd)
    nhd->blinkingOn();
  else if (NULL != lcd)
    lcd->noBlink();
}

// move current cursor to one right
void Display::moveCursorRight() 
{

  if (NULL != nhd)
    nhd->moveCursorRight();
  else if (NULL != lcd)
    lcd->scrollDisplayRight();
}

// move current cursor to one left
void Display::moveCursorLeft() 
{

  if (NULL != nhd)
    nhd->moveCursorLeft();
  else if (NULL != lcd)
    lcd->scrollDisplayLeft();
}

// delete previous character
void Display::backspace() 
{

  if (NULL != nhd)
    nhd->backspace();
  else if (NULL != lcd)
  {
    moveCursorLeft();
    remove();
  }
}

// remove character in current position
void Display::remove() 
{
  if (NULL != nhd)
    nhd->remove();
  else if (NULL != lcd)
    lcd->print(' ');
}

// This helper function ensures integers have 2 decimal places.
String Display::zeroPad(int in) 
{
  
  // Make a temp char array to hold the 2 digits.
  char digit[2];

  // Pad with a 0 if integer is 1 digit.
  sprintf(digit, "%02d", in);

  return String(digit);
}
