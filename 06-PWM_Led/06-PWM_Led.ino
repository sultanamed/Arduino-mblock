/*
  Ders 06: PWM Sinyali ile LED Parlaklığı Ayarlama
  Açıklama: PWM (Sinyal Genişlik Modülasyonu) kullanarak bir LED'in 
            parlaklığını 3 farklı seviyede kademeli olarak değiştirir.
  
  Pin Tanımlamaları:
    - LED Pin: 5 (Donanımsal PWM pini)
  
  Yazar: sultanamed
*/

// LED'in bağlı olduğu PWM pini
const int ledPin = 5;

void setup() {
  // PWM pini çıkış (OUTPUT) olarak tanımlanır
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // 1. Kısık Seviye (Değer: 55, Yaklaşık 1V)
  analogWrite(ledPin, 55);
  delay(1000);
  
  // 2. Orta Seviye (Değer: 127, Yaklaşık 2.5V, %50 Doluluk Oranı)
  analogWrite(ledPin, 127);
  delay(1000);
  
  // 3. Parlak Seviye (Değer: 255, Yaklaşık 5V, %100 Doluluk Oranı)
  analogWrite(ledPin, 255);
  delay(1000);
}
