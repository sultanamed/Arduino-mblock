# Ders 02: Trafik Lambası 🚦

Çocukların günlük hayatta karşılaştıkları sistemlerin çalışma mantığını çözmelerini sağlayan, sıralı düşünme (algoritma) ve zamanlama becerilerini geliştiren harika bir proje! Robotist’in Trafik Lambası uygulaması, üç farklı LED'in belirli bir düzen ve süreyle kontrol edilmesini öğreterek geleceğin akıllı şehir teknolojilerine ilk adımı attırıyor.

Bu projeyle çocuklar; çoklu bileşen kontrolünü, zamanlama yönetimini ve sistemli düşünmeyi öğrenir. Kendi elleriyle tasarladıkları trafik ışıkları simülasyonu, problem çözme ve proje üretme yeteneklerini güçlendirir!

**Robotist ile keşfet, öğren, eğlen!**

---

## ⚙️ Gerekli Elemanlar

1. **Arduino Uno** (Zekamızı temsil eden kontrol kartı)
2. **Breadboard** (Devremizi kuracağımız delikli tahta)
3. **3x LED** (Kırmızı, Sarı, Yeşil)
4. **3x 220Ω Direnç** (LED'lerimizi koruyan dirençlerimiz)
5. **Jumper Kablolar** (Bağlantı yollarımız)

---

## 🔌 Devre Şeması

Bu projede kırmızı, sarı ve yeşil LED'lerimizin her birini farklı dijital pinlere bağlayarak bağımsız kontrol ediyoruz:
*   LED'lerin katot (-) bacaklarını dirençler üzerinden **GND** hattına bağlayın.
*   **Kırmızı LED** anot (+) ucunu -> Arduino **Pin 5**'e bağlayın.
*   **Sarı LED** anot (+) ucunu -> Arduino **Pin 6**'ya bağlayın.
*   **Yeşil LED** anot (+) ucunu -> Arduino **Pin 7**'ye bağlayın.

![Devre Şeması](./images/schematic.jpg)

---

## 🧩 mBlock Blok Kodları

mBlock 5 ile trafik lambası döngüsünü blokları ardışık sıralayarak tasarlıyoruz. Çocuklar bekleme sürelerini değiştirerek devrenin çalışma hızını diledikleri gibi test edebilirler:

*   **Kırmızı Işık:** Kırmızı LED (Pin 5) YÜKSEK, Sarı ve Yeşil LED'ler DÜŞÜK konumda -> 3 saniye bekle.
*   **Hazırlanma:** Sarı LED (Pin 6) de kırmızıyla birlikte YÜKSEK konuma gelir -> 1 saniye bekle.
*   **Yeşil Işık (Geç):** Yeşil LED (Pin 7) YÜKSEK, Kırmızı ve Sarı DÜŞÜK konumda -> 3 saniye bekle.
*   **Yavaşlama/Durma:** Yeşil LED söner, Sarı LED (Pin 6) YÜKSEK olur -> 1 saniye bekle.

![mBlock Blokları](./images/mblock.jpg)

---

## 💻 Arduino C/C++ Kodları

Projenin Arduino IDE ile yüklenebilecek metin tabanlı C/C++ kodları:

```cpp
/*
  Ders 02: Trafik Lambası Uygulaması
*/

const int kirmiziLed = 5;
const int sariLed = 6;
const int yesilLed = 7;

void setup() {
  // LED pinlerini çıkış olarak ayarlıyoruz
  pinMode(kirmiziLed, OUTPUT);
  pinMode(sariLed, OUTPUT);
  pinMode(yesilLed, OUTPUT);
}

void loop() {
  // 1. Durum: Sadece Kırmızı ışık yanar (3 saniye)
  digitalWrite(kirmiziLed, HIGH);
  digitalWrite(sariLed, LOW);
  digitalWrite(yesilLed, LOW);
  delay(3000);
  
  // 2. Durum: Kırmızı ile birlikte Sarı ışık yanar (1 saniye)
  digitalWrite(sariLed, HIGH);
  delay(1000);
  
  // 3. Durum: Kırmızı ve Sarı söner, Yeşil ışık yanar (3 saniye)
  digitalWrite(kirmiziLed, LOW);
  digitalWrite(sariLed, LOW);
  digitalWrite(yesilLed, HIGH);
  delay(3000);
  
  // 4. Durum: Yeşil söner, Sarı ışık tek başına yanar (1 saniye)
  digitalWrite(yesilLed, LOW);
  digitalWrite(sariLed, HIGH);
  delay(1000);
}
```

---

## 🌐 Tinkercad Simülasyonu

Projeyi bilgisayarınızda kurmadan çevrimiçi simüle etmek isterseniz:
👉 **[Tinkercad Devresini İncele](https://www.tinkercad.com/)** *(Buraya kendi Tinkercad linkinizi ekleyebilirsiniz)*
