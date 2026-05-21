/*
  Ders 17: LM393 Alev Sensörü ile Yangın Alarmı Devresi
  Açıklama: Bu kod hem Analog (A0) hem de Dijital (D0 - Pin 8) okuma 
            seçeneklerini destekler. Alev algılandığında Pin 7'deki 
            LED'i yakar ve Pin 6'daki Buzzer'ı siren şeklinde öttürür.
  
  ÖNEMLİ DETAYLAR:
    - Dijital Okumada (D0): LM393 sensörü alev algıladığında 0 (LOW), 
      alev yokken 1 (HIGH) çıkışı verir.
    - Analog Okumada (A0): Alev algılandığında analog değer düşer. 
      Ortam ışığına göre eşik değer belirlenmelidir (örneğin < 500).
      
  Pin Tanımlamaları:
    - Alev Sensörü Analog: A0
    - Alev Sensörü Dijital: Pin 8
    - Kırmızı LED: Pin 7 (Dijital Çıkış)
    - Buzzer: Pin 6 (Dijital Çıkış)
    
  Yazar: sultanamed
*/

// Okuma Modu Seçimi:
// true: Analog okuma kullanır (varsayılan)
// false: Dijital okuma kullanır
const bool analogModAktif = true; 

// Pin Tanımlamaları
const int sensorAnalogPin = A0;
const int sensorDijitalPin = 8;
const int ledPin = 7;
const int buzzerPin = 6;

// Eşik Değeri (Analog Mod için)
const int analogEsik = 500; 

void setup() {
  Serial.begin(9600);
  
  pinMode(sensorDijitalPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  bool yanginVar = false;
  
  if (analogModAktif) {
    // ANALOG OKUMA MODU
    int alevDegeri = analogRead(sensorAnalogPin);
    Serial.print("Analog Alev Seviyesi: ");
    Serial.println(alevDegeri);
    
    // Alev yaklaşınca analog değer eşik değerin altına iner
    if (alevDegeri < analogEsik) {
      yanginVar = true;
    }
  } 
  else {
    // DİJİTAL OKUMA MODU
    int dijitalDeger = digitalRead(sensorDijitalPin);
    Serial.print("Dijital Alev Durumu: ");
    Serial.println(dijitalDeger);
    
    // Alev algılandığında sensör 0 (LOW) üretir
    if (dijitalDeger == LOW) {
      yanginVar = true;
    }
  }
  
  // Yangın Alarm Mantığı
  if (yanginVar) {
    Serial.println("!!! YANGIN ALARMI AKTİF !!!");
    digitalWrite(ledPin, HIGH);
    
    // Siren sesi efekti
    digitalWrite(buzzerPin, HIGH);
    delay(80);
    digitalWrite(buzzerPin, LOW);
    delay(80);
  } 
  else {
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);
    delay(200);
  }
}
