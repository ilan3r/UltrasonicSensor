#include <LiquidCrystal.h>

int rs=7;
int en=8; 
int d4=9; 
int d5=10;
int d6=11; 
int d7=12; 
// set up variables for pins 

int buttonPin=4; 
int buttonValOld;
int buttonValNew;  

int dt=100;

LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
// create lcd object

int trigPin=3; 
int echoPin=2; 
int pingTravelTime; 
float distanceToObject; 

void setup() {

Serial.begin(9600); 

lcd.begin(16,2); 
pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT); 
//because lcd has 16 columns and 2 rows 

pinMode(buttonPin, INPUT); 
digitalWrite(buttonPin, HIGH);

}

void loop() {

Serial.println("================="); 
//this tells the user what to do
lcd.setCursor(0,0); 
lcd.print("place target"); 
lcd.setCursor(0,1); 
lcd.print("press button"); 

buttonValNew=digitalRead(buttonPin); 
// when button has been pressed from a released position, detect then display the distance

if (buttonValNew==0 && buttonValOld==1){
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(10); 
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  pingTravelTime = pulseIn(echoPin, HIGH);  
  delay(25); 
  distanceToObject=(pingTravelTime)*(34300./2000000.); 
  lcd.clear(); 
  lcd.setCursor(0,0); 
  lcd.print("Distance->object");
  lcd.setCursor(0,1); 
  lcd.print(distanceToObject); 
  lcd.print(" cm");
  delay(1000); 
  lcd.clear(); 
}

buttonValOld=buttonValNew; 

delay(dt); 
}
