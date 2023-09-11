#define TRIGGER_PIN 9
#define ECHO_PIN 10
#define BUTTON_PIN 7

const int melody[] = {
  261, 294, 330, 349, 392, 440, 494, 523
};

int melodyLength = sizeof(melody) / sizeof(melody[0]);
int currentNote = 0;

void setup() {
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(BUTTON_PIN) == LOW) {
    digitalWrite(TRIGGER_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIGGER_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIGGER_PIN, LOW);
    long duration = pulseIn(ECHO_PIN, HIGH);

    int distance = duration / 29 / 2;
    int note = map(distance, 2, 20, 0, 7);

    if (note < 0) {
      note = 0;
    } else if (note >= melodyLength) {
      note = melodyLength - 1;
    }

    tone(8, melody[note]); // Predvajaj frekvenco na pinu 8
    delay(200);
    noTone(8); // Izklopi zvok
  }
}

