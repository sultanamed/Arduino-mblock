/*
  Ders 28: 7 Segment Display Scoreboard (Butonlu Sayaç) 🤖🔢🔘
  
  Bu projede Ortak Katot 7 Segment Display kullanarak iki buton yardımıyla
  sayıyı artıran ve azaltan bir Skor Tabelası (Scoreboard) uygulaması yapıyoruz.
  
  Bağlantılar:
  - Segment A  ➡️ Dijital Pin 4
  - Segment B  ➡️ Dijital Pin 5
  - Segment C  ➡️ Dijital Pin 6
  - Segment D  ➡️ Dijital Pin 7
  - Segment E  ➡️ Dijital Pin 10
  - Segment F  ➡️ Dijital Pin 11
  - Segment G  ➡️ Dijital Pin 12
  - Nokta (DP) ➡️ Dijital Pin 13
  
  Butonlar (Aktif-Yüksek / Pull-Down Dirençli):
  - İleri (Arttırma) Butonu ➡️ Dijital Pin 8
  - Geri (Azaltma) Butonu   ➡️ Dijital Pin 9
*/

// Segment pinleri
const int segmentPins[] = {4, 5, 6, 7, 10, 11, 12, 13}; // A, B, C, D, E, F, G, DP

// Buton pinleri
const int ileriButonPin = 8;
const int geriButonPin = 9;

// Ortak Katot için segment tablosu (1 = AÇIK, 0 = KAPALI)
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

int sayac = 0; // Skor değeri

// Buton durum takibi için değişkenler
int sonIleriDurum = LOW;
int sonGeriDurum = LOW;

void setup() {
  // Segment pinlerini çıkış yapıyoruz
  for (int i = 0; i < 8; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }
  
  // Buton pinlerini giriş yapıyoruz
  pinMode(ileriButonPin, INPUT);
  pinMode(geriButonPin, INPUT);
  
  // Başlangıç skorunu gösteriyoruz
  rakamGoster(sayac);
}

void rakamGoster(int sayi) {
  for (int segment = 0; segment < 8; segment++) {
    digitalWrite(segmentPins[segment], rakamlar[sayi][segment]);
  }
}

void loop() {
  // Butonların anlık durumlarını okuyoruz
  int ileriDurum = digitalRead(ileriButonPin);
  int geriDurum = digitalRead(geriButonPin);
  
  // İLERİ BUTONU KONTROLÜ (Durum Değişimi: LOW'dan HIGH'a geçiş)
  if (ileriDurum == HIGH && sonIleriDurum == LOW) {
    sayac++;
    if (sayac > 9) {
      sayac = 0; // 9'u geçince tekrar 0'a döner
    }
    rakamGoster(sayac);
    delay(150); // Debounce gecikmesi
  }
  
  // GERİ BUTONU KONTROLÜ (Durum Değişimi: LOW'dan HIGH'a geçiş)
  if (geriDurum == HIGH && sonGeriDurum == LOW) {
    sayac--;
    if (sayac < 0) {
      sayac = 9; // 0'ın altına inince 9'a döner
    }
    rakamGoster(sayac);
    delay(150); // Debounce gecikmesi
  }
  
  // Buton durumlarını güncelliyoruz
  sonIleriDurum = ileriDurum;
  sonGeriDurum = geriDurum;
}
