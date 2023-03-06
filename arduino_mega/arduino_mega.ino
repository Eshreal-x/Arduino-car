#include <Servo.h>
Servo myservo;

int states [5] = { 
  0, //left
  0, //up
  0, //right
  0  //down
}; 




void setup() {
  // Begin the Serial at 9600 Baud
  Serial.begin(115200);
   pinMode(22, OUTPUT);
pinMode(2, OUTPUT);
pinMode(3, OUTPUT);
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
}

 
int pos = 90; // variable to store the servo position
 



long previousMillis = 0; 

void loop() {
  if(Serial.available() > 0){
    char payload[5];
    Serial.readBytes(payload, 5);
    String str = (char*)payload;
    int type = str.substring(0, str.indexOf("+")).toInt();
    bool val = str.substring(str.indexOf("+")+1, str.indexOf("+")+2).toInt();
    states[type] = val;
    //Serial.println(type);
   // Serial.println(val);
    Serial.println("Received");
  }


  unsigned long currentMillis = millis();
  if(currentMillis - previousMillis > 15) {
    previousMillis = currentMillis;


    bool val = states[0] + states[1] + states[2] + states[3];

    digitalWrite(2, 0);
    digitalWrite(3, 0);
    digitalWrite(4, 0);
    digitalWrite(5, 0);
    
    if(states[1] == 1){
      digitalWrite(2, 0);
      digitalWrite(3, 1);
      digitalWrite(4, 1);
      digitalWrite(5, 0);
    }

    
    if(states[3] == 1){
      digitalWrite(2, 1);
      digitalWrite(3, 0);
      digitalWrite(4, 0);
      digitalWrite(5, 1);
    }

    if(states[0] == 1){
      digitalWrite(2, 1);
      digitalWrite(3, 0);
      digitalWrite(4, 1);
      digitalWrite(5, 0);
    }

    if(states[2] == 1){
      digitalWrite(2, 0);
      digitalWrite(3, 1);
      digitalWrite(4, 0);
      digitalWrite(5, 1);
    }
    
    digitalWrite(22, val);
  }
}
