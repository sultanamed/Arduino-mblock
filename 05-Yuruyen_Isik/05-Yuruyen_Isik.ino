/*
  Ders 05: Yürüyen Işık Devresi (Kara Şimşek / Sıralı LED)
  Açıklama: 3 adet LED'i sırayla yakarak (1. led yanar -> 2. led yanar -> 3. led yanar) 
            sürekli tekrarlayan sıralı bir yürüyen ışık devresi oluşturur.
  
  Pin Tanımlamaları:
    - LED 1: Pin 8
    - LED 2: Pin 9
    - LED 3: Pin 10
  
  Yazar: sultanamed
*/

// LED pin tanımlamaları
const int led1 = 8;
const int led2 = 9;
const int led3 = 10;

void setup() {
  // LED pinlerini çıkış (OUTPUT) olarak tanımlıyoruz
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {
  // 1. Durum: Sadece 1. LED yanar (0.5 saniye)
  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  delay(500);
  
  // 2. Durum: Sadece 2. LED yanar (0.5 saniye)
  digitalWrite(led1, LOW);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, LOW);
  delay(500);
  
  // 3. Durum: Sadece 3. LED yanar (0.5 saniye)
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, HIGH);
  delay(500);
}
