/*
    Project name : Potentiometer Variable Resistor
    Modified Date: 11-06-2024
    Code by : Projectslearner
    Website : https://projectslearner.com/learn/arduino-nano-potentiometer-variable-resistor
*/

const int potPin = A0; // Analog pin connected to the potentiometer

void setup() {
  Serial.begin(9600); // Initialize serial communication
}

void loop() {
  int potValue = analogRead(potPin); // Read the value from the potentiometer
  int mappedValue = mapToRange(potValue, 0, 1023, 0, 100); // Map the value to a range from 0 to 100
  
  Serial.print("Potentiometer Value: ");
  Serial.println(mappedValue); // Print the mapped potentiometer value to the Serial Monitor
  
  delay(100); // Delay for stability
}

int mapToRange(int value, int fromLow, int fromHigh, int toLow, int toHigh) {
  // Map the value from one range to another
  return (value - fromLow) * (toHigh - toLow) / (fromHigh - fromLow) + toLow;
}
