#include <LiquidCrystal.h>
#include <DHT.h>
#include <Wire.h>

#define buttonPin 2
#define DHTPIN A0   // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11  


LiquidCrystal lcd(8, 7, 6, 5, 4, 3);
DHT dht(DHTPIN, DHTTYPE);



int current_state = 0;
int change= 0;

void setup(){  
  lcd.begin(16, 2);
  lcd.clear();
  dht.begin();


  pinMode(A0, INPUT);
  pinMode(buttonPin,INPUT_PULLUP);
}

void loop(){
  


  int sensorVal = digitalRead(2);
  //when pressed
  if (sensorVal == LOW){
    if(change != 1){
      if(current_state ==1) current_state = 0;
      else current_state = 1;
    }
    change = 1;
  }
  else{
    change = 0;
  }
   
  if(current_state == 1){
     print_tr();
  }
  else{
     print_en();
  }
 
}

void print_tr(){
  lcd.setCursor(0, 0);
  lcd.print("SIC(C):");
   lcd.setCursor(14, 0);
  lcd.print("TR");
  lcd.setCursor(0, 1);
  lcd.print("NEM(%):");
  lcd.setCursor(7, 0);
  //sıcaklık
  if(dht.readTemperature()/100 >= 1){
    lcd.print(dht.readTemperature());
  }
  else{
    lcd.print(" ");
    lcd.print(dht.readTemperature());
  }
  //nem
  lcd.setCursor(7, 1);
  if(dht.readHumidity()/100 >= 1){
    lcd.print(dht.readHumidity());
  }
  else{
    lcd.print(" ");
    lcd.print(dht.readHumidity());
  }
}
  
void print_en(){
  lcd.setCursor(0, 0);
  lcd.print("TEM(F):");
  lcd.setCursor(14, 0);
  lcd.print("EN");
  lcd.setCursor(0, 1);
  lcd.print("HUM(%):");
  //temperature
  lcd.setCursor(7, 0);
  if(dht.readTemperature()/100 >= 1){
    lcd.print(dht.readTemperature(true));
  }
  else{
    lcd.print(" ");
    lcd.print(dht.readTemperature(true));
  }
  //humidity
  lcd.setCursor(7, 1);
  if(dht.readHumidity()/100 >= 1){
    lcd.print(dht.readHumidity());
  }
  else{
    lcd.print(" ");
    lcd.print(dht.readHumidity());
  }
}