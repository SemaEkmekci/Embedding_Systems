#include <Wire.h> 
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_RESET    -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Image2cpp kullanarak oluşturduğunuz bitmap dizisi burada olacak
const unsigned char school_logo [] PROGMEM = {
	// 'Yuvarlak Logo, 64x63px
	0x0c, 0x00, 0x00, 0x7f, 0xfe, 0x00, 0x00, 0x36, 0x06, 0x80, 0x03, 0xff, 0xff, 0xc0, 0x00, 0x68, 
	0x03, 0x00, 0x1f, 0xf0, 0x1f, 0xf8, 0x00, 0xc8, 0x80, 0x00, 0x7f, 0x00, 0x00, 0xfe, 0x00, 0x38, 
	0xe0, 0x01, 0xf8, 0x00, 0x00, 0x1f, 0x80, 0x00, 0x30, 0x03, 0xe0, 0x00, 0x00, 0x07, 0xc0, 0x00, 
	0x80, 0x0f, 0x80, 0x00, 0x00, 0x01, 0xe0, 0x07, 0x80, 0x1e, 0x00, 0x01, 0x80, 0x00, 0x78, 0x00, 
	0x80, 0x3c, 0x00, 0x03, 0xc0, 0x00, 0x3c, 0x00, 0x00, 0x78, 0x00, 0x0f, 0xf0, 0x00, 0x1e, 0x00, 
	0x00, 0xf0, 0x00, 0x1e, 0x78, 0x00, 0x0f, 0x00, 0x01, 0xe0, 0x00, 0x3c, 0x3c, 0x00, 0x07, 0x80, 
	0x01, 0xc0, 0x00, 0xf9, 0x9f, 0x00, 0x03, 0x80, 0x03, 0x80, 0x01, 0xe3, 0xc7, 0x80, 0x01, 0xc0, 
	0x07, 0x00, 0x03, 0xcf, 0xf3, 0xc0, 0x00, 0xe0, 0x0e, 0x00, 0x03, 0x9e, 0x79, 0xc0, 0x00, 0x60, 
	0x0e, 0x00, 0x03, 0x3c, 0x3d, 0xc0, 0x00, 0x70, 0x1c, 0x00, 0x7f, 0x38, 0x1c, 0xfe, 0x00, 0x38, 
	0x1c, 0x00, 0xff, 0x38, 0x1c, 0xff, 0x00, 0x38, 0x38, 0x01, 0xff, 0xfe, 0x7c, 0xff, 0x80, 0x18, 
	0x38, 0x07, 0xc0, 0x7f, 0xfe, 0xc3, 0xe0, 0x1c, 0x30, 0x0f, 0x1e, 0x07, 0xe6, 0xf8, 0xf0, 0x0c, 
	0x70, 0x3e, 0x7f, 0xe3, 0xc6, 0xfe, 0x7c, 0x0c, 0x70, 0x78, 0xff, 0xf3, 0xce, 0xff, 0x3e, 0x0e, 
	0x60, 0x73, 0xe6, 0x7b, 0xce, 0xe7, 0x8e, 0x0e, 0x60, 0x73, 0xc6, 0x3f, 0xcc, 0xe3, 0xce, 0x06, 
	0xe0, 0x33, 0x87, 0x87, 0xc9, 0xe1, 0xcc, 0x06, 0xe0, 0x3b, 0x83, 0xf0, 0x4f, 0xc1, 0xdc, 0x07, 
	0xe0, 0x3b, 0x87, 0xfe, 0xcf, 0xe1, 0x9c, 0x07, 0xe0, 0x19, 0xcf, 0xff, 0xcf, 0xf3, 0x98, 0x07, 
	0xe0, 0x1d, 0xdf, 0xf3, 0xcf, 0xfb, 0xb8, 0x07, 0xe0, 0x1d, 0xf8, 0x67, 0xfe, 0x1f, 0x38, 0x07, 
	0xe0, 0x0c, 0xf8, 0xcf, 0xf0, 0x1f, 0x30, 0x07, 0xe0, 0x0e, 0x33, 0xdd, 0x87, 0xfc, 0x70, 0x07, 
	0xe0, 0x0f, 0xb7, 0x99, 0xff, 0xf1, 0xf0, 0x07, 0xe0, 0x07, 0xe7, 0x3c, 0xfc, 0xc7, 0xe0, 0x07, 
	0xe0, 0x01, 0xcc, 0x7e, 0x7e, 0x1f, 0x80, 0x06, 0x60, 0x01, 0xdf, 0xff, 0x3f, 0xfb, 0x80, 0x06, 
	0x60, 0x03, 0x9f, 0xff, 0xbf, 0xf9, 0xc0, 0x06, 0x70, 0x03, 0xbf, 0xf9, 0x9f, 0xf9, 0xc0, 0x0e, 
	0x70, 0x03, 0xb8, 0x33, 0x9c, 0x1d, 0xc0, 0x0e, 0x30, 0x03, 0x98, 0x39, 0x9c, 0x39, 0x80, 0x0c, 
	0x38, 0x01, 0xdc, 0x3c, 0xfc, 0x3b, 0x80, 0x1c, 0x38, 0x01, 0xdc, 0x1e, 0x78, 0x3b, 0x80, 0x18, 
	0x1c, 0x01, 0xcf, 0xff, 0x3f, 0xf3, 0x00, 0x38, 0x1c, 0x00, 0xef, 0xfb, 0xbf, 0xf7, 0x00, 0x39, 
	0x8e, 0x00, 0xef, 0xf3, 0x9f, 0xf7, 0x00, 0x71, 0xce, 0x00, 0xe0, 0x03, 0xc0, 0x06, 0x00, 0x73, 
	0xc7, 0x00, 0x7f, 0xff, 0xff, 0xfe, 0x00, 0xe3, 0xe3, 0x80, 0x7f, 0xfe, 0x7f, 0xfe, 0x01, 0xc7, 
	0xe3, 0x80, 0x3f, 0xfc, 0x3f, 0xfc, 0x03, 0xc7, 0xf1, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x03, 0x8f, 
	0xf8, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x07, 0x1f, 0xfc, 0x70, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x3f, 
	0xfc, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x7f, 0xfe, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x78, 0x7f, 
	0xff, 0x0f, 0x00, 0x00, 0x00, 0x01, 0xf0, 0xff, 0xff, 0xc3, 0xc0, 0x00, 0x00, 0x03, 0xc3, 0xff, 
	0xff, 0xe1, 0xf0, 0x00, 0x00, 0x0f, 0x87, 0xff, 0xff, 0xf0, 0x7e, 0x00, 0x00, 0x7e, 0x0f, 0xff, 
	0xff, 0xfc, 0x1f, 0xe0, 0x07, 0xf8, 0x3f, 0xff, 0xff, 0xfe, 0x07, 0xff, 0xff, 0xe0, 0x7f, 0xff, 
	0xff, 0xff, 0x80, 0xff, 0xff, 0x01, 0xff, 0xff
};

void setup() {
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  display.clearDisplay();
  display.drawBitmap(0, 0, school_logo, 64, 64, SSD1306_WHITE);
  display.display();
}

void loop() {
}

