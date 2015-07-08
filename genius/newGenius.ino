//Genius
//Para Arduino, feito por Cristofer e Bruno.

#include <TrueRandom.h>

const int buttonPin1 = 8;
const int buttonPin2 = 9;
const int buttonPin3 = 10;
const int buttonPin4 = 11; //Set buttons pins
const int ledPin[4] = { 2, 3, 4, 5 }; //Contains the pins of the leds

int newLevel(int level, int ledOrder[]){
  int waitDelay = dly(level, 'w');
  int ledDelay = dly(level, 'l');
  int checkOrder = 0;
  for(int i = 0; i < level; i++){
    ledOn(ledOrder[i]);
    delay(ledDelay);
  }
  for(int i = 0; i < level; i++){
    checkOrder = waitButton(waitDelay, ledOrder[i]);
    if(checkOrder == 0){
      return 0;
    }
  }
  return 1;
}

int dly(int level, char type){
  int dly;
  switch(type){
    case 'w':
      dly = 5*(500 - (10*(level-1)));
      break;
    case 'l':
      dly = 500 - (10*(level-1));
      break;
    }
  return dly;
}

void ledOn(int led){
  digitalWrite(ledPin[led], HIGH);
  delay(350);
  digitalWrite(ledPin[led], LOW);
}

int getButtonState(){
  int button1State = digitalRead(buttonPin1);
  int button2State = digitalRead(buttonPin2);
  int button3State = digitalRead(buttonPin3);
  int button4State = digitalRead(buttonPin4);
  if(button1State == HIGH){
    return 0;
  }
  else if(button2State == HIGH){
    return 1;
  }
  else if(button3State == HIGH){
    return 2;
  }
  else if(button4State == HIGH){
    return 3;
  }
  else{
    return 4;
  }
}

int waitButton(int dly, int btn){
  int button = getButtonState();
  int time;
  while((button != 0) && (button != 1) && (button != 2)
  && (button != 3) && (time <= dly)){
    button = getButtonState();
    delay(1);
    time++;
  }
  ledOn(button);
  if(button == btn){
    return 1;
  }
  else{
    return 0;
  }
}

void error(){
  for(int i = 0; i < 3; i++){
    digitalWrite(ledPin[0], HIGH);
    digitalWrite(ledPin[1], HIGH);
    digitalWrite(ledPin[2], HIGH);
    digitalWrite(ledPin[3], HIGH);
    delay(350);
    digitalWrite(ledPin[0], LOW);
    digitalWrite(ledPin[1], LOW);
    digitalWrite(ledPin[2], LOW);
    digitalWrite(ledPin[3], LOW);
    delay(350);
  }
}

void setup(){
  Serial.begin(9600);
  pinMode(ledPin[0], OUTPUT);
  pinMode(ledPin[1], OUTPUT);
  pinMode(ledPin[2], OUTPUT);
  pinMode(ledPin[3], OUTPUT);
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);
} //Sets the pins

void loop() {
  int gameState = 0; //gameState = 0 means 'everything ok' = 1 means 'you made somthing wrong'
  int ledOrder[50];
  int level = 1;
  for(int i = 0; i < 50; i++){
    ledOrder[i] = random(0,4);
  }
  for(int i = 0; i < 2; i++){
    ledOn(0);
    ledOn(1);
    ledOn(2);
    ledOn(3);
    ledOn(2);
    ledOn(1);
    ledOn(0);
  }
  delay(1000);
  do {
    gameState = newLevel(level, ledOrder);
    delay(1000);
    level++;
  }
  while (gameState == 1); //While you did nothing wrong the game flows
  if (gameState == 0){ //If you did something wrong the game stops, blinks the leds and restarts
    error();
    delay(2000);
    gameState = 1;
  }
}
