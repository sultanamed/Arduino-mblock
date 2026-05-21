/*
  Ders 14: HC-SR04 Ultrasonik Sensör ile Mesafe Ölçümü
  Açıklama: Trig pini üzerinden ses dalgası gönderip, Echo pini ile 
            yansıyan dalganın dönüş süresini (mikrosaniye) ölçerek 
            cismin uzaklığını santimetre (cm) cinsinden hesaplar.
            Sonuçları Seri Port ekranına yazdırır.
  
  Pin Tanımlamaları:
    - Trig Pini: Pin 3 (Çıkış)
    - Echo Pini: Pin 2 (Giriş)
  
  Yazar: sultanamed
*/

// Pin Tanımlamaları
const int trigPin = 3;
const int echoPin = 2;

// Değişkenler
long sure;
int mesafe;

void setup() {
  // Seri port ekranını başlatıyoruz
  Serial.begin(9600);
  
  // Sensör pin yönlerini belirliyoruz
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // Trig pinini temizliyoruz
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Ses dalgasını tetiklemek için 10 mikrosaniye HIGH gönderiyoruz
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Echo pininin HIGH kalma süresini okuyoruz (sesin gidiş-dönüş süresi)
  sure = pulseIn(echoPin, HIGH);
  
  // Ses hızı (340 m/s) formülüyle süreyi mesafeye çeviriyoruz (mesafe = (süre/2) / 29.1)
  mesafe = sure * 0.034 / 2;
  
  // Ölçülen mesafeyi Seri Monitör'e yazdırıyoruz
  Serial.print("Mesafe: ");
  Serial.print(mesafe);
  Serial.println(" cm");
  
  // 250 milisaniye bekliyoruz (Kararlı ölçümler için)
  delay(250);
}
