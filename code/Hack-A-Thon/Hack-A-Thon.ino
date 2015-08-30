#define NUM_ELEM(x) (sizeof (x) / sizeof (*(x)))
#define BUTTON 2

int val = 0;
int old_val = 0;
int state = 0;

int old_state = 0;

 int morrow[] = {

 0,0,0,0,0,0,0,0,
 0,1,1,1,1,1,1,0,
 0,1,1,1,1,1,1,0, //o
 1,1,0,0,0,0,1,1,
 0,1,1,1,1,1,1,0,
 0,1,1,1,1,1,1,0,
 0,0,0,0,0,0,0,0,

 0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,
 1,1,1,1,1,1,1,1,
 1,1,1,1,1,1,1,1,//n
 0,0,0,0,0,0,1,1,
 1,1,1,1,1,1,1,1,
 1,1,1,1,1,1,1,1,
 0,0,0,0,0,0,0,0,

 0,0,0,0,0,0,0,0,
 1,1,1,1,1,1,1,1,
 1,1,1,1,1,1,1,1,
 1,0,0,1,1,0,0,1,
 1,0,0,1,1,0,0,1,
 1,0,0,1,1,0,0,1,
 0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,
 };


 int hi[] = {
 0,0,0,0,0,0,0,0,
 1,1,1,1,1,1,1,1, //h
 1,1,1,1,1,1,1,1,
 0,0,0,1,1,0,0,0,
 0,0,0,1,1,0,0,0,
 1,1,1,1,1,1,1,1,
 1,1,1,1,1,1,1,1,
 0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,

 0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,
 1,1,0,0,0,0,1,1, 
 1,1,0,0,0,0,1,1, //i
 1,1,1,1,1,1,1,1,
 1,1,1,1,1,1,1,1,
 1,1,0,0,0,0,1,1,
 1,1,0,0,0,0,1,1,
 0,0,0,0,0,0,0,0,

 };



 int ledPin13 = 13; // LED connected to digital pin 13
 int ledPin12 = 12; // LED connected to digital pin 13
 int ledPin11 = 11; // LED connected to digital pin 13
 int ledPin10 = 10; // LED connected to digital pin 13
 int ledPin9 = 9; // LED connected to digital pin 13
 int ledPin8 = 8; // LED connected to digital pin 13
 int ledPin7 = 7; // LED connected to digital pin 13
 int ledPin6 = 6; // LED connected to digital pin 13
 int ground = 5; // LED connected to digital 5 "ground"

 int ledPinArray[8] = {6,7,8,9,10,11,12,13};
 // The setup() method runs once, when the sketch starts

 int columnDelay;
 int sizeWord = 0;
 
 void setup() { 
  pinMode(BUTTON,INPUT);
 // initialize the digital pin as an output:
   for(int i = 0; i < 8; i++){
     pinMode(ledPinArray[i],OUTPUT);
   }
   pinMode(ground, OUTPUT); 
   digitalWrite(ground, LOW); 

   columnDelay = 2.5; //wait 2.5ms between each column flash
   Serial.begin(9600);
   delay(2000);
 }

 // the loop() method runs over and over again,
 // as long as the Arduino has power

 /*void loop() 
 {
 for(int i = 0; i < 8; i++){
 digitalWrite(ledPinArray[i],HIGH);
 }

 delay(1000); // wait for a second
 for(int i = 0; i < 8; i++){
 digitalWrite(ledPinArray[i],LOW);
 }
   delay(1000); // wait for a second
 }*/

 void loop()
 {
 //Serial.print("Number of lilypad: ");
 //Serial.println(NUM_ELEM(lilypad));
 //delay(1000);


  Serial.print(digitalRead(BUTTON));

  state = digitalRead(BUTTON);
// button코드 추가.
  if (state == HIGH && old_state == LOW){
    if(old_val == 0){
      val ++;
    }
     else if(old_val == 1){
        val ++;
     }
     else if(old_val == 2){
        val = 0;
     }
     delay(30);
  }
  
  //if((val==HIGH) && (old_val == LOW)){
  //state = 1 - state;
  //delay(10);
  old_state = state;
  old_val = val;
  
  if(val == 0){
    pinMode(ledPin13,LOW);
    pinMode(ledPin12,LOW);
    pinMode(ledPin11,LOW);
    pinMode(ledPin10,LOW);
    pinMode(ledPin9,LOW);
    pinMode(ledPin8,LOW);
    pinMode(ledPin7,LOW);
    pinMode(ledPin6,LOW);
    Serial.println("finish");
  } else if (val == 1){
    if(digitalRead(ledPin13) == LOW){
      pinMode(ledPin13,HIGH);
      pinMode(ledPin12,HIGH);
      pinMode(ledPin11,HIGH);
      pinMode(ledPin10,HIGH);
      pinMode(ledPin9,HIGH);
      pinMode(ledPin8,HIGH);
      pinMode(ledPin7,HIGH);
      pinMode(ledPin6,HIGH);
    }
    sizeWord = NUM_ELEM(morrow);
    printWord(morrow);
   Serial.println("morrow");
  }
  else if (val == 2){
    if(digitalRead(ledPin13) == LOW){
      pinMode(ledPin13,HIGH);
      pinMode(ledPin12,HIGH);
      pinMode(ledPin11,HIGH);
      pinMode(ledPin10,HIGH);
      pinMode(ledPin9,HIGH);
      pinMode(ledPin8,HIGH);
      pinMode(ledPin7,HIGH);
      pinMode(ledPin6,HIGH);
    }
    sizeWord = NUM_ELEM(hi);
    printWord(hi);
    Serial.println("hi");
  }
 
   //printWord(lilypad);
   delay(30); //wait a little bit between each display of the word LilyPad
 }

 void printWord(int wordVar[]) {
   int numRows = sizeWord/8;
   for(int j = 0; j < numRows; j++) {
     for(int i = 0; i<8; i++) {
       digitalWrite(i+6, wordVar[i+j*8]);
     }
   delay(columnDelay);
   }
 }
