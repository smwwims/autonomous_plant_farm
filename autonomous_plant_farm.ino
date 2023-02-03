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

#include "definitions.h"
#include "functions.h"

void loop() {
  switch (state) {
    
  }
}
