#include <Wire.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(11, 10, 5, 4, 3, 2); // RS, E, D4, D5, D6, D7

#define echoPin 6
#define trigPin 7
#define led 8
#define buzzerPin 12


int BUZZER_LED_DURATION_MAX = 500;
int BUZZER_LED_DURATION_MIN = 10;

int DISTANCE_MAX = 50;
int DISTANCE_MIN = 10;

int CURRENT_DISTANCE = 0;
int CURRENT_DURATION = 0;

int UPDATE_DURATION_BUZZER = 200;
int UPDATE_DURATION_LCD = 200;

int counter = 0;
int buzzer_led_status = 0;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  //lcd.setBacklight(1);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(led,OUTPUT);
  
  //CURRENT_DURATION = (((CURRENT_DISTANCE-DISTANCE_MIN)/(DISTANCE_MAX-DISTANCE_MIN))*(BUZZER_LED_DURATION_MAX-BUZZER_LED_DURATION_MIN));
  //CURRENT_DURATION += BUZZER_LED_DURATION_MIN;
  Serial.begin(9600); 
}

void loop() {
  long start_time = micros();
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW); 
  int duration = pulseIn(echoPin,HIGH);
  
  CURRENT_DISTANCE = (duration/29.1)/2;
  
  if(DISTANCE_MAX==DISTANCE_MIN)
  {
    lcd.setCursor(0, 0);
    lcd.print("DIVISION ERROR");
  }
    

  if(counter % UPDATE_DURATION_BUZZER == 0){
    CURRENT_DURATION = int(float(float(CURRENT_DISTANCE-DISTANCE_MIN)/float(DISTANCE_MAX-DISTANCE_MIN))*float(BUZZER_LED_DURATION_MAX-BUZZER_LED_DURATION_MIN)) + BUZZER_LED_DURATION_MIN;
    if(CURRENT_DURATION>= BUZZER_LED_DURATION_MAX){
      CURRENT_DURATION= BUZZER_LED_DURATION_MAX;
    }
    else if(CURRENT_DURATION<=BUZZER_LED_DURATION_MIN){
      CURRENT_DURATION=BUZZER_LED_DURATION_MIN;
    }
  }
  if(counter % UPDATE_DURATION_LCD == 0){
  lcd.setCursor(0, 0);             // 1. satır, 1. sütuna git
    lcd.print("DISTANCE :"); 
    Serial.print("  DISTANCE :");
    if(CURRENT_DISTANCE/1000>=1){lcd.print("");Serial.print(""); }
    else if (CURRENT_DISTANCE/100>=1) {lcd.print(" ");Serial.print("");}
    else {lcd.print("  ");Serial.print("");}
    lcd.print(CURRENT_DISTANCE); 
    Serial.print(CURRENT_DISTANCE); 
    Serial.print(" cm"); 
    lcd.print("cm"); 


    lcd.setCursor(0,1);             // 1. satır, 1. sütuna git
    lcd.print("DURATION :"); 
    Serial.print("  DURATION :");
    if(CURRENT_DURATION/1000>=1)lcd.print("");
    else if (CURRENT_DURATION/100>=1) lcd.print(" ");
    else lcd.print("  ");
    lcd.print(CURRENT_DURATION); 
    Serial.print(CURRENT_DURATION); 
    lcd.print("ms");
    Serial.println(" ms");
         // Mesaj2'yi yazdır
    
  }
  

  if ( CURRENT_DISTANCE <= DISTANCE_MAX)
  {
    if(counter % CURRENT_DURATION == 0){
      if(buzzer_led_status == 0) {
      	digitalWrite(led,HIGH);
        tone(buzzerPin,CURRENT_DURATION);
        buzzer_led_status = 1;
      }
      else{
        noTone(buzzerPin);
        digitalWrite(led,LOW);
        buzzer_led_status = 0;
      }
    }
  }
  else{
    noTone(buzzerPin);
    digitalWrite(led,LOW);
    buzzer_led_status = 0;
  }
  
  long end_time = micros();
  if ((1000 - (end_time - start_time)) > 0)delayMicroseconds(1000 - (end_time - start_time));
  counter= counter +1;
}