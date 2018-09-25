//going to start adding in the servo motor to turn
//this works for multiple button presses and 
//3/7/2018 15:06


#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 90;    // variable to store the servo position

// this constant won't change:
const int  buttonPin = 2;    // the pin that the pushbutton is attached to
const int ledPin = 13;       // the pin that the LED is attached to



// Variables will change:
int buttonPushCounter = 0;   // counter for the number of button presses
int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button
int happened1 = 0;
int happened2 = 0;
int happened3 = 0;
int happened4 = 0;


unsigned long previousMillis;   //you need to use the long command because of the length of the number you are using
unsigned long timer = 60000;    //How long do you want your contract to last for in milliseconds
unsigned long difference;
unsigned long pressTime1;       //Record the start time of each contract
unsigned long wait1;
unsigned long pressTime2;
unsigned long wait2;
unsigned long pressTime3;
unsigned long wait3;
unsigned long pressTime4;
unsigned long wait4;



String inputString = "";         // a String to hold incoming data
String lastSerialVal = "";      //Put the serial value in from 0s to 5min
String currentSerialVal = "";   //Put the current serial value in this variable

boolean stringComplete = false;  // whether the string is complete


void setup() {
  // initialize the button pin as a input:
  pinMode(buttonPin, INPUT);
  // initialize the LED as an output:
  pinMode(ledPin, OUTPUT);
  // initialize serial communication:
  Serial.begin(115200);
  //reserve 10 bytes of the information string
  inputString.reserve(10);
  
 //Initialise the servo 
  
      myservo.attach(10);  // attaches the servo on pin 10 to the servo object
    myservo.write(0);
    delay(1000);
        myservo.write(90);
    delay(1000);
        myservo.write(180);
    delay(1000);
            myservo.write(90);
    delay(1000);
    myservo.detach();

  
  //start the timer 
previousMillis = 0;
Serial.print("Start time = ");
Serial.println(previousMillis);

}


void loop() {
  // read the pushbutton input pin:
  buttonState = digitalRead(buttonPin);
  difference = millis() - previousMillis;
    
if(difference > timer){

   lastSerialVal = currentSerialVal;  //Check to see if the current value sent over the serial is the same as the previous value
   
    Serial.println("Data not recieved in last 5 min - therefore no earthquake");

      
      previousMillis=millis();
      delay(50);

  }

   else if (stringComplete) {
      
    lastSerialVal = currentSerialVal;
    currentSerialVal = inputString;
    
    Serial.println("Data recieved in last 5 minutes - therefore earthquake happened");



    // clear the string:
    inputString = "";
    stringComplete = false;
    
   previousMillis = millis();
  }

  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState == HIGH) {
      // if the current state is HIGH then the button went from off to on:
      buttonPushCounter++;
      
    for (int ledCount = 0; ledCount < 6; ledCount++) {
    // turn the pin on:
    digitalWrite(ledPin, HIGH);
    delay(1000);
    // turn the pin off:
    digitalWrite(ledPin, LOW);
    delay(1000);
  }
      

    if (buttonPushCounter == 1) {
    Serial.println(buttonPushCounter);
          pressTime1 = millis();

  } else if (buttonPushCounter == 2){
    Serial.println(buttonPushCounter);
          pressTime2 = millis();

  } else if (buttonPushCounter == 3){
    Serial.println(buttonPushCounter);
          pressTime3 = millis();

  } else if (buttonPushCounter == 4){
    Serial.println(buttonPushCounter);
          pressTime4 = millis();

  } else{
    buttonPushCounter = 0;
    Serial.println("reset");
  }

      Serial.println("Button has been pressed - wait for 5 minutes");
      
      //input code to run once when you press the button

      
    }
    // Delay a little bit to avoid bouncing
    delay(50);

  }
  // save the current state as the last state, for next time through the loop
  lastButtonState = buttonState;

//this is where the code which runs after the 5 minutes will go 'below'
if(buttonPushCounter == 0){
wait1 = 0;
wait2 = 0;
wait3 = 0;
wait4 = 0;
happened1 = 0;
happened2 = 0;
happened3 = 0;
happened4 = 0;
} else if(buttonPushCounter == 1){
wait1 = millis() - pressTime1;
wait2 = 0;
wait3 = 0;
wait4 = 0;
} else if(buttonPushCounter == 2){
wait1 = millis() - pressTime1;
wait2 = millis() - pressTime2;
wait3 = 0;
wait4 = 0;
}else if(buttonPushCounter == 3){
wait1 = millis() - pressTime1;
wait2 = millis() - pressTime2;
wait3 = millis() - pressTime3;
wait4 = 0;
}else if(buttonPushCounter == 4){
wait1 = millis() - pressTime1;
wait2 = millis() - pressTime2;
wait3 = millis() - pressTime3;
wait4 = millis() - pressTime4;
}


if (wait1 > timer && happened1 == 0){
  happened1 = 1;
      if(lastSerialVal==currentSerialVal){
turnAnticlockwise();
pressTime1=millis();
        if(buttonPushCounter == 1){ // this is the point to edit
          //pressTime1=millis();
          buttonPushCounter = 0;
        }
      }else{
turnClockwise();
pressTime1=millis();

        if(buttonPushCounter == 1){
          //pressTime1=millis();
          buttonPushCounter = 0;
        }
      }
}

if (wait2 > timer && happened2 == 0){
  happened2 = 1;
      if(lastSerialVal==currentSerialVal){
turnAnticlockwise();
pressTime2=millis();
        if(buttonPushCounter == 2){
          buttonPushCounter = 0;
        }
      }else{

turnClockwise();
pressTime2=millis();
        if(buttonPushCounter == 2){
          buttonPushCounter = 0;
        }
        }
}

if (wait3 > timer && happened3 == 0){
  happened3=1;
      if(lastSerialVal==currentSerialVal){
turnAnticlockwise();
pressTime3=millis();

        if(buttonPushCounter == 3){
          buttonPushCounter = 0;
        }
      }else{

turnClockwise();
pressTime3=millis();
        if(buttonPushCounter == 3){
          buttonPushCounter = 0;
        }
      }
}

if (wait4 > timer && happened4 == 0){
  happened4 = 1;
      if(lastSerialVal==currentSerialVal){
turnAnticlockwise();
pressTime4=millis();

        if(buttonPushCounter == 4){
          buttonPushCounter = 0;
        }
      }else{
turnClockwise();
pressTime4=millis();
        if(buttonPushCounter == 4){
          buttonPushCounter = 0;
        }
      }
}
      
//this is where the code which runs after the 5 minutes will go 'above'


}

////turn clockwise
//void turnClockwise(){
//    Serial.println("There has been an earthquake ");
//
//  myservo.attach(10);
//  delay(100);
//        for (pos = 90; pos <= 180; pos += 5) { // goes from 0 degrees to 180 degrees
//    // in steps of 1 degree
//    myservo.write(pos);              // tell servo to go to position in variable 'pos'
//    delay(15);                       // waits 15ms for the servo to reach the position
//  }
//    delay(1000);
//
//  for (pos = 180; pos >= 90; pos -= 5) { // goes from 180 degrees to 0 degrees
//    myservo.write(pos);              // tell servo to go to position in variable 'pos'
//    delay(15);                       // waits 15ms for the servo to reach the position
//  }
//  delay(100);
//   myservo.detach();
//       Serial.println("There has been an earthquake end");
//
//}

//turn clockwise
void turnClockwise(){
    Serial.println("There has been an earthquake ");

  myservo.attach(10);
  delay(100);
      myservo.attach(10);  // attaches the servo on pin 3 to the servo object
    myservo.write(90);
    delay(1000);
        myservo.write(0);
    delay(1000);
        myservo.write(90);
    delay(1000);
    myservo.detach();
       Serial.println("There has been an earthquake end");

}

////turn anticlockwise
//void turnAnticlockwise(){
//  Serial.println("There has not been an earthquake ");
//  myservo.attach(10);
//  delay(100);
//        for (pos = 90; pos >= 0; pos -= 5) { // goes from 90 degrees to 0 degrees
//    // in steps of 1 degree
//    myservo.write(pos);              // tell servo to go to position in variable 'pos'
//    delay(15);                       // waits 15ms for the servo to reach the position
//  }
//  delay(3000);
//  for (pos = 0; pos <= 90; pos += 5) { // goes from 90 degrees to 180 degrees
//    myservo.write(pos);              // tell servo to go to position in variable 'pos'
//    delay(15);                       // waits 15ms for the servo to reach the position
//  }
//  delay(100);
//   myservo.detach();
//     Serial.println("There has not been an earthquake end");
//
//   
//}

void turnAnticlockwise(){
  Serial.println("There has not been an earthquake ");
  myservo.attach(10);
  delay(100);
      myservo.attach(10);  // attaches the servo on pin 3 to the servo object
    myservo.write(90);
    delay(1000);
        myservo.write(180);
    delay(1000);
        myservo.write(90);
    delay(1000);
    myservo.detach();
     Serial.println("There has not been an earthquake end");

   
}

void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}
