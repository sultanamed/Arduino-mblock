/*
  Ders 04: RGB LED Uygulaması
  Açıklama: Ortak Katot RGB LED kullanarak sırasıyla kırmızı, yeşil, 
            mavi, sarı, magenta, cyan ve beyaz renkleri oluşturur.
  
  Pin Tanımlamaları:
    - Kırmızı (R) Pin: 9
    - Yeşil (G) Pin: 10
    - Mavi (B) Pin: 11
  
  Yazar: sultanamed
*/

// Pin tanımlamaları
const int kirmiziPin = 9;
const int yesilPin = 10;
const int maviPin = 11;

void setup() {
  // Bütün RGB led pinlerini çıkış (OUTPUT) olarak tanımlıyoruz
  pinMode(kirmiziPin, OUTPUT);
  pinMode(yesilPin, OUTPUT);
  pinMode(maviPin, OUTPUT);
}

// Renk fonksiyonu yardımıyla pinlerin durumlarını ayarlıyoruz
void renkAyarla(int kirmizi, int yesil, int mavi) {
  digitalWrite(kirmiziPin, kirmizi);
  digitalWrite(yesilPin, yesil);
  digitalWrite(maviPin, mavi);
}

void loop() {
  // 1. Kırmızı (1 saniye)
  renkAyarla(HIGH, LOW, LOW);
  delay(1000);
  
  // 2. Yeşil (1 saniye)
  renkAyarla(LOW, HIGH, LOW);
  delay(1000);
  
  // 3. Mavi (1 saniye)
  renkAyarla(LOW, LOW, HIGH);
  delay(1000);
  
  // 4. Sarı (Kırmızı + Yeşil) (1 saniye)
  renkAyarla(HIGH, HIGH, LOW);
  delay(1000);
  
  // 5. Magenta / Mor (Kırmızı + Mavi) (1 saniye)
  renkAyarla(HIGH, LOW, HIGH);
  delay(1000);
  
  // 6. Cyan / Turkuaz (Yeşil + Mavi) (1 saniye)
  renkAyarla(LOW, HIGH, HIGH);
  delay(1000);
  
  // 7. Beyaz (Kırmızı + Yeşil + Mavi) (1 saniye)
  renkAyarla(HIGH, HIGH, HIGH);
  delay(1000);
}
