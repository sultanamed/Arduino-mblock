/*
  Ders 26: LCD Ekranli Toprak Nem Seviye Ölçme Devresi 🤖🔆📟🌱
  
  Bu projede FC-28 toprak nem sensörü yardımıyla saksı toprağının
  kuruluk/ıslaklık durumunu ölçüyoruz. LCD ekran üzerinde toprağın durumuna göre
  sulama uyarısı veya durum raporu yayınlıyoruz.
  
  Toprak nem sensöründe değerler:
  - Tamamen Kuru: ~1023
  - Çok Islak/Su İçinde: ~270-300
  
  Bağlantılar:
  - Toprak Nem Sensörü Sinyal (AO) ➡️ A0 pini
  - LCD SDA ➡️ A4 (veya SDA pini)
  - LCD SCL ➡️ A5 (veya SCL pini)
  - VCC ➡️ 5V
  - GND ➡️ GND
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

// Türkçe Karakterler (ü, ş, ı, ö)
byte turkce_u[8] = { B01010, B00000, B10001, B10001, B10001, B10001, B01110, B00000 }; // ü
byte turkce_s[8] = { B00000, B01111, B10000, B01110, B00001, B11110, B00100, B00000 }; // ş
byte turkce_noktasiz_i[8] = { B00000, B00000, B01100, B00100, B00100, B00100, B01110, B00000 }; // ı
byte turkce_o[8] = { B01010, B00000, B01110, B10001, B10001, B10001, B01110, B00000 }; // ö

const int nemPin = A0;

void setup() {
  lcd.init();
  lcd.backlight();
  
  // Türkçe karakter tanımlamaları
  lcd.createChar(0, turkce_u);
  lcd.createChar(1, turkce_s);
  lcd.createChar(2, turkce_noktasiz_i);
  lcd.createChar(3, turkce_o);
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Akilli Cicek");
  lcd.setCursor(0, 1);
  lcd.print("Sistemi Acildi");
  delay(2000);
}

void loop() {
  int nemDegeri = analogRead(nemPin);
  
  lcd.clear();
  
  // Değeri ekrana yazdır (hata kontrolü / kalibrasyon için)
  lcd.setCursor(0, 0);
  lcd.print("Nem Degeri: ");
  lcd.print(nemDegeri);
  
  lcd.setCursor(0, 1);
  // Değer ne kadar büyükse toprak o kadar kurudur!
  if (nemDegeri > 750) {
    // Toprak Kuru, Lütfen Sulayın
    lcd.print("Kuru. L");
    lcd.write(0); // ü
    lcd.print("tfen Sula"); // Lütfen Sula
  } 
  else if (nemDegeri <= 750 && nemDegeri > 450) {
    // Nem Seviyesi Normal
    lcd.print("Nem: Normal");
  } 
  else {
    // Nem Seviyesi Yüksek
    lcd.print("Nem: Y");
    lcd.write(0); // ü
    lcd.print("ksek"); // Yüksek
  }
  
  delay(1000); // 1 saniyede bir kontrol et
}
