/*
  Ders 29: MQ-5 Gaz Sensörü ile Doğal Gaz Kaçağı Alarmı 🤖💨🚨
  
  Bu projede MQ-5 gaz sensörü kullanarak ortamdaki yanıcı gaz/doğal gaz seviyesini
  ölçüyoruz. Ortamda tehlikeli miktarda gaz algılandığında Kırmızı LED ve Buzzer ile
  kesikli uyarı verirken, ortam güvenli iken Yeşil LED sabit yanacaktır.
  
  Bağlantılar:
  - MQ-5 Gaz Sensörü VCC ➡️ Arduino 5V
  - MQ-5 Gaz Sensörü GND ➡️ Arduino GND
  - MQ-5 Gaz Sensörü AO (Analog Çıkış) ➡️ Arduino A0 pini
  
  - Kırmızı LED ➡️ Dijital Pin 8
  - Yeşil LED   ➡️ Dijital Pin 9
  - Buzzer      ➡️ Dijital Pin 7
  
  Eşik Değeri:
  - Sensörden okunan analog değer genellikle temiz havada 100-250 arasındadır.
  - Gaz kaçağı durumunda bu değer hızla yükselir. Bu projede eşik değerini 400 olarak belirledik.
*/

// Pin tanımlamaları
const int gazPin = A0;      // MQ-5 sensör analog pini
const int kirmiziLed = 8;   // Tehlike LED'i
const int yesilLed = 9;     // Güvenli LED'i
const int buzzer = 7;       // Alarm hoparlörü

// Eşik gaz değeri (Kalibrasyona göre ayarlanabilir)
const int esikDegeri = 400;

void setup() {
  // LED ve Buzzer pinlerini çıkış yapıyoruz
  pinMode(kirmiziLed, OUTPUT);
  pinMode(yesilLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  
  // Hata ayıklama için seri haberleşmeyi başlatıyoruz
  Serial.begin(9600);
}

void loop() {
  // Sensörden analog gaz değerini okuyoruz
  int gazDegeri = analogRead(gazPin);
  
  // Seri port ekranına gaz seviyesini yazdırıyoruz
  Serial.print("Gaz Seviyesi: ");
  Serial.println(gazDegeri);
  
  // Gaz seviyesi eşik değerini aşarsa ALARM ver
  if (gazDegeri > esikDegeri) {
    digitalWrite(yesilLed, LOW); // Yeşil LED söner
    
    // Kırmızı LED ve Buzzer kesikli olarak (Pulse) uyarı verir
    digitalWrite(kirmiziLed, HIGH);
    digitalWrite(buzzer, HIGH);
    delay(200);
    digitalWrite(kirmiziLed, LOW);
    digitalWrite(buzzer, LOW);
    delay(200);
  }
  else {
    // Gaz kaçağı yoksa
    digitalWrite(yesilLed, HIGH); // Yeşil LED yanar
    digitalWrite(kirmiziLed, LOW); // Kırmızı LED söner
    digitalWrite(buzzer, LOW);    // Buzzer susar
    delay(100);
  }
}
