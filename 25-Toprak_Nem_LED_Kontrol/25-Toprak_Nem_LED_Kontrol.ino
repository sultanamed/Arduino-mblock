/*
  Ders 25: Toprak Nem Seviye LED Kontrol Devresi 🤖🌱🔴🟡🟢
  
  Bu projede FC-28 toprak nem sensörü yardımıyla saksı toprağının
  nem seviyesini ölçüyoruz ve nem miktarına göre kademeli olarak
  Kırmızı, Sarı ve Yeşil LED'lerimizi yakarak görsel geri bildirim sağlıyoruz.
  
  Toprak nem sensörü (FC-28) Değer Aralıkları:
  - Toprak Kuru (Analog Değer > 700) ➡️ Yeşil LED Yanar (Sulamaya gerek yok veya kuru olduğunu bildirmek için)
  - Toprak Nemli (Analog Değer 450 - 700) ➡️ Sarı LED Yanar
  - Toprak Çok Islak (Analog Değer < 450) ➡️ Kırmızı LED Yanar
  
  Not: Problar sudan çıkarıldığında (tamamen kuru) okunan değer ~1023'tür.
        Suya batırıldığında (tamamen ıslak) okunan değer minimum ~270-300 seviyelerine iner.
        Eğitim portalındaki mantığa göre:
        - Kuru iken: Yeşil LED
        - Nemli iken: Sarı LED
        - Çok nemli iken: Kırmızı LED ışık verecektir.
  
  Bağlantılar:
  - Sensör Analog Çıkış (AO) ➡️ Arduino A0 pini
  - Kırmızı LED ➡️ Dijital Pin 8
  - Sarı LED ➡️ Dijital Pin 9
  - Yeşil LED ➡️ Dijital Pin 10
  - LED katotları (eksi uçları) ➡️ 220 ohm dirençler üzerinden GND
*/

// Pin tanımlamaları
const int nemPin = A0;      // Toprak nem sensörü analog pini
const int kirmiziLed = 8;   // Çok ıslak seviye LED'i
const int sariLed = 9;      // Nemli seviye LED'i
const int yesilLed = 10;    // Kuru seviye LED'i

void setup() {
  // LED pinlerini çıkış olarak ayarlıyoruz
  pinMode(kirmiziLed, OUTPUT);
  pinMode(sariLed, OUTPUT);
  pinMode(yesilLed, OUTPUT);
  
  // Seri haberleşmeyi başlatıyoruz (hata ayıklama ve kalibrasyon için)
  Serial.begin(9600);
  
  // Başlangıçta tüm LED'leri söndürelim
  digitalWrite(kirmiziLed, LOW);
  digitalWrite(sariLed, LOW);
  digitalWrite(yesilLed, LOW);
}

void loop() {
  // Sensörden analog değeri okuyoruz
  int nemDegeri = analogRead(nemPin);
  
  // Seri port ekranına değeri yazdırıyoruz
  Serial.print("Toprak Nem Degeri: ");
  Serial.println(nemDegeri);
  
  // Nem seviyesine göre LED'leri kontrol ediyoruz
  if (nemDegeri > 700) {
    // Toprak Kuru -> Yeşil LED Aktif
    digitalWrite(yesilLed, HIGH);
    digitalWrite(sariLed, LOW);
    digitalWrite(kirmiziLed, LOW);
  }
  else if (nemDegeri <= 700 && nemDegeri > 450) {
    // Toprak Nemli -> Sarı LED Aktif
    digitalWrite(yesilLed, LOW);
    digitalWrite(sariLed, HIGH);
    digitalWrite(kirmiziLed, LOW);
  }
  else {
    // Toprak Çok Nemli / Islak -> Kırmızı LED Aktif
    digitalWrite(yesilLed, LOW);
    digitalWrite(sariLed, LOW);
    digitalWrite(kirmiziLed, HIGH);
  }
  
  // 500 ms (yarım saniye) bekletiyoruz
  delay(500);
}
