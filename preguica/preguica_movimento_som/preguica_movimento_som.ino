
// tempo de duracao da casa por volta de 50s
#include "SerialMP3Player.h"
#include <Stepper.h>
#include <SoftwareSerial.h>

// pinos do shield mp3
#define TX 1
#define RX 0
// pinos do sensor de presenca
#define trigPin 14
#define echoPin 15
// pino rele bomba de agua
#define relay 10


// declaracoes do sensor de presenca
long duration;
int distance;
SerialMP3Player mp3(RX,TX);

const int stepsPerRevolution = 2048;  
Stepper porta(stepsPerRevolution, 2,3,4,5);  
Stepper barco(stepsPerRevolution, 6,7,8,9);  


void setup() {

  //Serial.begin(9600);     // start serial interface
  mp3.begin(9600);        // start mp3-communication
  delay(500);             // wait for init
  mp3.sendCommand(CMD_SEL_DEV, 0, 2);   //select sd-card
  delay(500);             // wait for init

  // pinos do sensor de presenca
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input

  // pinos do motor da porta
  pinMode(2, OUTPUT);  
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);

  // pinos do motor do barco
  pinMode(6, OUTPUT);  
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);

  // pino do relay
  pinMode(10, OUTPUT);

  porta.setSpeed(14);
  barco.setSpeed(8);
  digitalWrite(relay, HIGH);
}

void loop() {

  // partes do sensor de presenca
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  //Serial.print("Distance: ");
  //Serial.println(distance);
  
  
  if (distance <= 40){

    mp3.play();

    porta.step(stepsPerRevolution/4); // abre
    digitalWrite(relay, LOW);
    barco.step(stepsPerRevolution*11.62);  //*11.62); // move o barco por 50s
    digitalWrite(relay, HIGH);
    
    porta.step(-stepsPerRevolution/4); // fecha    
    mp3.stop();

  }
  
  delay(3000);
}


#include <Servo.h> 
#include <Stepper.h>
 
Servo travesseiro;  
int pos = 60;
const int stepsPerRevolution = 2048;  
Stepper porta_armario(stepsPerRevolution, 14,15,16,17);            

void setup() 
{ 
  travesseiro.attach(8); 
  porta_armario.setSpeed(14);

} 
 
 
void loop() 
{ 
    // MOVIMENTOS ARMARIO
    
    //MOVIMENTO ABRIR PORTA DO ARMARIO
    porta_armario.step(-stepsPerRevolution*0.30);
    delay(2000);
    
    //MOVIMENTO FECHAR PORTA DO ARMARIO
    porta_armario.step(stepsPerRevolution*0.30);
    delay(2000);
    
   
    
 
    /* MOVIMENTO TRAVESSEIRO
  
    travesseiro.write(40);              
    delay(1500);                    
    travesseiro.write(60);               
    delay(1500);                     
    for(pos = 60; pos >= 40; pos -= 1)  // goes from 0 degrees to 180 degrees 
    {                                  // in steps of 1 degree 
      travesseiro.write(pos);              // tell servo to go to position in variable 'pos' 
      delay(100);                       // waits 15ms for the servo to reach the position 
    }
  
    */
    
    
} 


