// C++ code
//
double dist = 0; 
int EN1 = 11; //for left motor
int EN2 = 10; //for right motor

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH,30000);
}

void setup()
{
  Serial.begin(9600);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(EN1, OUTPUT);
  pinMode(EN2, OUTPUT);
 //***************************************Control the Speep******************************
  // Set speed of Motor1(PWM: 0 to 255)
  analogWrite(EN1, 100);  // Slow
  delay(300);
  // Set speed of Motor2(PWM: 0 to 255)
  analogWrite(EN2, 100);  // Slow
  delay(300);
}

void loop()
{
  //Calculate the distance in CM; 0.03432 is the cound speed in cm
  dist = 0.03432 / 2 * readUltrasonicDistance(9, 8);
  
  delay(50); // Wait for 500 millisecond(s)
  Serial.println(dist);
  if (dist < 50) {
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    delay(300);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
  } else {
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
     
  }
  delay(30); 
}
