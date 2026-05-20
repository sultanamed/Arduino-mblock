/*
  Ders 02: Trafik Lambası Uygulaması
  Açıklama: Kırmızı, Sarı ve Yeşil LED'leri sırayla yakarak
            basit bir trafik ışığı simülasyonu yapar.
  
  Pin Tanımlamaları:
    - Kırmızı LED: Pin 5
    - Sarı LED: Pin 6
    - Yeşil LED: Pin 7
  
  Yazar: sultanamed
*/

// LED pin numaralarını tanımlıyoruz
const int kirmiziLed = 5;
const int sariLed = 6;
const int yesilLed = 7;

void setup() {
  // Bütün LED pinlerini çıkış (OUTPUT) olarak ayarlıyoruz
  pinMode(kirmiziLed, OUTPUT);
  pinMode(sariLed, OUTPUT);
  pinMode(yesilLed, OUTPUT);
}

void loop() {
  // 1. ADIM: Kırmızı ışık yanar (Diğerleri söner) - 3 saniye
  digitalWrite(kirmiziLed, HIGH);
  digitalWrite(sariLed, LOW);
  digitalWrite(yesilLed, LOW);
  delay(3000);
  
  // 2. ADIM: Sarı ışık da kırmızı ile birlikte yanar (Hazırlan) - 1 saniye
  digitalWrite(sariLed, HIGH);
  delay(1000);
  
  // 3. ADIM: Yeşil ışık yanar (Kırmızı ve Sarı söner) - 3 saniye
  digitalWrite(kirmiziLed, LOW);
  digitalWrite(sariLed, LOW);
  digitalWrite(yesilLed, HIGH);
  delay(3000);
  
  // 4. ADIM: Yeşil söner, Sarı yanar (Yavaşla/Dur) - 1 saniye
  digitalWrite(yesilLed, LOW);
  digitalWrite(sariLed, HIGH);
  delay(1000);
}
