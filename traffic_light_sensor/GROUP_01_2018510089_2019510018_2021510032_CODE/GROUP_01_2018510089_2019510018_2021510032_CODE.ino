#define led 2
#define enA 3
#define in1 4
#define in2 5

int LED_WAIT_DURATION_MIN = 2000;
int LED_WAIT_DURATION_MAX = 6000;

int LED_ON_DURATION_MIN = 2000;
int LED_ON_DURATION_MAX = 6000;

int LIGHT_SENSOR_OUTPUT_INTERVAL = 1000;

int light_bound = 150;

int rand_wait = 0;
int rand_on = 0;
int led_on_counter = 1;
int led_wait_counter = 1;
int sensor_counter = 1;

int led_status = 0;
int sensor_value = 0;


void setup()
{
  pinMode(led, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(A0, INPUT);
  
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  
  rand_wait=random(LED_WAIT_DURATION_MIN,LED_WAIT_DURATION_MAX);
  Serial.begin(9600);
  Serial.print("LED is turned OFF for ");
  Serial.print(rand_wait);
  Serial.print(" milliseconds.");
  Serial.println();
}

void loop()
{
  long start_time = micros();;

  if(led_status == 0){
   
    if(led_wait_counter>=rand_wait){
      rand_on=random(LED_WAIT_DURATION_MIN,LED_WAIT_DURATION_MAX);
      digitalWrite(led, HIGH);
      led_status = 1;
      rand_wait = 0;
      led_wait_counter = 0;
      Serial.println();
      Serial.print("LED is turned ON for ");
      Serial.print(rand_on);
      Serial.print(" milliseconds.");
      Serial.println();
      Serial.println();
    }
    led_wait_counter++;
  }
  else if(led_status == 1){
    if(led_on_counter>=rand_on){
      rand_wait=random(LED_WAIT_DURATION_MIN,LED_WAIT_DURATION_MAX);
      digitalWrite(led, LOW);
      led_status = 0;
      rand_on = 0;
      led_on_counter = 0;
      Serial.println();
      Serial.print("LED is turned OFF for ");
      Serial.print(rand_wait);
      Serial.print(" milliseconds.");
      Serial.println();
      Serial.println();
    }
    led_on_counter++;
  }
  sensor();
  motor();
  long end_time = micros();
  if ((1000 - (end_time - start_time)) > 0)delayMicroseconds(1000 - (end_time - start_time));
 	
}
void sensor(){
    
 
  if(sensor_counter>=LIGHT_SENSOR_OUTPUT_INTERVAL){
    sensor_value = analogRead(A0);
    Serial.print("Light sensor output is ");
    Serial.print(sensor_value);
    Serial.print(".");
    Serial.println();
    sensor_counter=0;
  } 
  sensor_counter++;
}
void motor(){
  if (sensor_value > light_bound){
    digitalWrite(enA, LOW);
  }
  else{
    digitalWrite(enA, HIGH);
  }
}