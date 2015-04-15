//Genius

#include <TrueRandom.h>

const int buttonPin1 = 8;
const int buttonPin2 = 9;
const int buttonPin3 = 10;
const int buttonPin4 = 11; //Set buttons pins
int time = 0; //Set the time of 'waiting button'
int buttonCounter = 0; //Used to set the stage of the button counter
int gameState = 0; //gameState = 0 means 'everything ok' = 1 means 'you made somthing worng
int button1State, button2State, button3State, button4State; //Defines the state of the buttons
int a, b, c, d, e; //Randon numbers witch are stored in an array
int ledPin[4] = { 2, 3, 4, 5 }; //Contains the pins of the leds
int ledOrder[5]; //Stores the randon number to compare them with the 'buttonOrder'
int buttonOrder[5]; //Stores witch buttons were pressed
int level; //Used to make some 'if' conditions
int dly; //Sets the delay between leds and the time you have to press the button

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
  do {
    Serial.println("start");
    Serial.println(gameState);
    level0();
  }
  while (gameState == 0); //While you did nothing wrong the game flows
  if (gameState == 1){ //If you did something wrong the game stops, blinks the leds and restarts
    Serial.println("erro");
    blinkLeds();
    blinkLeds();
    blinkLeds();
    delay(2000);
    gameState = 0;
  }
}

void level0() {  
  delay(2000); //Wait 2 seconds to start the game
  level = 1; //We are in level 1
  dly = 500; //Sets the delay time
  Serial.println(level);
  a = TrueRandom.random(0,4); //Random a nunbem between 0 and 3
  ledOrder[0] = a; //And stores it here
  led1(); //Blinks the first random led
  waitButton(); //Commentary below
  checkTime(); //Commentary below
  checkBug(); //Commentary below
  buttonCounter = 0; //First button you press
  getButtonOrder(); //Commentary below
  if (ledOrder[0] == buttonOrder[0]) { //If the button pressed is right
    led1(); //Blinks the first led if you are right
    level1(); //Calls level 1
  }
  else {
    Serial.println("lvl0");
    Serial.println(ledOrder[0]);
    Serial.println(buttonOrder[0]);
    gameState = 1; //If the button is wrong stop the game
  }
}

void level1() {
  delay(2000);
  level = 2;
  dly = 400; //Each level the time you have decreases
  Serial.println(level);
  b = TrueRandom.random(0,4);
  ledOrder[1] = b;
  led1();
  delay(dly); //Waits the specified time between leds
  led2();
  waitButton();
  checkTime();
  checkBug();
  buttonCounter = 0;
  getButtonOrder();
  if (ledOrder[0] == buttonOrder[0]) {
    led1();
    waitButton();
    checkTime();
    checkBug();
    buttonCounter++; //Second button you press
    getButtonOrder();
    Serial.println(ledOrder[1]);
    Serial.println(buttonOrder[1]);
    Serial.println("aeho");
    if (ledOrder[1] == buttonOrder[1]){
      led2();
      Serial.println("aeho2");
      level2();
    }
  }
  else {
    Serial.println("lvl1");
    Serial.println(ledOrder[0]);
    Serial.println(buttonOrder[0]);
    Serial.println(ledOrder[1]);
    Serial.println(buttonOrder[1]);
    gameState = 1;
  }
}

void level2(){
  delay(2000);
  level = 3;
  dly = 300;
  c = TrueRandom.random(0,4);
  ledOrder[2] = c;
  led1();
  delay(dly);
  led2();
  delay(dly);
  led3();
  waitButton();
  checkTime();
  checkBug();
  buttonCounter = 0;
  getButtonOrder();
  if (ledOrder[0] == buttonOrder[0]) {
    led1();
    waitButton();
    checkTime();
    checkBug();
    buttonCounter++;
    getButtonOrder();
    if (ledOrder[1] == buttonOrder[1]){
      led2();
      waitButton();
      checkTime();
      checkBug();
      buttonCounter++;
      getButtonOrder();
      if(ledOrder[2] == buttonOrder[2]){
        led3();
        level3();
      }
    }
  }
  else {
    Serial.println("lvl2");
    gameState = 1;
  }
}

void level3(){
  delay(2000);
  level = 4;
  dly = 200;
  d = TrueRandom.random(0,4);
  ledOrder[3] = d;
  led1();
  delay(dly);
  led2();
  delay(dly);
  led3();
  delay(dly);
  led4();
  waitButton();
  checkTime();
  checkBug();
  buttonCounter = 0;
  getButtonOrder();
  if (ledOrder[0] == buttonOrder[0]) {
    led1();
    waitButton();
    checkTime();
    checkBug();
    buttonCounter++;
    getButtonOrder();
    if (ledOrder[1] == buttonOrder[1]){
      led2();
      waitButton();
      checkTime();
      checkBug();
      buttonCounter++;
      getButtonOrder();
      if(ledOrder[2] == buttonOrder[2]){
        led2();
     	waitButton();
   	    checkTime();
   	 	checkBug();
        buttonCounter++;
        getButtonOrder();
        if(ledOrder[3] == buttonOrder[3]){
          led4();
          level4();
        }
      }
    }
  }
  else {
    Serial.println("lvl3");
    gameState = 1;
  }
}

void level4(){
  delay(2000);
  level = 5;
  dly = 100;
  e = TrueRandom.random(0,4);
  ledOrder[4] = e;
  led1();
  delay(dly);
  led2();
  delay(dly);
  led3();
  delay(dly);
  led4();
  delay(dly);
  led5();
  waitButton();
  checkTime();
  checkBug();
  buttonCounter = 0;
  getButtonOrder();
  if (ledOrder[0] == buttonOrder[0]) {
    led1();
    waitButton();
    checkTime();
    checkBug();
    buttonCounter++;
    getButtonOrder();
    if (ledOrder[1] == buttonOrder[1]){
      led2();
      waitButton();
      checkTime();
      checkBug();
      buttonCounter++;
      getButtonOrder();
      if(ledOrder[2] == buttonOrder[2]){
        led3();
        waitButton();
        checkTime();
        checkBug();
        buttonCounter++;
        getButtonOrder();
        if(ledOrder[3] == buttonOrder[3]){
          led4();
          waitButton();
          checkTime();
          checkBug();
          buttonCounter++;
          getButtonOrder();
          if(ledOrder[4] == buttonOrder[4]){
            led5();
            youWin();
          }
        }
      }
    }
  }
  else {
    Serial.println("lvl4");
    gameState = 1;
  }
}

void led1(){ //The random nunbem is between 0 and 3 so the led that will be on is called by the array
  digitalWrite(ledPin[a], HIGH);
  delay(dly);
  digitalWrite(ledPin[a], LOW);
}

void led2(){
  digitalWrite(ledPin[b], HIGH);
  delay(dly);
  digitalWrite(ledPin[b], LOW);
}

void led3(){
  digitalWrite(ledPin[c], HIGH);
  delay(dly);
  digitalWrite(ledPin[c], LOW);
}

void led4(){
  digitalWrite(ledPin[d], HIGH);
  delay(dly);
  digitalWrite(ledPin[d], LOW);
}

void led5(){
  digitalWrite(ledPin[e], HIGH);
  delay(dly);
  digitalWrite(ledPin[e], LOW);
}

void getButtonState() { //Verifies if the buttons are 'on' or 'off'
  button1State = digitalRead(buttonPin1);
  button2State = digitalRead(buttonPin2);
  button3State = digitalRead(buttonPin3);
  button4State = digitalRead(buttonPin4);
}

void waitButton(){ //This function waits for the player to push a button
  if(level == 1){ //Each level the player has less time to press
    time = (dly / 5);
  }
  else if(level == 2){
    time = (dly / 2);
  }
  else if(level == 3){
    time = dly;
  }
  else if(level == 4){
    time = dly * 2.5;
  }
  else if(level == 5){
    time = dly * 10;
  }
  getButtonState();
  Serial.println("while");
  while (button1State == LOW && button2State == LOW && button3State == LOW && button4State == LOW && time <= 2000){ //While all buttos are 'low' and the time is lower than 2000ms
    getButtonState(); //Verifies the state
    delay(1); //Wait a milisecond
    time++; //Increase time
  }
  Serial.println("while3");
}

void checkTime(){ //If the player didnt pushed a button in some time (depends on the level) gameState changes to 1 and the game is over 
  if (time > 2000){
  Serial.println("tempo");
  gameState = 1;
  }
}

void getButtonOrder(){ //Get your button and puts it into an array
  Serial.println("order");
  if (buttonCounter == 0) { //If it is the first button
    Serial.println("order00");
    if (button1State == HIGH) {
       Serial.println("order0");
      buttonOrder[0] = 0; //Puts in first array
    }
    else if (button2State == HIGH) {
       Serial.println("order1");
      buttonOrder[0] = 1;
    }
    else if (button3State == HIGH) {
       Serial.println("order2");
      buttonOrder[0] = 2;
    }
    else if (button4State == HIGH) {
       Serial.println("order3");
      buttonOrder[0] = 3;
    }
  }
  if (buttonCounter == 1) { //Second
    Serial.println("order01");
    if (button1State == HIGH) {
      Serial.println("order10");
      buttonOrder[1] = 0; //Second array
    }
    else if (button2State == HIGH) {
      Serial.println("order11");
      buttonOrder[1] = 1;
    }
    else if (button3State == HIGH) {
      Serial.println("order12");
      buttonOrder[1] = 2;
    }
    else if (button4State == HIGH) {
      Serial.println("order13");
      buttonOrder[1] = 3;
    }
  }
   if (buttonCounter == 2) {
     Serial.println("order02");
    if (button1State == HIGH) {
      Serial.println("order20");
      buttonOrder[2] = 0;
    }
    else if (button2State == HIGH) {
      Serial.println("order21");
      buttonOrder[2] = 1;
    }
    else if (button3State == HIGH) {
      Serial.println("order22");
      buttonOrder[2] = 2;
    }
    else if (button4State == HIGH) {
      Serial.println("order23");
      buttonOrder[2] = 3;
    }
  }
   if (buttonCounter == 3) {
     Serial.println("order03");
    if (button1State == HIGH) {
      Serial.println("order30");
      buttonOrder[3] = 0;
    }
    else if (button2State == HIGH) {
      Serial.println("order31");
      buttonOrder[3] = 1;
    }
    else if (button3State == HIGH) {
      Serial.println("order32");
      buttonOrder[3] = 2; }
    else if (button4State == HIGH) {
      Serial.println("order33");
      buttonOrder[3] = 3;
    }
  }
   if (buttonCounter == 4) {
     Serial.println("order04");
    if (button1State == HIGH) {
      Serial.println("order40");
      buttonOrder[4] = 0;
    }
    else if (button2State == HIGH) {
      Serial.println("order41");
      buttonOrder[4] = 1;
    }
    else if (button3State == HIGH) {
      Serial.println("order42");
      buttonOrder[4] = 2;
    }
    else if (button4State == HIGH) {
      Serial.println("order43");
      buttonOrder[4] = 3;
    }
  }
}

void blinkLeds(){ //This function blinks all leds with a 200ms delay
  digitalWrite(ledPin[0], HIGH);
  digitalWrite(ledPin[1], HIGH);
  digitalWrite(ledPin[2], HIGH);
  digitalWrite(ledPin[3], HIGH);
  delay(200);
  digitalWrite(ledPin[0], LOW);
  digitalWrite(ledPin[1], LOW);
  digitalWrite(ledPin[2], LOW);
  digitalWrite(ledPin[3], LOW);
  delay(200);
}

void checkBug(){ //If the player pushes 2 or more buttons the gameStates changes to 1
  if (button1State == HIGH && button2State == HIGH){
    Serial.println("errooo");
    gameState = 1;
  }
  else if (button1State == HIGH && button3State == HIGH){
    Serial.println("erroo");
    gameState = 1;
  }
  else if (button1State == HIGH && button4State == HIGH){
    Serial.println("erro");
    gameState = 1;
  }
  else if (button2State == HIGH && button3State == HIGH){
    Serial.println("err");
    gameState = 1;
  }
  else if (button2State == HIGH && button4State == HIGH){
    Serial.println("er");
    gameState = 1;
  }
  else if (button3State == HIGH && button4State == HIGH){
    Serial.println("e");
    gameState = 1;
  }
}  

void youWin(){ //Blinks the leds 5 times
  Serial.println("WINNNN");
  blinkLeds();
  blinkLeds();
  blinkLeds();
  blinkLeds();
  blinkLeds();
  gameState = 0;
}
