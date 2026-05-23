/*
  Ders 23: Su Seviye Kontrol Devresi - Yagmur Alarmi 🤖🔆🌧️
  
  Bu projede su seviye sensörünü kullanarak suyun yükseklik seviyesini (0-750 arası)
  ölçüyoruz. Su seviyesine bağlı olarak 5 farklı renkte LED sırayla yanar
  ve en yüksek seviyede buzzer alarm çalar.
  
  Bağlantılar:
  - Su Seviye Sensörü Sinyal (S) ➡️ A0 pini
  - LED 1 (Yeşil) ➡️ Pin 8
  - LED 2 (Mavi)  ➡️ Pin 9
  - LED 3 (Sarı)  ➡️ Pin 10
  - LED 4 (Beyaz) ➡️ Pin 11
  - LED 5 (Kırmızı)➡️ Pin 12
  - Buzzer        ➡️ Pin 7
*/

const int suPin = A0;
const int ledPins[] = {8, 9, 10, 11, 12};
const int buzzerPin = 7;
const int numLeds = 5;

// Su seviyesi eşik değerleri
const int esikler[] = {100, 250, 400, 550, 680};

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
  // Sensörden analog değer okunuyor
  int suDegeri = analogRead(suPin);
  
  Serial.print("Su Seviyesi Degeri: ");
  Serial.println(suDegeri);
  
  // LED'leri ve buzzer'ı başlangıçta kapatalım
  for (int i = 0; i < numLeds; i++) {
    digitalWrite(ledPins[i], LOW);
  }
  digitalWrite(buzzerPin, LOW);
  
  // Kademeli kontrol
  if (suDegeri >= esikler[0]) {
    digitalWrite(ledPins[0], HIGH); // 1. LED
  }
  if (suDegeri >= esikler[1]) {
    digitalWrite(ledPins[1], HIGH); // 2. LED
  }
  if (suDegeri >= esikler[2]) {
    digitalWrite(ledPins[2], HIGH); // 3. LED
  }
  if (suDegeri >= esikler[3]) {
    digitalWrite(ledPins[3], HIGH); // 4. LED
  }
  if (suDegeri >= esikler[4]) {
    digitalWrite(ledPins[4], HIGH); // 5. LED
    digitalWrite(buzzerPin, HIGH);  // Buzzer alarm
  }
  
  delay(100);
}
