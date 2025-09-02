const int pinLED = 9;
const int pinPompe = 3;
const int pinPot = A1;

unsigned long previousMicros = 0;
unsigned long period_us = 100000; // 10 Hz par défaut
unsigned long ton_us = 5000;      // 5% dce 100000 µs

bool ledState = false;

void setup() {
  pinMode(pinLED, OUTPUT);
  pinMode(pinPompe, OUTPUT);
  analogWrite(pinPompe, 240); // PWM 50% pour pompe
}

void loop() {
  int valPot = analogRead(pinPot);
  int freq = map(valPot, 0, 1023, 25, 100);
  period_us = 1000000UL / freq;
  ton_us = period_us * 0.05;

  unsigned long currentMicros = micros();

  if (ledState && (currentMicros - previousMicros >= ton_us)) {
    digitalWrite(pinLED, HIGH);
    ledState = false;
    previousMicros = currentMicros;
  } else if (!ledState && (currentMicros - previousMicros >= (period_us - ton_us))) {
    digitalWrite(pinLED, LOW);
    ledState = true;
    previousMicros = currentMicros;
  }
}
