// pinnen
const int pinRood = 12;
const int pinOranje = 10;
const int pinGroen = 8;
const int pinKnop = 7;

// variabelen voor actuatoren
int waardeKnop = LOW;
bool voetgangerWacht = false;

// variabelen voor toestanden
const int LEDUIT_KNOPLOS = 1;
const int LEDAAN_KNOPIN = 2;
const int LEDAAN_KNOPLOS = 3;
const int LEDUIT_KNOPIN = 4;
int toestand = LEDUIT_KNOPLOS;



void setup() { // wordt 1x uitgevoerd

// init serial monitor
Serial.begin(9600)
Serial.println(“start”)

// pinmodes
pinMode(pinRood  , OUTPUT);
pinMode(pinOranje, OUTPUT);
pinMode(pinGroen , OUTPUT); 
pinMode(pinKnop  , INPUT); 

  }
  
  void loop() { // wordt oneindig herhaald
    // sensoren lezen
    if (toestand == LEDUIT_KNOPLOS) {
        if (millis() - toestandStartTijd > 5000) {
          toestandStartTijd = millis();
          toestand = LEDAAN_KNOPIN;
         }
      }
      if (toestand == ORANJE) {
        if (millis() - toestandStartTijd > 1000)
  }

  }