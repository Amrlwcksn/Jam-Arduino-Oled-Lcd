#include <DS3231.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>


DS3231 rtc(SDA,SCL);
Adafruit_SSD1306 oled(128,64,&Wire,1);
void setup() {
  Serial.begin(9600);
  if(!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C)){
    Serial.println("Modul OLED gagal dimulai");
  }
  rtc.begin();
  rtc.setDate(17,1,2024);
  rtc.setTime(20,49,00);
  rtc.setDOW(3);
}

void loop() {

  oled.clearDisplay();
  oled.drawRect(1, 5, 126, 55, WHITE);
  oled.setTextColor(WHITE);
  //JAM
  oled.setCursor(16,14);
  oled.setTextSize(2);
  oled.print(rtc.getTimeStr());
  //Hari
  oled.setCursor(36,33);
  oled.setTextSize(1);
  oled.print(rtc.getDOWStr());
  //Tanggal
  oled.setCursor(33,45);
  oled.setTextSize(1);
  oled.print(rtc.getDateStr());

  oled.display();

  delay(1000);
 

}
