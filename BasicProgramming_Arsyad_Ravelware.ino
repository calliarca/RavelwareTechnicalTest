// Pin LED
// Pin 2 = LED merah
// Pin 3 = LED kuning
// Pin 4 = LED Hijau
// Pin 5 = LED Biru
// Pin 6 = LED Putih
const int ledPins[5] = {2, 3, 4, 5, 6};  
unsigned long intervals[5] = {270, 440, 710, 1330, 1850};
unsigned long previousMillis[5] = {0, 0, 0, 0, 0};
bool ledState[5] = {LOW, LOW, LOW, LOW, LOW};

void setup() {
  for (int i = 0; i < 5; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);
  }
}

void loop() {
  unsigned long currentMillis = millis();
  for (int i = 0; i < 5; i++) {
    if (currentMillis - previousMillis[i] >= intervals[i]) {
      previousMillis[i] = currentMillis;
      ledState[i] = !ledState[i];
      digitalWrite(ledPins[i], ledState[i]);
    }
  }
}
