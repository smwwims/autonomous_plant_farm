// Definitions of I/O pins:
#define ultraMainTrig A0  // Ultrasonic Sensor Main Water Tank Trigger Pin
#define ultraMainEcho A1  // Ultrasonic Sensor Main Water Tank Echo Pin
#define ldr1          A2  // Brighntess Sensor 1
#define ldr2          A3  // Brightness Sensor 2
#define moisture1     A4  // Moisture Sensor 1
#define moisture2     A5  // Moisture Sensor 2
#define pumpMain      7   // Relay (NO) for Main Water Pump 
#define pumpAux       8   // Relay (NO) for Auxiliary Water Pump
#define lamp          9   // Relay (NO) for Plant Lamp
#define ultraAuxTrig  10  // Ultrasonic Sensor Auxiliary Water Tank Trigger Pin
#define ultraAuxEcho  11  // Ultrasonic Sensor Auxiliary Tank Trigger Pin

// Definitions of switch states:
#define normal        0

// Definitions of static values:

// Setting Pin Modes:
void setup() {
  pinMode(ultraMainTrig, OUTPUT);
  pinMode(ultraMainEcho, INPUT);
  pinMode(ldr1, INPUT);
  pinMode(ldr2,INPUT);
  pinMode(moisture1, INPUT);
  pinMode(moisture2, INPUT);
  pinMode(pumpMain, OUTPUT);
  pinMode(pumpAux, OUTPUT);
  pinMode(lamp, OUTPUT);
  pinMode(ultraAuxTrig, OUTPUT);
  pinMode(ultraAuxEcho, INPUT);
}
