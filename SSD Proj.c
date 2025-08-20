#include <Servo.h>  // Include the Servo library

char t;
Servo myServo;     // Create a Servo object

void setup() {
  pinMode(13, OUTPUT);   // Left motors forward
  pinMode(12, OUTPUT);   // Left motors reverse
  pinMode(11, OUTPUT);   // Right motors forward
  pinMode(10, OUTPUT);   // Right motors reverse
  pinMode(9, OUTPUT);    // LED

  myServo.attach(6);     // Attach the servo to pin 6
  myServo.write(0);      // Initialize servo at 0 degrees
  
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    t = Serial.read();
    Serial.println(t);  // Print received command for debugging
  }

  if (t == 'F') {  // Move forward
    digitalWrite(13, HIGH);
    digitalWrite(11, HIGH);
    Serial.println("Moving Forward");
    t = '\0';  // Clear command
  }
  else if (t == 'B') {  // Move reverse
    digitalWrite(12, HIGH);
    digitalWrite(10, HIGH);
    Serial.println("Moving Backward");
    t = '\0';
  }
  else if (t == 'L') {  // Turn right
    digitalWrite(11, HIGH);
    digitalWrite(13, LOW);
    Serial.println("Turning Right");
    t = '\0';
  }
  else if (t == 'R') {  // Turn left
    digitalWrite(13, HIGH);
    digitalWrite(11, LOW);
    Serial.println("Turning Left");
    t = '\0';
  }
  else if (t == 'W') {  // Turn LED on
    digitalWrite(9, HIGH);
    Serial.println("LED ON");
    t = '\0';
  }
  else if (t == 'w') {  // Turn LED off
    digitalWrite(9, LOW);
    Serial.println("LED OFF");
    t = '\0';
  }
  else if (t == 'S') {  // STOP all motors
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    Serial.println("STOP");
    t = '\0';
  }
  else if (t == 'V') {  // Activate servo
    myServo.write(90); // Move servo to 90 degrees
    Serial.println("Servo Activated");
    t = '\0';
  }
  else if (t == 'v') {  // Deactivate servo
    myServo.write(0);  // Move servo back to 0 degrees
    Serial.println("Servo Deactivated");
    t = '\0';
  }

  // Optional: reduce delay to 5 ms or remove it entirely for faster response
  delay(5);
}