/*
  Ders 24: LCD Ekranli Su Seviye Kontrol Devresi 🤖🔆📟🌧️
  
  Bu projede su seviye sensöründen (A0) okuduğumuz değeri
  16x2 I2C LCD ekran üzerinde sayısal ve sözel (durum) olarak görüntülüyoruz.
  
  Bağlantılar:
  - Su Seviye Sensörü S ➡️ A0 pini
  - LCD SDA ➡️ A4 (veya SDA pini)
  - LCD SCL ➡️ A5 (veya SCL pini)
  - VCC ➡️ 5V
  - GND ➡️ GND
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

// Türkçe Karakterler (ü, ş, ı)
byte turkce_u[8] = { B01010, B00000, B10001, B10001, B10001, B10001, B01110, B00000 }; // ü
byte turkce_s[8] = { B00000, B01111, B10000, B01110, B00001, B11110, B00100, B00000 }; // ş
byte turkce_noktasiz_i[8] = { B00000, B00000, B01100, B00100, B00100, B00100, B01110, B00000 }; // ı

const int suPin = A0;

void setup() {
  lcd.init();
  lcd.backlight();
  
  // Türkçe karakter tanımlamaları
  lcd.createChar(0, turkce_u);
  lcd.createChar(1, turkce_s);
  lcd.createChar(2, turkce_noktasiz_i);
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Su Seviye Olcum");
  lcd.setCursor(0, 1);
  lcd.print("Sistemi Acildi");
  delay(2000);
}

void loop() {
  int suDegeri = analogRead(suPin);
  
  lcd.clear();
  
  // 1. Satır: Değeri yazdır
  lcd.setCursor(0, 0);
  lcd.print("Deger: ");
  lcd.print(suDegeri);
  
  // 2. Satır: Durumu yazdır
  lcd.setCursor(0, 1);
  lcd.print("Durum: ");
  
  if (suDegeri < 100) {
    lcd.print("Kuru");
  } 
  else if (suDegeri >= 100 && suDegeri < 300) {
    lcd.print("D");
    lcd.write(0); // ü
    lcd.write(1); // ş
    lcd.write(0); // ü
    lcd.print("k"); // Düşük
  } 
  else if (suDegeri >= 300 && suDegeri < 500) {
    lcd.print("Orta");
  } 
  else if (suDegeri >= 500 && suDegeri < 650) {
    lcd.print("Y");
    lcd.write(0); // ü
    lcd.print("ksek"); // Yüksek
  } 
  else {
    lcd.print("Kritik / Ta");
    lcd.write(1); // ş
    lcd.print("ma"); // Kritik / Taşma
  }
  
  delay(500); // Yarım saniyede bir güncelle
}
