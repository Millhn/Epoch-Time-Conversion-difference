# Epoch-Time-Conversion-difference
Tarih Zaman Farkı Hesaplayıcı Kullanıcı tarafından girilen iki tarih arasındaki kesin zaman farkını hesaplayan bir C programı. Program, tarihleri çağ saatine dönüştürür ve farkı gün, saat, dakika ve saniye dahil olmak üzere birden çok formatta görüntüler. Örneğin günlük hayattaki problemleri çözmek için kullanışlı olabilir: 
* İş veya Çalışma Oturumları için Zaman Takibi
* Yaş Hesaplama
## 🚀 Özellikler

1970'ten sonraki herhangi iki tarih arasındaki zaman farkını hesaplama (Unix dönemi) Tarih ve saat bileşenleri için giriş doğrulama Sonuçları hem yerel saat hem de dönem saati formatlarında görüntüleme Zaman farklarını günlere, saatlere, dakikalara ve saniyelere ayırma Geçersiz tarih girişleri için hata işleme

## 🚀 Gereksinimler

* C derleyicisi (GCC önerilir)
* Standart C kütüphaneleri:
  * `stdio.h`
  * `stdlib.h`
  * `time.h`
## 🚀 Program Yapısı

* `struct`: Tarih ve saat bileşenlerini saklar
* `union`: DateTime veya epoch zamanını saklamak için esneklik sağlar
* `mktime()`: DateTime'ı epoch zamanına dönüştürür
* `difftime()`: iki tarih arasındaki farkı hesaplar
* `main()`: Kullanıcı girdisini ve program akışını yönetir

## 🚀 Hata İşleme
* Program temel hata işlemeyi içerir:
  * Tarih/saat bileşenleri için giriş aralıklarını doğrular
  * Epoch zamana dönüştürürken dönüştürme hatalarını kontrol eder
  * Geçersiz girişler için uygun hata mesajlarını döndürür
## 🚀 Sınırlamalar
* Yalnızca 1 Ocak 1970'ten sonraki tarihleri işler (Unix dönem sınırlaması)
* Zaman dilimi dönüşümlerini işlemez
* Temel giriş doğrulaması (30 Şubat gibi geçersiz tarihleri kontrol etmez)
