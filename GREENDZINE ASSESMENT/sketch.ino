#include <Arduino.h>
#include <util/delay.h>
#define Sensor_pin A0
void setup()
{
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT); // pin 13
}

void loop()
{
  int reading = analogRead(Sensor_pin);
  /*
   * ADC value is converted to VTG HERE
   * vref = 5V = 5000mV
   * ADC = 10BIT Data = 2^10 = 1024
  */
  
  //float voltage = (((reading) * 5.0) / 1024.0)); // VTG = (ADC Value * Vref)/1024
    float voltage = reading * (5.0 / 1024.0);
  // O/P VTG in mV
    //According to the data sheet output of LM35 is 10mV/°C
   //1°C = 10 MILLI VOLTS AS PER IN THE DATA SHEETS
  float temparatureC = voltage * 100; //voltage changed into corresponding temperature degree celsius
  float temparatureF = (temparatureC * 9.0 / 5.0) + 32.0;

  
  if (temparatureC >= 30)
  {
    /*If the temp. rises above 30 degrees Celsius,  LED blink
      every 500 milliseconds.*/
    digitalWrite(LED_BUILTIN, HIGH);
    _delay_ms(500);
    digitalWrite(LED_BUILTIN, LOW);
    _delay_ms(500);
  }
  else
  {
    /*When the temperature falls below 30 degrees Celsius,  LED
      blink every 250 milliseconds.*/
    digitalWrite(LED_BUILTIN, HIGH);
    _delay_ms(250);
    digitalWrite(LED_BUILTIN, LOW);
    _delay_ms(250);
  }

  if (temparatureF >= 30)
  {
    /*If the temp. rises above 30 degrees Celsius,  LED blink
      every 500 milliseconds.*/
    digitalWrite(LED_BUILTIN, HIGH);
    _delay_ms(500);
    digitalWrite(LED_BUILTIN, LOW);
    _delay_ms(500);
  }
  else
  {
    /*When the temperature falls below 30 degrees Celsius,  LED
      blink every 250 milliseconds.*/
    digitalWrite(LED_BUILTIN, HIGH);
    _delay_ms(250);
    digitalWrite(LED_BUILTIN, LOW);
    _delay_ms(250);
  }
  //Serial.println(temp_in_celsius);
 
  // Print the temperature in Celsius
  Serial.print("Temparature: ");
  Serial.print(temparatureC);
  Serial.print("\xC2\xB0"); // shows degree symbol
  Serial.print("C  |  ");

  //Print the temaprature Farhenheit 
  Serial.print("Farhenheit: ");
  Serial.print(temparatureF);
  Serial.print("\xC2\xB0"); // shows degree symbol
  Serial.println("F  |  ");
}



  

