/*
  Ders 32: HC-SR04 Ultrasonik Sensör ile Servo Motor Kontrolü 🤖📏⚙️
  
  Bu projede HC-SR04 Ultrasonik Mesafe Sensörü kullanarak mesafeyi ölçüyoruz.
  Belirli bir mesafeden (6 cm) daha yakın bir nesne algılandığında Servo Motorun
  açısını 90 dereceye getirerek otomatik açılan bir engel/bariyer veya akıllı
  çöp kutusu kapak mekanizması tasarlıyoruz. Engel ortadan kalktığında motor
  başlangıç konumuna (0 derece) geri dönecektir.
  
  Bağlantılar:
  - SG90 Servo Motor:
    - Kırmızı Kablo (VCC) ➡️ Arduino 5V
    - Kahverengi/Siyah Kablo (GND) ➡️ Arduino GND
    - Turuncu/Sarı Kablo (Sinyal) ➡️ Arduino Pin 9 (PWM)
  
  - HC-SR04 Ultrasonik Mesafe Sensörü:
    - VCC ➡️ Arduino 5V
    - GND ➡️ Arduino GND
    - Trig ➡️ Arduino Dijital Pin 8
    - Echo ➡️ Arduino Dijital Pin 7
*/

#include <Servo.h> // Servo motor kütüphanesi

Servo bariyerServo; // Servo nesnemizi tanımlıyoruz

// Mesafe sensörü pin tanımlamaları
const int trigPin = 8;
const int echoPin = 7;
const int servoPin = 9;

// Mesafe eşiği (santimetre cinsinden)
const int esikMesafe = 6;

void setup() {
  // Servo motoru bağlıyoruz
  bariyerServo.attach(servoPin);
  
  // Mesafe sensörü pin modları
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  // Başlangıçta bariyer kapalı (0 derece) olsun
  bariyerServo.write(0);
  
  // Seri haberleşmeyi başlatıyoruz
  Serial.begin(9600);
}

void loop() {
  // HC-SR04 ile mesafe ölçüm döngüsü
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Ses dalgasının geri dönüş süresini ölçüyoruz (mikrosaniye)
  long sure = pulseIn(echoPin, HIGH);
  
  // Süreyi santimetre cinsinden mesafeye çeviriyoruz
  // Ses hızı = 343 m/s = 0.0343 cm/us. Yol = Hız x Zaman -> Gidiş-Dönüş olduğu için 2'ye bölüyoruz.
  // Mesafe = (sure * 0.0343) / 2 -> Yaklaşık olarak sure / 58.2
  int mesafe = sure / 58.2;
  
  // Seri port ekranına mesafeyi yazdıralım
  Serial.print("Mesafe: ");
  Serial.print(mesafe);
  Serial.println(" cm");
  
  // Eşik değerinin altında bir nesne algılanırsa bariyeri AÇ
  if (mesafe > 0 && mesafe < esikMesafe) {
    bariyerServo.write(90); // Servo 90 dereceye döner (Bariyer Açık)
    Serial.println("-> Engel algılandı! Kapı Açık.");
  } 
  else {
    bariyerServo.write(0);  // Servo 0 dereceye döner (Bariyer Kapalı)
  }
  
  delay(100); // Kararlı okumalar için kısa bir gecikme
}
