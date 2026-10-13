#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64 // Ubah ke 32 jika menggunakan OLED 128x32

// Deklarasi OLED (menggunakan I2C)
#define OLED_RESET    -1 
#define SCREEN_ADDRESS 0x3C // Alamat I2C umum (bisa 0x3D)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(115200);

  // Inisialisasi I2C (SDA = GPIO 8, SCL = GPIO 9 - sesuaikan dengan board Anda jika perlu)
   Wire.begin(40, 41); 

  // Inisialisasi OLED SSD1306
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 alokasi gagal!"));
    for(;;);
  }

  // Bersihkan buffer
  display.clearDisplay();

  // Konfigurasi Teks
  display.setTextSize(2);          // Ukuran teks
  display.setTextColor(SSD1306_WHITE); // Warna teks
  display.setCursor(10, 25);       // Posisi kursor (X, Y)
  display.println(F("Hello"));     // Teks yang ditampilkan

  // Tampilkan ke layar
  display.display();
}

void loop() {
  // Tidak ada proses berulang di sini
}
