// Measure water tank water level:
float waterTank() {
  currentMillisUltra = millis();                             // Store current system running time
  digitalWrite(ultraMainTrig, LOW);                          // Reset the Trigger Pin for 2ms
  if (currentMillisUltra - previousMillisUltra >= 2) {
    digitalWrite(ultraMainTrig, HIGH);                       // Send ultrasonic wave
  }
  if (currentMillisUltra - previousMillisUltra >= 20) {   
    digitalWrite(ultraMainTrig, LOW);                        // Stop ultrasonic wave transmition after 20ms
  }
  durationUltra = pulseIn(ultraMainEcho, HIGH);              // Reads the echoPin, returns the sound wave travel time in microseconds
  distanceUltra = durationUltra * 0.034 / 2;                 // Calculating the distance in cm
  previousMillisUltra = currentMillisUltra;                  // Resetting timer             
  Serial.println(distanceUltra);                             // Debugging
  return(distanceUltra);
}

// Measure collection container water level:
float waterContainer() {
  currentMillisUltra = millis();                             // Store current system running time
  digitalWrite(ultraAuxTrig, LOW);                           // Reset the Trigger Pin for 2ms
  if (currentMillisUltra - previousMillisUltra >= 2) {
    digitalWrite(ultraAuxTrig, HIGH);                        // Send ultrasonic wave
  }
  if (currentMillisUltra - previousMillisUltra >= 20) {   
    digitalWrite(ultraAuxTrig, LOW);                         // Stop ultrasonic wave transmition after 20ms
  }
  durationUltra = pulseIn(ultraAuxEcho, HIGH);               // Reads the echoPin, returns the sound wave travel time in microseconds
  distanceUltra = durationUltra * 0.034 / 2;                 // Calculating the distance in cm
  previousMillisUltra = currentMillisUltra;                  // Resetting timer             
  Serial.println(distanceUltra);                             // Debugging
  return(distanceUltra);
}

// Measures the brighntess via the average value of ldr1 and ldr2
int envBrightness() {
  brightness = ldr1 + ldr2;                                  // Summarize ldr1 and ldr2
  brightness = brightness / 2;                               // Calculate the average value
  return brightness;
}

// Measures the soil moisture and maps it into a percentage value:
int soilMoisture() {
  moisA = analogRead(moisture);
  moisP = map(moisA, 1023, 0, 0, 100);
  return moisP;
}

// Display a warning message for minimum water level:
void displayWarningMinimum() {
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("Wasserlevel MIN!");
}

// Display a warning message for maximum water level:
void displayWarningMaximum() {
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("Wasserlevel MAX");
}

// Display a information message for stating that everything is ok:
void displayInformation() {
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("OK.");
}
