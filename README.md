🌡️ Monitor Suhu & Kelembaban dengan DHT22 dan LCD I2C
Proyek ini adalah simulasi Arduino sederhana yang dirancang untuk mengukur suhu dan kelembaban menggunakan sensor DHT22, dan menampilkannya secara real-time pada layar LCD I2C. Cocok untuk pemula yang ingin mempelajari dasar-dasar pemantauan lingkungan menggunakan Arduino.

✨ Fitur Utama
✅ Pembacaan suhu dalam derajat Celsius (°C)
✅ Pembacaan kelembaban relatif dalam persen (%)
✅ Tampilan data secara ringkas dan jelas pada LCD 16x2 atau 20x4 I2C
✅ Kode yang mudah dipahami dan dimodifikasi
✅ Notifikasi error di LCD dan Serial Monitor saat pembacaan sensor gagal

🔧 Komponen yang Dibutuhkan
| Komponen                       | Keterangan                                                    |
| ------------------------------ | ------------------------------------------------------------- |
| 🟦 Arduino Board               | Uno, Nano, atau board kompatibel lainnya                      |
| 🌡️ Sensor DHT22                | Untuk pembacaan suhu & kelembaban (bisa diganti dengan DHT11) |
| 📟 LCD I2C (16x2 / 20x4)       | Untuk menampilkan data secara real-time                       |
| 🔌 Kabel Jumper                | Untuk menyambungkan komponen                                  |
| 🔲 Breadboard (opsional)       | Membantu merapikan sambungan                                  |
| 🟨 Resistor 10K Ohm (opsional) | *Pull-up resistor* jika DHT22 tidak memiliki bawaan           |


📝 Catatan: Jika kamu menggunakan DHT11, ubah #define DHTTYPE DHT22 menjadi DHT11 di dalam kode.

🔌 Diagram Pengkabelan
📥 DHT22 ke Arduino:
VCC / Vout ➜ 5V (Arduino)

GND ➜ GND (Arduino)

Data ➜ Digital Pin 2 (Arduino)

💡 Jika tidak ada resistor internal, pasang resistor 10K Ohm antara pin Data dan VCC.

📤 LCD I2C ke Arduino:
VCC ➜ 5V (Arduino)

GND ➜ GND (Arduino)

SDA ➜ A4 (Arduino Uno/Nano)

SCL ➜ A5 (Arduino Uno/Nano)

📚 Instalasi Library
Untuk menjalankan proyek ini, kamu perlu menginstal dua library berikut melalui Arduino IDE:

Buka Arduino IDE

Pergi ke Sketch > Include Library > Manage Libraries...

Cari dan instal:

🔹 DHT sensor library – by Adafruit
🔹 LiquidCrystal I2C – by Frank de Brabander atau DFRobot
