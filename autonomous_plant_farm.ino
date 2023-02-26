/* Project:       Autonomous Plant Farm  
 * Made by:       Simon M. Wimmer (@smwwims)
 * Sponsored by:  The Hack Club (Winter Hardware Wonderland)
 * Details:       https://github.com/hackclub/winter/blob/main/smwwims.md
 * 
 * Summary:
 *  A fully automatic smart garden powered by moisture sensors, light sensors, ultrasonic sensors
 *  water pumps and an Arduino. The water supply is regulated based on the moisture level measured
 *  by the moisture sensor. The plant lamps are regulated based on the environment brightness
 *  measured by the light sensors.
 *  
 *  Hardware:
 *    Board               Arduino Uno    https://docs.arduino.cc/hardware/uno-rev3
 *    Shield              Sensor v5.0    https://curtocircuito.com.br/datasheet/arduino_sensor_shield.pdf
 *    Main Pump           12V DC Motor
 *    Auxiliary Pump      5V DC Motor
 *    Relays              KY-019         https://roboticafacil.es/datasheets/ky-019.pdf
 *    Ultrasonic Senors   HC SR04        https://cdn.sparkfun.com/datasheets/Sensors/Proximity/HCSR04.pdf 
 *    Moisture Sensors    YL-69 /HW-103  https://kysungheo.com/wp-content/uploads/2022/07/instructions.261306374.pdf
 *    Lamp                5V 2000K
 */

#include <SPI.h>                //For the OLED Display
#include <Wire.h>               //For the OLED Display
#include <Adafruit_GFX.h>       //For the OLED Display
#include <Adafruit_SSD1306.h>   //For the OLED Display
Adafruit_SSD1306 display(128, 64);
#include "definitions.h"        //Defintions of variables
#include "functions.h"          //Self made functions used in this code

void loop() {
  switch (state) {
    case normal:
      
      //Check environment brightness and set plant lamps according to the result:
      if ((envBrightness < brightnessLevel) && (lastLampState = 0)) {
        digitalWrite(lamp, HIGH);
        lastLampState = 1;
        Serial.println("Plant Lamp ON");
      }
      else if ((envBrightness > brightnessLevel) && (lastLampState = 1)) {
        digitalWrite(lamp, LOW);
        lastLampState = 0;
        Serial.println("Plant Lamp OFF");
      }

      //Check soil moisture level and set water pump according to the result:
      if (soilMoisture < 55) {
        state = watering;
      }

      //Check water level of the collection container:
      if (waterContainer() < 2.5) {
        state = dewatering;
      }

      //Check water level of the water tank:
      if ((waterTank() > 9) && (lastDisplayState != 1)) {
        //WARNUNG MINIMUM!!!
        displayWarningMinimum();
        lastDisplayState = 1;
        
      }
      else if ((waterTank() < 6) && (lastDisplayState != 2)) {
        //WARNUNG MAXIMUM!!!
        displayWarningMaximum();
        lastDisplayState = 2;
      }
      else if (lastDisplayState != 0) {
        displayInformation();
        lastDisplayState = 0;
      }

      break;

    //Used to water the plants:
    case watering:
      if (waterTank() > 10) {               //Check if water level is NOT below minimum
        digitalWrite(pumpMain, HIGH);       //Power the main water pump
        if (soilMoisture > 63) {            //Check if moisture is high enough
          digitalWrite(pumpMain, LOW);
          state = normal;
        }
      }
      else {
        digitalWrite(pumpMain, LOW);        //No water pumping if water level is below minimum
        //WARNUNG MINIMUM!!!
        displayWarningMinimum();
      }
      break;

    //Used to pump the water out of the collection container:
    case dewatering:
      if (waterTank() < 5) {               //Check if water level in main tank is not above maximum
        digitalWrite(pumpAux, HIGH);
        if (waterContainer() > 3.7) {
          digitalWrite(pumpAux, LOW);
          state = normal;
        }
      }
      else {                                //If water level in main tank is above maximum
        digitalWrite(pumpAux, LOW);
        state = normal;
      }
      break;

    default:
      state = normal;
      break;
  }
  Serial.println(state);
}
