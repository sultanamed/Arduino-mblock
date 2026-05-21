/*
  Ders 16: HC-SR501 PIR (Hareket) Sensörü ile Hırsız Alarmı
  Açıklama: PIR sensöründen dijital veri (0 veya 1) okunur. 
            Eğer hareket algılanırsa (1 / HIGH), Pin 6'daki LED yakılır 
            ve Pin 7'deki Buzzer ile hırsız alarm sireni çalınır. 
            Hareket durduğunda sistem sessizleşir.
  
  Pin Tanımlamaları:
    - PIR Hareket Sensörü: Pin 8 (Dijital Giriş)
    - Kırmızı LED: Pin 6 (Dijital Çıkış)
    - Buzzer: Pin 7 (Dijital Çıkış)
  
  Yazar: sultanamed
*/

// Pin Tanımlamaları
const int pirPin = 8;
const int ledPin = 6;
const int buzzerPin = 7;

// Durum değişkeni
int hareketDurumu = 0;

void setup() {
  // Durum izlemek için seri portu başlatıyoruz
  Serial.begin(9600);
  
  // Pin modlarını belirliyoruz
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // PIR sensöründen dijital veriyi okuyoruz (HIGH veya LOW)
  hareketDurumu = digitalRead(pirPin);
  
  // Durumu seri port ekranına yazdırıyoruz
  if (hareketDurumu == HIGH) {
    Serial.println("HAREKET ALGILANDI! Alarm Aktif!");
    
    // LED ve Buzzer'ı çalıştır
    digitalWrite(ledPin, HIGH);
    
    // Kesikli siren sesi etkisi oluşturuyoruz
    digitalWrite(buzzerPin, HIGH);
    delay(100);
    digitalWrite(buzzerPin, LOW);
    delay(100);
  } 
  else {
    Serial.println("Ortam Güvenli / Hareket Yok.");
    
    // LED ve Buzzer'ı kapat
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);
    
    delay(200); // Kararlılık için kısa gecikme
  }
}
