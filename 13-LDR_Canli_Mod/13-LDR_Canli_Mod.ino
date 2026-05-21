/*
  Ders 13: LDR ile Canlı Mod (Live Mode) Sokak Lambası
  Açıklama: Bu kod, mBlock programının Canlı Mod (Live Mode) özelliğiyle 
            entegre çalışarak LDR'den okunan verileri seri port üzerinden 
            mBlock sahnesine iletir. mBlock sahnesindeki gece/gündüz 
            arka planı ve kukla konuşması bu verilerle anlık tetiklenir.
  
  Pin Tanımlamaları:
    - LDR Sensörü: A0 (Analog Giriş)
    - LED: Pin 7 (Dijital Çıkış)
  
  Yazar: sultanamed
*/

// Pin Tanımlamaları
const int ldrPin = A0;
const int ledPin = 7;

// mBlock Canlı Modda kullanılan eşik ışık değeri
const int esikDeger = 350;

void setup() {
  // Canlı mod iletişimi ve veri izleme için seri port başlatılır
  Serial.begin(9600);
  
  // LED pini çıkış olarak ayarlanır
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // LDR'den analog veriyi oku (0 - 1023)
  int isikSeviyesi = analogRead(ldrPin);
  
  // Veriyi mBlock sahnesinin okuyabilmesi için seri porttan gönderiyoruz
  Serial.println(isikSeviyesi);
  
  // Arduino tarafında da LED kontrolünü bağımsız sürdürüyoruz
  if (isikSeviyesi < esikDeger) {
    digitalWrite(ledPin, HIGH); // Karanlıkta LED Açık
  } else {
    digitalWrite(ledPin, LOW);  // Aydınlıkta LED Kapalı
  }
  
  delay(100); // Kararlı bir veri akışı için bekleme
}
