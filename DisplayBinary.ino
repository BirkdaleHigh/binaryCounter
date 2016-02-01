/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the Uno and
  Leonardo, it is attached to digital pin 13. If you're unsure what
  pin the on-board LED is connected to on your Arduino model, check
  the documentation at http://www.arduino.cc

  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
 */
int pin[] = {2,3,4,5,6,7,8,9};
int pinAmount = sizeof(pin)/sizeof(int);
int buttonState = 0;
byte count = 1;
bool buttonDown = false;

// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(13, INPUT);
  // initialize digital pin 13 as an output.
  for(int i = 0; i < pinAmount; i++){
    pinMode(pin[i], OUTPUT);
  }
  delay(100);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  buttonState = digitalRead(13);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH && buttonDown == false) {
    buttonDown = true;
    count++;
    Serial.print("Button count to: ");
    Serial.println(count);
  }
  if (buttonState == LOW){
    buttonDown = false;
  }
  
  for(int i = 0; i <= 8; i++){
    if(bitRead(count, i)){
      digitalWrite(pin[i], HIGH);
    } else {
      digitalWrite(pin[i], LOW);
    }
  }

  if(Serial.available() > 0){
    count = Serial.parseInt();
    Serial.print("Displaying: ");
    Serial.println(count, DEC);
  }
  
}
