// tempo de duracao da casa por volta de 50s

#include "SerialMP3Player.h"
#include <Stepper.h>


// pinos do shield mp3
#define TX 1
#define RX 0
// pinos do sensor de presenca
#define trigPin = 15
#define echoPin = 14
// pino rele bomba de agua
#define relay = 10


// declaracoes do sensor de presenca
long duration;
int distance;
SerialMP3Player mp3(RX,TX);

const int stepsPerRevolution = 2048;  
Stepper porta(stepsPerRevolution, 2,3,4,5);  
Stepper barco(stepsPerRevolution, 6,7,8,9);  


void setup() {

  Serial.begin(9600);     // start serial interface
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
  barco.setSpeed(14);
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

    digitalWrite(relay, HIGH);
    barco.step(stepsPerRevolution*11.62); // move o barco por 50s
    digitalWrite(relay, LOW);
    
    porta.step(-stepsPerRevolution/4); // fecha    
  }

}
