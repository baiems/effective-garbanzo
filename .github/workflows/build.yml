name: Build Arduino Sketch

on:
  push:
    branches: [ "main", "master" ]
  pull_request:
    branches: [ "main", "master" ]

jobs:
  build:
    runs-on: ubuntu-latest

    steps:
    - name: Checkout repository
      uses: actions/checkout@v4

    - name: Install Arduino CLI
      run: |
        curl -fsSL https://raw.githubusercontent.com/arduino/arduino-cli/master/install.sh | sh
        echo "$PWD/bin" >> $GITHUB_PATH

    - name: Initialize Arduino CLI configuration
      run: arduino-cli config init --additional-urls https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json

    - name: Install ESP32 Core
      run: |
        arduino-cli core update-index
        arduino-cli core install esp32:esp32

    - name: Install Required Libraries
      run: |
        arduino-cli lib install "Adafruit SSD1306"
        arduino-cli lib install "Adafruit GFX Library"

    - name: Compile Sketch
      run: |
        arduino-cli compile --fqbn esp32:esp32:esp32s3 tes layar/tes.ino --output-dir ./build

    - name: Upload Firmware Binary Artifact
      uses: actions/upload-artifact@v4
      with:
        name: firmware-esp32s3
        path: ./build/tes.ino.bin
