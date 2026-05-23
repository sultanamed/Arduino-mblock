/*
  Ders 22: LCD Ekran I2C Turkce Karakter Yazdirma 🤖🔆📟
  
  Standart LCD ekranlarin hafizasinda Turkce karakterler (c, g, i, o, s, u, G, S vb.)
  bulunmaz. Bu derste LCD'nin CGRAM hafizasina kendi 5x8 piksellik karakterlerimizi
  tanimlayarak ekranda Turkce kelimeler yazdirmayi ogreniyoruz.
  
  Tanimlanan Karakterler:
  - 0: 'c' (ç)
  - 1: 'g' (ğ)
  - 2: 'i' (ı)
  - 3: 'o' (ö)
  - 4: 's' (ş)
  - 5: 'u' (ü)
  - 6: 'I' (İ)
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

// 5x8 Piksel Turkce Karakter Haritalari
byte turkce_c[8] = {
  B00000,
  B01110,
  B10000,
  B10000,
  B10001,
  B01110,
  B00100,
  B00000
}; // ç

byte turkce_g[8] = {
  B01111,
  B00000,
  B01110,
  B10000,
  B10111,
  B10001,
  B01110,
  B00000
}; // ğ

byte turkce_noktasiz_i[8] = {
  B00000,
  B00000,
  B01100,
  B00100,
  B00100,
  B00100,
  B01110,
  B00000
}; // ı

byte turkce_o[8] = {
  B01010,
  B00000,
  B01110,
  B10001,
  B10001,
  B10001,
  B01110,
  B00000
}; // ö

byte turkce_s[8] = {
  B00000,
  B01111,
  B10000,
  B01110,
  B00001,
  B11110,
  B00100,
  B00000
}; // ş

byte turkce_u[8] = {
  B01010,
  B00000,
  B10001,
  B10001,
  B10001,
  B10001,
  B01110,
  B00000
}; // ü

byte turkce_buyuk_i[8] = {
  B00100,
  B00000,
  B01110,
  B00100,
  B00100,
  B00100,
  B01110,
  B00000
}; // İ

void setup() {
  lcd.init();
  lcd.backlight();
  
  // Ozel karakterler LCD hafizasina kaydediliyor (en fazla 8 adet)
  lcd.createChar(0, turkce_c);
  lcd.createChar(1, turkce_g);
  lcd.createChar(2, turkce_noktasiz_i);
  lcd.createChar(3, turkce_o);
  lcd.createChar(4, turkce_s);
  lcd.createChar(5, turkce_u);
  lcd.createChar(6, turkce_buyuk_i);
  
  lcd.clear();
  
  // "TÜRKÇE karakter" yazdirma testi
  lcd.setCursor(0, 0);
  lcd.print("T");
  lcd.write(5); // Ü
  lcd.print("RK");
  lcd.write(0); // Ç
  lcd.print("E YAZI");
  
  // "sağlık, ışık" yazdirma testi
  lcd.setCursor(0, 1);
  lcd.print("sa");
  lcd.write(1); // ğ
  lcd.print("l");
  lcd.write(2); // ı
  lcd.print("k, ");
  lcd.write(2); // ı
  lcd.write(4); // ş
  lcd.write(2); // ı
  lcd.print("k");
}

void loop() {
  // Dongude yapilacak bir islem yok
}
