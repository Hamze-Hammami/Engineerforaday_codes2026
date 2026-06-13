// C++ code
 
 
 
void setup()

{

  Serial.begin(9600);

  pinMode(4, OUTPUT);

  pinMode(5, OUTPUT);

}
 
void loop()

{

  //**************Forward Movement**********

  //>>>>>>>>>>>>>>>>>>>>>>Motor Left

  digitalWrite(4, HIGH);

  digitalWrite(5, LOW);
 
  

  Serial.println("Forward Movement");

  delay(5000);
 
  //**************Backward Movement**********

  //>>>>>>>>>>>>>>>>>>>>>>Motor Left

  digitalWrite(4, LOW);

  digitalWrite(5, HIGH);
 
 
  Serial.println("Backward Movement");

  //>>>>>>>>>>>>Delay for 5 seconds

  delay(5000);

}
