// Definitions of I/O pins:
#define ldr1          A0  // Brighntess Sensor 1
#define ldr2          A1  // Brightness Sensor 2
#define moisture      A2  // Moisture Sensor
#define pumpMain      7   // Relay (NO) for Main Water Pump 
#define pumpAux       8   // Relay (NO) for Auxiliary Water Pump
#define lamp          9   // Relay (NO) for Plant Lamp
#define ultraAuxTrig  10  // Ultrasonic Sensor Auxiliary Water Tank Trigger Pin
#define ultraAuxEcho  11  // Ultrasonic Sensor Auxiliary Tank Trigger Pin
#define ultraMainTrig 12  // Ultrasonic Sensor Main Water Tank Trigger Pin
#define ultraMainEcho 13  // Ultrasonic Sensor Main Water Tank Echo Pin

// Definitions of switch states:
#define normal        0
#define watering      1
#define dewatering    2

// Definitions of variables:
int state = 0;                           // stores the current running state of the state machine
int brightness = 1023;                   // used for the calculation of the environment brightness
int moisA;                               // used for the analog measurement of the soil moisture
int moisP;                               // used for moisture conversion from analog to percentage
unsigned long previousMillisUltra = 0;   // stores time since the last ultrasonic distance measurement
unsigned long currentMillisUltra = 0;    // stores current system running time
long durationUltra;                      // time between trigger and echo return of the ultrasonic sensor
float distanceUltra;                     // measured distance by the ultrasonic sensor in cm
int lastLampState = 0;                   // used to store the last state of the lamp 0 for off and 1 for on
int brightnessLevel = 800;               // adjust the brightness level to decide when the lamps are being switched on
int lastDisplayState = 3;                // display state changes only if a new information should be presented

// Setting Pin Modes:
void setup() {
  pinMode(ultraMainTrig, OUTPUT);
  pinMode(ultraMainEcho, INPUT);
  pinMode(ldr1, INPUT);
  pinMode(ldr2,INPUT);
  pinMode(moisture, INPUT);
  pinMode(pumpMain, OUTPUT);
  pinMode(pumpAux, OUTPUT);
  pinMode(lamp, OUTPUT);
  pinMode(ultraAuxTrig, OUTPUT);
  pinMode(ultraAuxEcho, INPUT);
  Serial.begin(9600);               // Debugging
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x32)
  display.clearDisplay();
}
