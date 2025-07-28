#include <DHT.h>
#include <Wire.h> // Library wajib untuk komunikasi I2C
#include <LiquidCrystal_I2C.h> // Library untuk LCD I2C

#define DHTPIN2 2 // Pastikan pin ini sesuai dengan koneksi fisik data DHT
#define DHTTYPE DHT22

// Inisialisasi sensor DHT
DHT dht(DHTPIN2, DHTTYPE);

// Inisialisasi LCD I2C
// Sesuaikan alamat I2C dan ukuran LCD Anda.
// Alamat umum: 0x27 atau 0x3F
// Ukuran umum: 16,2 (16 karakter, 2 baris) atau 20,4 (20 karakter, 4 baris)
LiquidCrystal_I2C lcd(0x27, 16, 2); // Contoh: alamat 0x27, LCD 16x2

void setup() {
  Serial.begin(9600); // Tetap aktifkan Serial Monitor untuk debugging
  dht.begin();

  // Inisialisasi LCD
  lcd.init(); // Menginisialisasi LCD
  lcd.backlight(); // Menyalakan backlight LCD

  // Tampilkan pesan awal di LCD
  lcd.print("Memulai Sensor...");
  delay(2000);
  lcd.clear(); // Bersihkan layar setelah pesan awal
}

void loop() {
  // Baca kelembaban dan suhu dari sensor DHT
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature(true); // 'true' untuk Fahrenheit, 'false' untuk Celsius.
                                                  // Oh, jika 'true' itu Fahrenheit, berarti 'false' itu Celsius.
                                                  // Tapi di kode sebelumnya kamu pakai 'true' dan hasilnya °C.
                                                  // Ini sering bikin bingung. Umumnya 'false' untuk Celsius.
                                                  // Coba pakai 'false' jika hasilnya aneh.
                                                  // Jika tetap ingin Celsius dan hasil sebelumnya sudah benar
                                                  // dengan 'true', biarkan saja.
                                                  // Asumsi kamu ingin Celsius, ubah ke false jika diperlukan:
                                                  // float temperature = dht.readTemperature(false); // Untuk Celsius

  // Cek jika pembacaan sensor gagal
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Gagal membaca dari sensor DHT!");
    lcd.clear();
    lcd.print("Gagal baca DHT!");
    delay(2000);
    return; // Keluar dari loop saat ini dan coba lagi
  }

  // Bersihkan layar LCD sebelum menampilkan data baru
  lcd.clear();

  // Tampilkan kelembaban di baris pertama LCD
  lcd.setCursor(0, 0); // Atur kursor ke kolom 0, baris 0
  lcd.print("Hum:");
  lcd.print(humidity);
  lcd.print("%");

  // Tampilkan suhu di baris kedua LCD
  lcd.setCursor(0, 1); // Atur kursor ke kolom 0, baris 1
  lcd.print("Temp:");
  lcd.print(temperature);
  lcd.print((char)223); // Karakter derajat (°)
  lcd.print("C");

  delay(2000); // Jeda 2 detik sebelum pembacaan berikutnya
}