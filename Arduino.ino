// pinnen
const int pinGroen = 8;
const int pinKnop  = 7;

// toestanden
const int LEDUIT_KNOPLOS = 0;
const int LEDAAN_KNOPIN  = 1;
const int LEDAAN_KNOPLOS = 2;
const int LEDUIT_KNOPIN  = 3;

int toestand;
int vorigeKnop;
int huidigeKnop;

void setup() {
  pinMode(pinGroen, OUTPUT);
  pinMode(pinKnop, INPUT);         // externe pull-down op pinKnop
  vorigeKnop = digitalRead(pinKnop);
  toestand   = LEDUIT_KNOPLOS;
  digitalWrite(pinGroen, LOW);
}

void loop() {
  huidigeKnop = digitalRead(pinKnop);

  // detecteer alleen rising edge: LOW → HIGH
  if (vorigeKnop == LOW && huidigeKnop == HIGH) {
    switch (toestand) {
      case LEDUIT_KNOPLOS:
        toestand = LEDAAN_KNOPIN;
        digitalWrite(pinGroen, HIGH);
        break;
      case LEDAAN_KNOPIN:
        toestand = LEDAAN_KNOPLOS;
        // LED blijft aan
        break;
      case LEDAAN_KNOPLOS:
        toestand = LEDUIT_KNOPIN;
        digitalWrite(pinGroen, LOW);
        break;
      case LEDUIT_KNOPIN:
        toestand = LEDUIT_KNOPLOS;
        // LED blijft uit
        break;
    }
  }

  vorigeKnop = huidigeKnop;
  delay(10);  // korte debounce
}
