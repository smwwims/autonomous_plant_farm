# autonomous_plant_farm
Code for a DIY Smart Garden. A Winter Hardware Wonderland project.

Read https://github.com/hackclub/winter and https://github.com/hackclub/winter/blob/main/smwwims.md for full details.

# Short project summary
I have always had a keen interest in botany, but unfortunately my gardening skills do not quite match my programming skills. 
That is why I came up with the idea of building a fully automatic smart garden. In contrast to the "Smart Planting Sets" available 
on the market, my project is not a simple control circuit, but a regulation circuit. This means that the water and light supply is 
not simply controlled by the time, but responds to the needs of the plants via sensors.

# Hardware
| Part                | Hardware                    | Additional Information                                                        |
| ------------------- | --------------------------- | ----------------------------------------------------------------------------- |
| Board               | Arduino Uno                 | https://docs.arduino.cc/hardware/uno-rev3                                     |
| Shield              | Arduino Sensor Shield v5.0  |  https://curtocircuito.com.br/datasheet/arduino_sensor_shield.pdf             |
| Main Pump           | 12V DC Motor                |                                                                               |
| Auxiliary Pump      | 5V DC Motor                 | https://docs.arduino.cc/hardware/uno-rev3                                     |
| Relays              | KY-019                      |  https://roboticafacil.es/datasheets/ky-019.pdf                               |
| Ultrasonic Sensors  | HC SR04                     | https://cdn.sparkfun.com/datasheets/Sensors/Proximity/HCSR04.pdf              |
| Moisture Sensors    | YL-69 / HW-103              |  https://kysungheo.com/wp-content/uploads/2022/07/instructions.261306374.pdf  |
| Lamp                | 5V 2000K                    |                                                                               |

# Languages
Arduino C
