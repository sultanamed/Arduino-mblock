/*
  Ders 31: LDR (Işık Sensörü) ile Servo Motor Kontrolü 🤖☀️⚙️
  
  Bu projede LDR yardımıyla ortamdaki ışık şiddetini ölçüyoruz ve
  okuduğumuz ışık değerine göre Servo Motorun açısını (0-180 derece) 
  ve bir LED'in parlaklığını (0-255) otomatik ve kademeli olarak kontrol ediyoruz.
  
  Bu sistem akıllı evlerde güneş yönüne göre otomatik ayarlanan kepenkler
  veya ışık miktarına göre yön değiştiren güneş paneli (solar tracker)
  gibi sistemlerin temelidir.
  
  Bağlantılar:
  - SG90 Servo Motor:
    - Kırmızı Kablo (VCC) ➡️ Arduino 5V
    - Kahverengi/Siyah Kablo (GND) ➡️ Arduino GND
    - Turuncu/Sarı Kablo (Sinyal) ➡️ Arduino Pin 9 (PWM)
  
  - LDR (Işık Sensörü) Bağlantısı (Pull-Down):
    - LDR bir ucu ➡️ Arduino 5V
    - LDR diğer ucu ➡️ 10 kΩ Direnç üzerinden GND
    - LDR ve Direnç birleşim noktası ➡️ Arduino Analog A0 pini
  
  - LED Bağlantısı:
    - LED Artı (+) ucu ➡️ 220 Ω Direnç üzerinden Arduino Pin 6 (PWM pini)
    - LED Eksi (-) ucu ➡️ Arduino GND
*/

#include <Servo.h> // Servo kütüphanesi

Servo servoMotor; // Servo nesnemiz

const int ldrPin = A0;   // LDR analog pini
const int ledPin = 6;    // LED PWM pini
const int servoPin = 9;  // Servo sinyal pini

void setup() {
  servoMotor.attach(servoPin); // Servo motoru bağlıyoruz
  pinMode(ledPin, OUTPUT);     // LED pinini çıkış yapıyoruz
  
  Serial.begin(9600); // Seri haberleşmeyi başlatıyoruz
}

void loop() {
  // LDR'den ışık değerini okuyoruz (0 - 1023)
  int ldrDegeri = analogRead(ldrPin);
  
  // 1. UYGULAMA: Işık Şiddetine Göre Kademeli/Orantılı Kontrol (Mesafe ve Parlaklık)
  // Işık azaldıkça (karanlıkta) servo motor 180 dereceye dönsün (perde kapansın),
  // ışık arttıkça (aydınlıkta) 0 dereceye dönsün.
  int motorAcisi = map(ldrDegeri, 200, 900, 0, 180);
  
  // Sınır değerlerini korumak için constrain() kullanıyoruz
  motorAcisi = constrain(motorAcisi, 0, 180);
  
  // LED parlaklığını da ışık şiddetine göre ayarlayalım
  // Karanlıkta LED daha parlak yansın (255), aydınlıkta sönsün (0)
  int ledParlaklik = map(ldrDegeri, 200, 900, 255, 0);
  ledParlaklik = constrain(ledParlaklik, 0, 255);
  
  // Servo ve LED'i güncelliyoruz
  servoMotor.write(motorAcisi);
  analogWrite(ledPin, ledParlaklik);
  
  // Değerleri Seri Port Ekranında gözlemleyelim
  Serial.print("LDR Degeri: ");
  Serial.print(ldrDegeri);
  Serial.print(" | Motor Acisi: ");
  Serial.print(motorAcisi);
  Serial.print(" | LED Parlakligi: ");
  Serial.println(ledParlaklik);
  
  delay(20); // Kararlı çalışma için kısa bekleme
}
