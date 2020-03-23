//Buzzer is connected to pin 8
#define buzzer 8

//Constants:
const int ledPin = 9;  //pin 9 has PWM funtion
const int potPin = A0; //pin A0 to read analog input
const int ledPin1 = 10;  //pin 10 also has PWM funtion
const int potPin1 = A1; //pin A1 to read analog input

//Variables:
int value;
int value1;


void setup(){
  //Input or output?
  pinMode(ledPin, OUTPUT); 
  pinMode(potPin, INPUT);
  pinMode(ledPin1, OUTPUT); 
  pinMode(potPin1, INPUT);
  pinMode(buzzer, OUTPUT);
}

void loop(){
  //Read values
  value = analogRead(potPin);
  value1 = analogRead(potPin1);
  
  //Map values
  value = map(value, 0, 1023, 0, 255);
  value1 = map(value1, 0, 1023, 0, 255);
  
  //Set LEDs to analog values
  analogWrite(ledPin, value);
  analogWrite(ledPin1, value1);

  //Update buzzer
  tone(buzzer, value, value1);

  //Print values
  Serial.println("0 - ");
  Serial.print(value);
  Serial.println("1 - ");
  Serial.print(value1);
}
