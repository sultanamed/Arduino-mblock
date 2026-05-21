/*
  Ders 10: Bir Buton ile LED Yakma Söndürme (Toggle)
  Açıklama: Bir butona her basışımızda LED'in durumunu tersine çevirir (Açık ise Kapatır, 
            Kapalı ise Açar). Ark (bouncing) önleme gecikmesi içerir.
  
  Pin Tanımlamaları:
    - LED Pin: 7 (Çıkış)
    - Buton Pin: 8 (Giriş, Pull-Down Dirençli)
  
  Yazar: sultanamed
*/

// Pin tanımlamaları
const int ledPin = 7;
const int buttonPin = 8;

void setup() {
  // Pin modları ayarlanır
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  // Butonun ve LED'in mevcut durumunu okuyoruz
  int butonDurumu = digitalRead(buttonPin);
  int ledDurumu = digitalRead(ledPin);
  
  // Eğer butona basıldıysa (HIGH ise)
  if (butonDurumu == HIGH) {
    if (ledDurumu == LOW) {
      // LED sönükse yakıyoruz
      digitalWrite(ledPin, HIGH);
    } else {
      // LED yanıyorsa söndürüyoruz
      digitalWrite(ledPin, LOW);
    }
    // Buton arkını (bouncing) ve hızlı tetiklemeyi önlemek için bekleme
    delay(500); 
  }
}
