/*
  Ders 09: Potansiyometre ile Flip Flop Devresi (Hız Ayarlı Flaşör)
  Açıklama: A0 pinindeki potansiyometreden okunan analog değer yardımıyla, 
            sırayla yanıp sönen 2 adet LED'in bekleme süresini (hızını) 
            dinamik olarak ayarlar.
  
  Pin Tanımlamaları:
    - Potansiyometre: A0 (Analog Giriş)
    - LED 1: Pin 7
    - LED 2: Pin 8
  
  Yazar: sultanamed
*/

// Pin tanımlamaları
const int potPin = A0;
const int led1 = 7;
const int led2 = 8;

void setup() {
  // LED pinleri çıkış olarak ayarlanır
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  // Potansiyometreden bekleme süresini belirliyoruz (0-1023 milisaniye)
  int beklemeSuresi = analogRead(potPin);
  
  // LED 1 yanar, LED 2 söner
  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW);
  delay(beklemeSuresi);
  
  // Potansiyometreden süreyi tekrar okuyarak dinamik güncellik sağlıyoruz
  beklemeSuresi = analogRead(potPin);
  
  // LED 1 söner, LED 2 yanar
  digitalWrite(led1, LOW);
  digitalWrite(led2, HIGH);
  delay(beklemeSuresi);
}
