//Name:
//Date:
//Program u3SerialOnOff
//Circuit has led light at pin 12 and pin 13
//user can use serial monitor - enter pin and on/off value
//13 [enter] 0 [enter] - turns off led in pin 13
//13 [enter] 1 [enter] - turns on led in pin 13

String incomingText; //variable to store input
int pinNumber; //the led the user selects
int onoff = 0;//whether they want it on (1) or off (0)
char enterKey = 13; //13 is the key code for the Enter key
bool gettingPin = true;//keep track if getting pin or on/off

//Setup function - runs at start
void setup() {
  Serial.begin(9600);//Start serial input
  //circuit wired with led lights at 12 and 13
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
}
//loop continually runs
void loop() {
  // send data only when you receive data:
  if (Serial.available() > 0) {
    // read the incoming input:
    incomingText = Serial.readStringUntil(enterKey);
    
    if(gettingPin){
      pinNumber= incomingText.toInt();
      gettingPin = false;
    }else{
      onoff = incomingText.toInt();
      gettingPin = true;
    }
 
    
    digitalWrite(pinNumber,onoff);
    Serial.println(pinNumber);
    Serial.println(onoff);
  }
}
