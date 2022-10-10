#define echoPin A0 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin A1 //attach pin D3 Arduino to pin Trig of HC-SR04
// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement
int com = A7;
int com1 = A6;


int leds[] = {
  A0, A1, A2, A3, A4, A5,3, 5, 6, 9, 10, 11
};

int ledsF[] = {
  A0, A1, A2, A3, A4, A5
};

int ledsB[] = {
  9, 10, 11
};

int ledsL[] = {
  3, 5, 6
};

int tempLED = 5;
int tempFase = 1000;

void setup() {
  
  for (int x = 0; x < 11; x++) { 
    pinMode(leds[x], OUTPUT);
  }
   pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  pinMode(com, OUTPUT);
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
  Serial.println("with Arduino Nano 2022");   
}

void play() {
//P_1 ### LED Forno ###
    for(int y = 0; y < 50; y++) {
       analogWrite(ledsL[0],y);
       delay(tempLED*2);
    }
  for(int x = 0; x <6; x++){
    for(int y = 50; y < 255; y++) {
       analogWrite(ledsL[0],y);
       delay(tempLED*2);
    }
    for(int y = 255; y > 50; y--) {
        analogWrite(ledsL[0],y);
        delay(tempLED);    
    }
  }  
      for(int y = 0; y < 150; y++) {
       analogWrite(ledsL[0],y);
       delay(tempLED*2);
      }
      
      
 //P_1.2 ### LED Xicara ###
    for(int y = 0; y < 50; y++) {
       analogWrite(ledsL[1],y);
       delay(tempLED*2);
    }
  for(int x = 0; x <5 ; x++){
    for(int y = 50; y < 255; y++) {
       analogWrite(ledsL[1],y);
       delay(tempLED);
    }
    for(int y = 255; y > 50; y--) {
        analogWrite(ledsL[1],y);
        delay(tempLED);    
    }
  } 
//### LED Ambiente  ### 

      for(int y = 0; y < 150; y++) {
       analogWrite(ledsL[1],y); //forno
       analogWrite(ledsB[0],y);
       analogWrite(ledsB[1],y/5);
       analogWrite(ledsB[2],y);       
       delay(tempLED);
      }     

    for(int y = 150; y < 255; y++) {
       analogWrite(ledsL[0],y);
       delay(tempLED);
    }
  for(int x = 0; x <3; x++){
    for(int y = 150; y < 255; y++) {
       analogWrite(ledsB[0],y);
       analogWrite(ledsB[1],y/5);
       analogWrite(ledsB[2],y);
       delay(tempLED*2);
    }
    for(int y = 255; y > 155; y--) {
       analogWrite(ledsB[0],y);
       analogWrite(ledsB[1],y/5);
       analogWrite(ledsB[2],y);
        delay(tempLED);    
    }   
  }    
    for(int y = 155; y < 200; y++) {
       analogWrite(ledsB[0],y);
       analogWrite(ledsB[1],y/5);
       analogWrite(ledsB[2],y);
       delay(tempLED*2);
    }
delay(tempFase);

//P_1 ### LED Forno ###
    for(int y = 0; y < 50; y++) {
       analogWrite(ledsL[0],y);
       delay(tempLED);
    }
  for(int x = 0; x <7; x++){
    for(int y = 50; y < 255; y++) {
       analogWrite(ledsL[0],y);
       delay(tempLED*2);
    }
    for(int y = 255; y > 50; y--) {
       analogWrite(ledsL[0],y);
       delay(tempLED);
    }  
  } 
  
//### Fim ###  
delay(tempFase*3);  
for(int y = 255; y > 0; y--) {
    analogWrite(ledsL[0],y);
    analogWrite(ledsL[1],y);
    analogWrite(ledsL[2],y);
    analogWrite(ledsB[0],y);
    analogWrite(ledsB[1],y/3);
    analogWrite(ledsB[2],y);        
    delay(tempLED*2);    
 }
    analogWrite(ledsL[0],0);
    analogWrite(ledsL[1],0);
    analogWrite(ledsL[2],0);
    analogWrite(ledsB[0],0);
    analogWrite(ledsB[1],0);
    analogWrite(ledsB[2],0);    
    
    delay(6000);

}

void loop() {
 // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

//Start
  if(distance <30){
    Serial.println("play");
    digitalWrite(com, HIGH);
    digitalWrite(com1, HIGH);
    play();
    
  }
}