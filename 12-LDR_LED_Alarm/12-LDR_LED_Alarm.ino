/*
  Ders 12: LDR (Işık Sensörü) ile Sokak Lambası ve Buzzer Alarm Devresi
  Açıklama: A0 analog pinine bağlı LDR sensöründen okunan ışık şiddeti 
            belirli bir eşik değerin altına düştüğünde (hava karardığında), 
            Pin 7'deki LED'i yakar ve Pin 8'deki Buzzer'ı öttürür.
  
  Pin Tanımlamaları:
    - LDR Sensörü: A0 (Analog Giriş, 10k pull-down dirençli)
    - LED: Pin 7 (Dijital Çıkış)
    - Buzzer: Pin 8 (Dijital Çıkış)
  
  Yazar: sultanamed
*/

// Pin Tanımlamaları
const int ldrPin = A0;
const int ledPin = 7;
const int buzzerPin = 8;

// Eşik Işık Şiddeti Değeri (Ortama göre değiştirilebilir)
const int esikDeger = 300; 

void setup() {
  // Seri haberleşmeyi başlatıyoruz (LDR değerlerini okumak için)
  Serial.begin(9600);
  
  // Çıkış pinlerini ayarlıyoruz
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // LDR'den analog veriyi okuyoruz (0 - 1023)
  int isikSeviyesi = analogRead(ldrPin);
  
  // Okunan değeri seri port ekranına yazdırıyoruz
  Serial.print("Işık Seviyesi: ");
  Serial.println(isikSeviyesi);
  
  // Eğer ışık seviyesi eşik değerin altındaysa (karanlıksa)
  if (isikSeviyesi < esikDeger) {
    digitalWrite(ledPin, HIGH);     // LED'i yak
    digitalWrite(buzzerPin, HIGH);  // Buzzer'ı çal
  } 
  // Işık seviyesi normalse (aydınlıksa)
  else {
    digitalWrite(ledPin, LOW);      // LED'i söndür
    digitalWrite(buzzerPin, LOW);   // Buzzer'ı sustur
  }
  
  delay(100); // 100ms okuma kararlılığı beklemesi
}
