const int sensorPin = 33;
const int ledPin18 = 18;
const int ledPin23 = 23;
const int ledPin19 = 19;

float pressurePSI = 50;
int analogSensorValue = 0;
long previousMillisPressure = 0;
long previousMillisAnalog = 0;
const long intervalPressure = 1000;
const long intervalAnalog = 1000;

float readPressureSensor() {
  int sensorValue = analogRead(sensorPin);
  float pressure = map(sensorValue, 0, 1023, 0, 100);
  return pressure;
}

int readAnalogSensor() {
  return analogRead(sensorPin);
}

void setup() {
  Serial.begin(9600);
  pinMode(ledPin18, OUTPUT);
  pinMode(ledPin23, OUTPUT);
  pinMode(ledPin19, OUTPUT);
}

void loop() {
  long currentMillisAnalog = millis();
  if (currentMillisAnalog - previousMillisAnalog >= intervalAnalog) {
    previousMillisAnalog = currentMillisAnalog;
    analogSensorValue = readAnalogSensor();
    Serial.print("Analog Sensor Value: ");
    Serial.println(analogSensorValue);
  }

  long currentMillisPressure = millis();
  if (currentMillisPressure - previousMillisPressure >= intervalPressure) {
    previousMillisPressure = currentMillisPressure;

    pressurePSI = readPressureSensor();

    Serial.print("Pressure (PSI): ");
    Serial.println(pressurePSI);

    if (pressurePSI <= 0.0) {
      digitalWrite(ledPin23, LOW);
      digitalWrite(ledPin18, HIGH);
      digitalWrite(ledPin19, HIGH);
    } else {
      digitalWrite(ledPin23, HIGH);
      digitalWrite(ledPin18, LOW);
      digitalWrite(ledPin19, HIGH);
    }
  }
}
