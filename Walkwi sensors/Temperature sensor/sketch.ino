#include <MD_Parola.h>
#include <MD_MAX72xx.h>

#define HARDWARE_TYPE MD_MAX72XX::PAROLA_HW
#define MAX_DEVICES 4
#define CS_PIN 10

MD_Parola myDisplay = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);

const float BETA = 3950; // Beta Coefficient of the thermistor

void setup() {
  // Initialize the display
  myDisplay.begin();
  // Set the intensity (brightness) of the display (0-15):
  myDisplay.setIntensity(0);
  // Clear the display:
  myDisplay.displayClear();
}

void loop() {
  // Read analog value from pin A0
  int analogValue = analogRead(A0);
  // Calculate temperature in Celsius using the Steinhart-Hart equation
  float celsius = 1 / (log(1 / (1023.0 / analogValue - 1)) / BETA + 1.0 / 298.15) - 273.15;
  // Convert temperature to a string
  String temp = (String) celsius;
  // Display temperature on the LED matrix display
  myDisplay.print(temp);
  // Delay for 1 second
  delay(1000);
}