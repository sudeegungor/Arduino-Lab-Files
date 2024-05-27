#include <LiquidCrystal.h>

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
byte turkishChars[][8] = {
  { B00100, B01110, B00100, B01110, B10101, B00100, B00100, B00000 }, // Ç
  { B00100, B01110, B00100, B01110, B00100, B01110, B00100, B00000 }, // Ş
  { B00000, B01110, B10001, B10001, B11111, B10001, B10001, B11111 }, // Ğ
  { B01110, B10001, B10001, B11111, B10001, B10001, B10001, B00000 }, // İ
  { B00100, B01110, B00100, B00100, B00100, B00100, B01110, B00000 }, // Ö
  { B00000, B00101, B01110, B00100, B00100, B01110, B00101, B00000 }, // Ü
};

String LCD_ROW_1 = "This text is for row 0 and longer than 16 characters.";
String LCD_ROW_2 = "ABCD EFGH";

boolean SCROLL_FLAG = true;

char SCROLL_DIRECTION = 'L';

int SCROLL_WAIT = 1000;

void setup() {
  lcd.begin(16, 2);
   // Load custom characters
    for(int i = 0; i < 6; i++) {
    lcd.createChar(i, turkishChars[i]);
  }  
  lcd.clear(); // clear the LCD screen
}

void loop() {
  static int j = 0;
  static int k = 0;

  // Clear the LCD every SCROLL_WAIT milliseconds
  if (millis() % SCROLL_WAIT == 0) {
    lcd.clear();
    scrollText(LCD_ROW_1, j, 0);
    scrollText(LCD_ROW_2, k, 1);
    updateScrollIndex(j, LCD_ROW_1.length());
    updateScrollIndex(k, LCD_ROW_2.length());
  }
}

 

// Function to scroll text
void scrollText(String text, int &scrollIndex, int row) {
  if (text.length() > 16) {
    for (int i = 0; i < 16; i++) {
     lcd.setCursor(i, row);
          if((i+scrollIndex)>0)
          {
            lcd.print(text.charAt((i + scrollIndex) % text.length()));
          }
          else lcd.print(text.charAt((text.length()+(i + scrollIndex)) % text.length()));
    }
  } else {
    for (int i = 0; i < text.length(); i++) {
      if((i-scrollIndex)>0)lcd.setCursor((i - scrollIndex) % 16, row);
          else lcd.setCursor((16+(i - scrollIndex)) % 16, row);
          lcd.print(text.charAt(i));
    }
  }
}

// Function to update scroll index
void updateScrollIndex(int &scrollIndex, int textLength) {
  if (SCROLL_FLAG) {
    if (SCROLL_DIRECTION == 'L') {
      scrollIndex++;
      
    } else {
      scrollIndex--;
      if (scrollIndex < 0) {
       scrollIndex = textLength - 1;
     }
    }
    if (textLength < 16 && scrollIndex >= 16) {
        scrollIndex = 0;
      }
  }
}
