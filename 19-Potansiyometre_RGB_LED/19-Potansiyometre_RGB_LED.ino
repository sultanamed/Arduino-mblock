/*
  Ders 19: Potansiyometre ile RGB LED Kontrolü 🤖🔆
  
  Bu projede potansiyometreden okunan analog değere (0-1023) göre
  RGB LED'in rengini değiştiriyoruz.
  
  Renk Aralıkları:
  - 0 - 200   : Mavi (Blue)
  - 201 - 400 : Yeşil (Green)
  - 401 - 600 : Kırmızı (Red)
  - 601 - 800 : Fuşya (Magenta)
  - 801 - 1023: Zeytin Yeşili / Sarı (Yellow)
*/

const int potPin = A0;      // Potansiyometre orta ucu A0 pinine bağlı
const int redPin = 9;       // RGB Led Kırmızı pini (PWM destekli pindir)
const int greenPin = 10;    // RGB Led Yeşil pini (PWM destekli pindir)
const int bluePin = 11;     // RGB Led Mavi pini (PWM destekli pindir)

void setup() {
  // Pin modları ayarlanıyor
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  
  // Seri haberleşme başlatılıyor
  Serial.begin(9600);
}

void loop() {
  // Potansiyometreden analog değer okunuyor
  int potDeger = analogRead(potPin);
  
  // Değer seri monitöre yazdırılıyor
  Serial.print("Potansiyometre Degeri: ");
  Serial.println(potDeger);
  
  // Ortak katot RGB LED için renk belirleme
  if (potDeger >= 0 && potDeger <= 200) {
    // Mavi
    setColor(0, 0, 255);
  } 
  else if (potDeger >= 201 && potDeger <= 400) {
    // Yeşil
    setColor(0, 255, 0);
  } 
  else if (potDeger >= 401 && potDeger <= 600) {
    // Kırmızı
    setColor(255, 0, 0);
  } 
  else if (potDeger >= 601 && potDeger <= 800) {
    // Fuşya (Kırmızı + Mavi)
    setColor(255, 0, 255);
  } 
  else {
    // Sarı / Zeytin Yeşili (Kırmızı + Yeşil)
    setColor(255, 255, 0);
  }
  
  delay(50); // Kararlılık için kısa bir gecikme
}

// RGB LED'e renk değerlerini yazan yardımcı fonksiyon
void setColor(int red, int green, int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}
