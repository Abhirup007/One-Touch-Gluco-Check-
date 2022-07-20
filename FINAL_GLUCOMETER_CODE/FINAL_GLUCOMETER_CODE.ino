#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>

#define OLED_RESET 4
Adafruit_SH1106 display(OLED_RESET);

int sensorPin1 = A1;
int sensorPin1 = A0;
int sensorPin1 = A2;
int indicator = 12;
float adc_voltage1 = 0.0;
float adc_voltage2 = 0.0;
float adc_voltage3 = 0.0;
float final_voltage1 = 0.0;
float final_voltage2 = 0.0;
float final_voltage3 = 0.0;
float average_voltage = 0.0;
float callibrated_value = 0.072;
float in_voltage = 0.0;

// Float for Reference Voltage
float ref_voltage = 5.0;
 
// Integer for ADC value
int adc_value1 = 0;
int adc_value2 = 0;
int adc_value3 = 0;

void setup()
{
    pinMode(indicator, OUTPUT);
    digitalWrite(indicator, LOW);
    Serial.begin(115200);
  
    // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
    display.begin(SH1106_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
    display.clearDisplay();
}

void loopSection()
{
  for (int i = 0; i<=30; i++)
  {
    
    if (final_voltage <= 3.00)
    {
      delay(1000);
      digitalWrite(indicator, HIGH);  
      delay(100);
      digitalWrite(indicator, LOW);
      delay(100);
      Serial.print("FINAL CALLIBRATED VOLTAGE :");
      Serial.print(final_voltage, 3);
      Serial.print(" mV");
      Serial.println(" ");
    }
  }
}

void loop()
{
    // Read the Analog Input
    adc_value1 = analogRead(sensorPin1);
    adc_value2 = analogRead(sensorPin2);
    adc_value3 = analogRead(sensorPin3);
    // Determine voltage at ADC input
    adc_voltage1  = (adc_value1 * ref_voltage) / 1023.0;
    adc_voltage2  = (adc_value2 * ref_voltage) / 1023.0;
    adc_voltage3  = (adc_value3 * ref_voltage) / 1023.0;
      
    final_voltage1 = adc_voltage1 - callibrated_value;
    final_voltage2 = adc_voltage2 - callibrated_value;
    final_voltage3 = adc_voltage3 - callibrated_value;

    average_voltage = (final_voltage1 + final_voltage2 + final_voltage3)/3;
    
    // Print results to Serial Monitor to 2 decimal places
    Serial.print("Input Voltage = ");
    Serial.print(final_voltage1, 3);
    Serial.print(" mV");
    Serial.println(" ");
    
    Serial.print("Input Voltage = ");
    Serial.print(final_voltage2, 3);
    Serial.print(" mV");
    Serial.println(" ");
    
    Serial.print("Input Voltage = ");
    Serial.print(final_voltage3, 3);
    Serial.print(" mV");
    Serial.println(" ");

    Serial.print("Final Average Voltage = ");
    Serial.print(average_voltage, 3);
    Serial.print(" mV");
    Serial.println(" ");
}
