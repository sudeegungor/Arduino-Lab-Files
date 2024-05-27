

#define LED 2
#define SENSOR A1

int LED_ACTIVATION_VALUE = 200;
int SERIAL_OUTPUT_FREQUENCY = 500; 
int counter = 0;
int status = 0;

void setup()
{
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  	long start_time = micros();
 	
  
  	digitalWrite(LED, LOW);
  	int value = analogRead(SENSOR);
  	
  if(value >= LED_ACTIVATION_VALUE ){
    digitalWrite(LED, LOW);
  	status = 1;
  }
  else{
    digitalWrite(LED, HIGH);
    status = 0;
  }
  
  if (counter % SERIAL_OUTPUT_FREQUENCY == 0){
    Serial.print("LIGHT SENSOR: ");
    Serial.print(value);
    Serial.println();
    
    Serial.print("LED   STATUS: ");
    if (status) Serial.print("OFF");
    else Serial.print("ON");
    Serial.println();
  }
    
  long end_time = micros();
  if ((1000 - (end_time - start_time)) > 0)delayMicroseconds(1000 - (end_time - start_time));
  counter++;
}
