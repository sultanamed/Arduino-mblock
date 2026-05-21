/*
  Ders 07: Potansiyometre ile LED Parlaklığı Ayarlama
  Açıklama: A0 analog pinine bağlı potansiyometreden okunan 0-1023 arasındaki 
            değeri 4'e bölerek 0-255 aralığına düşürür ve Pin 6'ya bağlı 
            LED'in parlaklığını manuel olarak kontrol etmemizi sağlar.
  
  Pin Tanımlamaları:
    - Potansiyometre (Orta Ayak): A0 (Analog Giriş)
    - LED Pin: 6 (Donanımsal PWM pini)
  
  Yazar: sultanamed
*/

// Pin tanımlamaları
const int potPin = A0;
const int ledPin = 6;

void setup() {
  // LED pini çıkış olarak ayarlanır (Analog pinler setup'ta giriş tanımlanmasa da olur)
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Potansiyometreden 0-1023 arası değer okunur
  int potDeger = analogRead(potPin);
  
  // 0-1023 değerini 4'e bölerek 0-255 PWM değer aralığına çeviriyoruz (analogWrite için)
  int ledParlaklik = potDeger / 4;
  
  // LED parlaklığı ayarlanır
  analogWrite(ledPin, ledParlaklik);
  
  // Küçük bir gecikme vererek okumayı stabil hale getiriyoruz
  delay(10);
}
