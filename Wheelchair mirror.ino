#include <Keypad.h>
#define LEDOUTPUT 12
#define ROWS 4
#define COLS 4
#define PASSWORDSIZE 5

//keypad layout and pin mapping
char output[ROWS][COLS] = {{'1','2','3','A'},{'4','5','6','B'},{'7','8','9','C'},{'*','0','#','D'}};
byte colPins[COLS] = {5,4,3,2};
byte rowPins[ROWS] = {9,8,7,6};
Keypad keypad1 = Keypad(makeKeymap(output), rowPins, colPins, ROWS, COLS);

//defines the passcode and a place to store keypad inputs
char inputCode[PASSWORDSIZE];
char password[] = "1D56C";
byte i = 0, j;

void setup() {
  // put your setup code here, to run once:
  pinMode(LEDOUTPUT, OUTPUT);
  Serial.begin(9600); //sets baud rate 9600 KHz
}

void loop() {
  // put your main code here, to run repeatedly:
  inputCode[i] = keypad1.getKey();
  if(inputCode[i]){
    Serial.println(inputCode[i]);
    i++;
    for (j = 0; j < i; j++){
      if(inputCode[j] != password[j]){
        digitalWrite(LEDOUTPUT, LOW);
        Serial.println("Wrong code entered");
        i = 0;
        break; 
      }else if (j == PASSWORDSIZE-1 && inputCode[j] == password[j]){
        for (i = 0; i < 20; i++){
          digitalWrite(LEDOUTPUT, HIGH);
          delay(50);
          digitalWrite(LEDOUTPUT, LOW);
          delay(50);
        }
        digitalWrite(LEDOUTPUT, HIGH);
        Serial.println("Correct code entered"); 
        i = 0;
      }else{
        digitalWrite(LEDOUTPUT, HIGH);
      }
    } 
  }
}  
