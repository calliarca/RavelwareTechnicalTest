#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

// Fungsi pengganti millis()
unsigned long millis() {
    static auto start = chrono::steady_clock::now();
    auto now = chrono::steady_clock::now();
    return chrono::duration_cast<chrono::milliseconds>(now - start).count();
}

// Class LED
class LED {
private:
    int pin;
    unsigned long interval;
    unsigned long previousMillis;
    bool state;

public:
    LED(int p, unsigned long i) {
        pin = p;
        interval = i;
        previousMillis = 0;
        state = false;
    }

    void update() {
        unsigned long currentMillis = millis();
        if (currentMillis - previousMillis >= interval) {
            previousMillis = currentMillis;
            state = !state;
            digitalWrite();
        }
    }

    void digitalWrite() {
        cout << "LED pin " << pin << " -> " << (state ? "ON" : "OFF") << endl;
    }
};

// Setup LED
LED leds[] = {
    LED(2, 270),   // Merah
    LED(3, 440),   // Kuning
    LED(4, 710),   // Hijau
    LED(5, 1330),  // Biru
    LED(6, 1850)   // Putih
};

void setup() {
    cout << "Inisialisasi LED..." << endl;
}

void loop() {
    for (auto &led : leds) {
        led.update();
    }
    this_thread::sleep_for(chrono::milliseconds(10));
}

int main() {
    setup();
    while (true) {
        loop();
    }
    return 0;
}
