/*
  Ders 21: I2C LCD Ekran Uygulamaları 🤖🔆📟
  
  Bu projede I2C haberleşme modüllü 16x2 LCD ekran kullanımını
  ve çeşitli ekran efektlerini (kayan yazı, yanıp sönme vb.) öğreniyoruz.
  
  Kütüphane Gereksinimi:
  - LiquidCrystal_I2C kütüphanesi yüklü olmalıdır.
  
  Bağlantılar:
  - VCC ➡️ Arduino 5V
  - GND ➡️ Arduino GND
  - SDA ➡️ Arduino A4 (Uno için) veya SDA pini
  - SCL ➡️ Arduino A5 (Uno için) veya SCL pini
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// LCD adresi genellikle 0x27 veya 0x3F'tir. Ekran 16 sütun, 2 satırdır.
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // LCD ekran başlatılıyor
  lcd.init();
  
  // Arka ışık açılıyor
  lcd.backlight();
  
  // Başlangıç mesajı yazılıyor
  lcd.setCursor(0, 0); // 1. satır, 1. sütun
  lcd.print("ROBOTIST KULUBY");
  
  lcd.setCursor(0, 1); // 2. satır, 1. sütun
  lcd.print("Hos Geldiniz!");
  
  delay(3000); // 3 saniye bekle
}

void loop() {
  // 1. Efekt: Ekranı temizle ve iki satırlı yeni metin yaz
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("mBlock & Arduino");
  lcd.setCursor(0, 1);
  lcd.print("Egitim Portali");
  delay(2000);
  
  // 2. Efekt: Sola kaydırma
  for (int i = 0; i < 16; i++) {
    lcd.scrollDisplayLeft();
    delay(200);
  }
  
  // 3. Efekt: Ekranı temizle ve yanıp sönen yazı efekti yap
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("UYARI: TEHLIKE");
  
  for (int i = 0; i < 5; i++) {
    lcd.noBacklight(); // Arka ışığı kapat
    delay(300);
    lcd.backlight();   // Arka ışığı aç
    delay(300);
  }
  
  delay(1000);
}
