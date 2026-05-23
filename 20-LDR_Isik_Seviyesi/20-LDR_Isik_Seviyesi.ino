/*
  Ders 20: LDR ile Işık Seviye Kontrolü 🤖🔆
  
  Bu projede LDR yardımıyla ortam ışık seviyesini ölçüyoruz.
  Işık şiddetine göre 4 adet LED sırayla yanar ve en yüksek seviyede
  buzzer sesli uyarı verir.
  
  Bağlantılar:
  - LDR: A0 pini (10k ohm pull-down direnç ile)
  - LED 1: Pin 4
  - LED 2: Pin 5
  - LED 3: Pin 6
  - LED 4: Pin 7
  - Buzzer: Pin 8
*/

const int ldrPin = A0;
const int ledPins[] = {4, 5, 6, 7};
const int buzzerPin = 8;
const int numLeds = 4;

void setup() {
  // LED pinleri çıkış olarak ayarlanıyor
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  
  // Buzzer pini çıkış olarak ayarlanıyor
  pinMode(buzzerPin, OUTPUT);
  
  // Seri haberleşme başlatılıyor
  Serial.begin(9600);
}

void loop() {
  // LDR'den ışık seviyesi okunuyor
  int isikDegeri = analogRead(ldrPin);
  
  Serial.print("Isik Seviyesi: ");
  Serial.println(isikDegeri);
  
  // Tüm LED'leri ve buzzer'ı başlangıçta kapatalım
  for (int i = 0; i < numLeds; i++) {
    digitalWrite(ledPins[i], LOW);
  }
  digitalWrite(buzzerPin, LOW);
  
  // Işık seviyesine göre kademeli kontrol
  if (isikDegeri > 200) {
    digitalWrite(ledPins[0], HIGH); // 1. LED Açık
  }
  if (isikDegeri > 400) {
    digitalWrite(ledPins[1], HIGH); // 2. LED Açık
  }
  if (isikDegeri > 600) {
    digitalWrite(ledPins[2], HIGH); // 3. LED Açık
  }
  if (isikDegeri > 800) {
    digitalWrite(ledPins[3], HIGH); // 4. LED Açık
    digitalWrite(buzzerPin, HIGH);  // Buzzer Aktif
  }
  
  delay(100); // Kararlılık için kısa bekleme
}
