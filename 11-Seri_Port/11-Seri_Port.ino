/*
  Ders 11: mBlock 4 ile Seri Port (Seri Monitör) Kullanımı
  Açıklama: Bilgisayar ile Arduino arasında seri haberleşme kurarak, 
            Seri Port Ekranı (Serial Monitor) üzerinden metinsel veri 
            gönderilmesini ve izlenmesini gösteren temel çalışma.
  
  Baud Rate: 9600 (Haberleşme hızı)
  
  Yazar: sultanamed
*/

void setup() {
  // Seri haberleşmeyi 9600 baud hızında başlatıyoruz
  Serial.begin(9600);
  
  // Program başladığında bir kez "Kodlama" mesajı gönderiyoruz
  Serial.println("Kodlama");
}

void loop() {
  // Eğer sürekli olarak veri göndermek istersek, loop içerisine yazıp 
  // bekleme ekleyebiliriz:
  /*
  Serial.println("Kodlama");
  delay(1000); // 1 saniye bekle
  */
}
