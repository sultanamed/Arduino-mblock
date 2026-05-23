/*
  Ders 30: Servo Motor Uygulamaları 🤖⚙️
  
  Bu projede SG90 Servo Motorun çalışma mantığını kavrıyoruz ve
  potansiyometreden okuduğumuz analog değeri (0-1023) servo motorun
  çalışma açısına (0-180 derece) dönüştürerek motoru kontrol ediyoruz.
  
  Bağlantılar:
  - SG90 Servo Motor:
    - Kırmızı Kablo (VCC) ➡️ Arduino 5V
    - Kahverengi/Siyah Kablo (GND) ➡️ Arduino GND
    - Turuncu/Sarı Kablo (Sinyal) ➡️ Arduino Pin 9 (PWM)
  
  - Potansiyometre:
    - Sol Bacak ➡️ Arduino 5V (veya GND)
    - Orta Bacak ➡️ Arduino Analog Pin A0
    - Sağ Bacak ➡️ Arduino GND (veya 5V)
*/

#include <Servo.h> // Arduino Servo Kütüphanesi

Servo servoMotor; // Servo nesnesini tanımlıyoruz

const int potPin = A0;  // Potansiyometre pini
const int servoPin = 9; // Servo motor sinyal pini

void setup() {
  // Servo nesnemizi ilgili dijital pine bağlıyoruz
  servoMotor.attach(servoPin);
  
  // Hata ayıklama için seri haberleşmeyi başlatıyoruz
  Serial.begin(9600);
}

void loop() {
  // Potansiyometreden analog değeri okuyoruz (0 - 1023)
  int potDegeri = analogRead(potPin);
  
  // Potansiyometre değerini servo motorun açısına (0 - 180) ölçekliyoruz
  // map(deger, min_giris, max_giris, min_cikis, max_cikis)
  int aci = map(potDegeri, 0, 1023, 0, 180);
  
  // Servo motoru okunan açıya döndürüyoruz
  servoMotor.write(aci);
  
  // Seri porta bilgileri yazdırıyoruz
  Serial.print("Pot Degeri: ");
  Serial.print(potDegeri);
  Serial.print(" -> Motor Acisi: ");
  Serial.println(aci);
  
  // Servonun hedeflenen konuma ulaşması için kısa bir gecikme
  delay(15);
}
