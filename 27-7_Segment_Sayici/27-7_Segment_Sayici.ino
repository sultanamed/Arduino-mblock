/*
  Ders 27: 7 Segment Display 0-9 Sayıcı 🤖🔢
  
  Bu projede Ortak Katot (Common Cathode) 7 Segment Display kullanarak
  0'dan 9'a kadar yukarı sayan veya 9'dan 0'a kadar aşağı sayan bir sayaç devresi kuruyoruz.
  
  7 Segment Display segment harfleri ve pin eşleşmeleri (Sırayla):
  - Segment A ➡️ Dijital Pin 4
  - Segment B ➡️ Dijital Pin 5
  - Segment C ➡️ Dijital Pin 6
  - Segment D ➡️ Dijital Pin 7
  - Segment E ➡️ Dijital Pin 8
  - Segment F ➡️ Dijital Pin 9
  - Segment G ➡️ Dijital Pin 10
  - Nokta (DP) ➡️ Dijital Pin 11
  
  Ortak katot displaylerde segmentleri yakmak için ilgili pini HIGH yapmalıyız.
  Ortak anot displaylerde ise tam tersi LOW yapmalıyız.
*/

// Segment pinlerinin dizisi (A, B, C, D, E, F, G, DP)
const int segmentPins[] = {4, 5, 6, 7, 8, 9, 10, 11};

// Ortak Katot için 0-9 rakamlarının segment tablosu (1 = AÇIK, 0 = KAPALI)
const byte rakamlar[10][8] = {
  {1, 1, 1, 1, 1, 1, 0, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1, 0}, // 2
  {1, 1, 1, 1, 0, 0, 1, 0}, // 3
  {0, 1, 1, 0, 0, 1, 1, 0}, // 4
  {1, 0, 1, 1, 0, 1, 1, 0}, // 5
  {1, 0, 1, 1, 1, 1, 1, 0}, // 6
  {1, 1, 1, 0, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1, 0}, // 8
  {1, 1, 1, 1, 0, 1, 1, 0}  // 9
};

void setup() {
  // Tüm segment pinlerini çıkış (OUTPUT) yapıyoruz
  for (int i = 0; i < 8; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }
}

// Belirli bir rakamı display üzerinde gösteren fonksiyon
void rakamGoster(int sayi) {
  for (int segment = 0; segment < 8; segment++) {
    // Ortak Katot için tablo değerini doğrudan yazdırıyoruz (HIGH = Segment Yanar)
    digitalWrite(segmentPins[segment], rakamlar[sayi][segment]);
  }
}

void loop() {
  // 0'dan 9'a kadar ileri doğru sayalım
  for (int i = 0; i < 10; i++) {
    rakamGoster(i);
    delay(1000); // Rakamlar arasında 1 saniye bekle
  }
  
  delay(1000); // Yukarı sayım bitince 1 saniye bekle
  
  // 9'dan 0'a kadar geri doğru sayalım
  for (int i = 9; i >= 0; i--) {
    rakamGoster(i);
    delay(1000); // Rakamlar arasında 1 saniye bekle
  }
  
  delay(1000); // Geri sayım bitince 1 saniye bekle
}
