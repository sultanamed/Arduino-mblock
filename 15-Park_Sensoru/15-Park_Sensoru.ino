/*
  Ders 15: HC-SR04 ile Kademeli Araç Park Sensörü
  Açıklama: Ultrasonik mesafe sensörüyle önündeki/arkasındaki engeli algılar. 
            Mesafe azaldıkça yanan LED sayısı artar ve buzzer daha sık 
            aralıklarla sinyal vererek park yardım uyarısı oluşturur.
  
  Pin Tanımlamaları:
    - Trig Pini: Pin 13 (Çıkış)
    - Echo Pini: Pin 12 (Giriş)
    - LED 1 (Mavi): Pin 6
    - LED 2 (Yeşil): Pin 5
    - LED 3 (Sarı): Pin 4
    - LED 4 (Kırmızı): Pin 3
    - Buzzer (Ses): Pin 2
  
  Yazar: sultanamed
*/

// Sensör Pinleri
const int trigPin = 13;
const int echoPin = 12;

// LED ve Buzzer Pinleri
const int ledMavi = 6;
const int ledYesil = 5;
const int ledSari = 4;
const int ledKirmizi = 3;
const int buzzerPin = 2;

// Süre ve Mesafe Değişkenleri
long sure;
int mesafe;

void setup() {
  // Seri port ekranını başlatıyoruz
  Serial.begin(9600);
  
  // Pinlerin yönlerini ayarlıyoruz
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  pinMode(ledMavi, OUTPUT);
  pinMode(ledYesil, OUTPUT);
  pinMode(ledSari, OUTPUT);
  pinMode(ledKirmizi, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Tetikleme sinyali gönderiliyor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Yansıyan dalganın süresi ölçülüyor
  sure = pulseIn(echoPin, HIGH);
  
  // Mesafe santimetreye dönüştürülüyor
  mesafe = sure * 0.034 / 2;
  
  Serial.print("Mesafe: ");
  Serial.print(mesafe);
  Serial.println(" cm");
  
  // Kademeli uyarı mantığı
  if (mesafe > 40) {
    // 40 cm üzeri: Güvenli (Hiçbir led yanmaz, alarm yok)
    digitalWrite(ledMavi, LOW);
    digitalWrite(ledYesil, LOW);
    digitalWrite(ledSari, LOW);
    digitalWrite(ledKirmizi, LOW);
    digitalWrite(buzzerPin, LOW);
    delay(200);
  } 
  else if (mesafe > 30 && mesafe <= 40) {
    // 30 - 40 cm: Seviye 1 (Sadece Mavi LED, Yavaş Bip)
    digitalWrite(ledMavi, HIGH);
    digitalWrite(ledYesil, LOW);
    digitalWrite(ledSari, LOW);
    digitalWrite(ledKirmizi, LOW);
    
    digitalWrite(buzzerPin, HIGH);
    delay(100);
    digitalWrite(buzzerPin, LOW);
    delay(1400); // 1.5 saniye toplam bekleme aralığı
  } 
  else if (mesafe > 20 && mesafe <= 30) {
    // 20 - 30 cm: Seviye 2 (Mavi + Yeşil LED, Orta Hızda Bip)
    digitalWrite(ledMavi, HIGH);
    digitalWrite(ledYesil, HIGH);
    digitalWrite(ledSari, LOW);
    digitalWrite(ledKirmizi, LOW);
    
    digitalWrite(buzzerPin, HIGH);
    delay(100);
    digitalWrite(buzzerPin, LOW);
    delay(700); // 0.8 saniye toplam bekleme aralığı
  } 
  else if (mesafe > 10 && mesafe <= 20) {
    // 10 - 20 cm: Seviye 3 (Mavi + Yeşil + Sarı LED, Hızlı Bip)
    digitalWrite(ledMavi, HIGH);
    digitalWrite(ledYesil, HIGH);
    digitalWrite(ledSari, HIGH);
    digitalWrite(ledKirmizi, LOW);
    
    digitalWrite(buzzerPin, HIGH);
    delay(100);
    digitalWrite(buzzerPin, LOW);
    delay(300); // 0.4 saniye toplam bekleme aralığı
  } 
  else {
    // 10 cm altı: Tehlikeli Yakınlık (Tüm LED'ler ve kesintisiz hızlı alarm)
    digitalWrite(ledMavi, HIGH);
    digitalWrite(ledYesil, HIGH);
    digitalWrite(ledSari, HIGH);
    digitalWrite(ledKirmizi, HIGH);
    
    digitalWrite(buzzerPin, HIGH);
    delay(75);
    digitalWrite(buzzerPin, LOW);
    delay(75); // 0.15 saniye toplam bekleme aralığı
  }
}
