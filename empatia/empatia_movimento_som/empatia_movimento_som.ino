#include <Servo.h>
#include "SerialMP3Player.h"
#include <Stepper.h>
#include <SoftwareSerial.h>


// pinos do shield mp3
#define TX 1
#define RX 0
// pinos do sensor de presenca
#define trigPin 14
#define echoPin 15


// declaracoes do sensor de presenca
long duration;
int distance;
SerialMP3Player mp3(RX,TX);

const int stepsPerRevolution = 2048;  
Stepper nuvens(stepsPerRevolution, 2,3,4,5);  
Stepper porta(stepsPerRevolution, 6,7,8,9);  
Servo mares;

void setup() {

  //Serial.begin(9600);     // start serial interface
  mp3.begin(9600);        // start mp3-communication
  delay(500);             // wait for init
  mp3.sendCommand(CMD_SEL_DEV, 0, 2);   //select sd-card
  delay(500);             // wait for init

  // pinos do sensor de presenca
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input

  // pinos do motor das nuvens
  pinMode(2, OUTPUT);  
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);

  // pinos do motor da porta
  pinMode(6, OUTPUT);  
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);

  // pino do motor dos mares
  pinMode(10, OUTPUT);

  // pino  de comunicacao com o outro arduino
  pinMode(11, OUTPUT);

  porta.setSpeed(14);
  nuvens.setSpeed(14);
}

void loop() {

  // ################ ATENCAO ##################

   /*
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
  
    
  */
 
  // COMUNICA PRO OUTRO ARDUINO QUE TEM QUE OCMECAR:
  
  //digitalWrite(11, HIGH);
 
  
  // TOCA MUSICA
  
  //mp3.play();

  
  // PORTA ABRIR EM 10 SEG:
  
//abre a porta em 10s
/*for (int counter = 0; counter >= 512; counter = counter + 1){
porta.step(1);
delay(19);     
}*/    
    
  // ESPERAR 11 SEG:
  
  delay(11000);
   

  for (int i = 0; i <=380; i = i + 1){
    mares.attach(10);
    mares.write(160);
    nuvens.step(10);
    delay(40);
    mares.detach();
  }
   
  delay(18000);
  
  // PARA A MUSICA
  
  //mp3.stop();

  // fecha a porta
  
//fecha a porta em 10s
/*for (int counter = 0; counter >= 512; counter = counter + 1){
porta.step(-1);
delay(19);     
}*/

  // baixa o pino de comunicacao
  //digitalWrite(11, LOW);

  //}
  
  //delay(200);
  
  
}
