#include <Servo.h>

Servo rainServo;
int rainSensor = A0;
int rainValue;

void setup() {
  Serial.begin(9600);
  rainServo.attach(9);         // Connect Servo Signal pin to D9
  rainServo.write(0);          // Start with servo at 0 degrees
}

void loop() {
  rainValue = analogRead(A0);  // Read analog value from rain sensor
  Serial.print("Rain Sensor Value: ");
  Serial.println(rainValue);

  if (rainValue < 800) {       // Adjust threshold as per your sensor
    Serial.println("🌧️ Rain Detected!");
    rainServo.write(90);       // Rotate servo to 90°
  } else {
    Serial.println("☀️ No Rain.");
    rainServo.write(0);        // Rotate servo back to 0°
  }

  delay(1000);                 // 1 Second Delay for stability
}
