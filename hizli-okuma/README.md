# Akış — PDF Hızlı Okuma

Mac / iPad tabletinizde PDF yükleyip **RSVP** (Rapid Serial Visual Presentation) tekniğiyle hızlı okumanızı sağlayan web uygulaması.

## Özellikler

- PDF yükleme (sürükle-bırak veya dosya seç)
- Kelime kelime RSVP + ORP (odak harfi) vurgusu
- 100–800 WPM hız ayarı
- 1–3 kelimelik grup okuma
- Oynat / duraklat, atla, ilerleme çubuğu
- Dosya tarayıcıda işlenir; sunucuya gönderilmez

## Çalıştırma

```bash
cd hizli-okuma
npm install
npm run dev
```

Tarayıcıda açılan adresi iPad / Mac tabletinizde Safari ile açın. Ana ekrana ekleyerek uygulama gibi kullanabilirsiniz.

## Derleme

```bash
npm run build
npm run preview
```

## Notlar

- Metin içeren PDF’ler desteklenir. Taranmış (yalnızca görüntü) PDF’lerde OCR yoktur.
- Klavye: Boşluk = oynat/duraklat, ← → = atla, ↑ ↓ = hız.
