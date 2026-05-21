/*
  Ders 08: Değişken Oluşturma ve Kullanımı (Variables)
  Açıklama: Arduino C/C++ programlamada değişken tanımlama, veri tipleri 
            ve seri haberleşme (Serial Monitor) üzerinden değişken değerlerini 
            ekrana yazdırmayı gösteren temel kavram uygulaması.
  
  Yazar: sultanamed
*/

// Küresel (Global) Değişken Tanımlamaları
int mesafe = 100;        // Tam sayı veri tipi (mesafe)
float sicaklik = 24.5;   // Ondalıklı sayı veri tipi
char ledDurum = 'A';     // Tek karakter veri tipi ('A'çık / 'K'apalı)
bool sistemCalisiyor = true; // Mantıksal veri tipi (true/false)

void setup() {
  // Seri port ekranını 9600 baud hızında başlatıyoruz
  Serial.begin(9600);
  
  // Değişken değerlerini seri port ekranına yazdırıyoruz
  Serial.println("--- Robotist Değişken Tanıtım Devresi ---");
  
  Serial.print("Mesafe Değeri: ");
  Serial.print(mesafe);
  Serial.println(" cm");
  
  Serial.print("Sıcaklık Değeri: ");
  Serial.print(sicaklik);
  Serial.println(" C");
  
  Serial.print("LED Durumu: ");
  Serial.println(ledDurum);
  
  Serial.print("Sistem Çalışıyor mu?: ");
  Serial.println(sistemCalisiyor ? "Evet" : "Hayır");
}

void loop() {
  // Bu uygulamada döngü içerisinde işlem yapmıyoruz
}
