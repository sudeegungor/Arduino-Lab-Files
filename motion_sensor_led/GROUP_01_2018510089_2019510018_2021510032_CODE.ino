int TIMER_START = 30;
int TIMER_SPEED = 500;
int ANIMATION_SPEED = 100;


int temp_timer_start = TIMER_START;
int animationCounter = 0;
int SENSOR_PIN = 2;
int LED_PIN = 10;
int sensor_state = 0;
int A = 3;
int B = 4;
int C = 5;
int D = 6;
int E = 7;
int F = 8;
int G = 9;
unsigned long previousMillisAnimation = 0;
unsigned long previousMillisTimer = 0;
bool cleanScreen = true;
bool sensorActive= false;
void setup()
{
  Serial.begin(9600);
  pinMode(SENSOR_PIN,INPUT_PULLUP);
  pinMode(LED_PIN,OUTPUT);
  pinMode(A,OUTPUT);
  pinMode(B,OUTPUT);
  pinMode(C,OUTPUT);
  pinMode(D,OUTPUT);
  pinMode(E,OUTPUT);
  pinMode(F,OUTPUT);
  pinMode(G,OUTPUT);
  
}

void loop()
{
  sensor_state = digitalRead(2);
  digitalWrite(LED_PIN,LOW);
  if(cleanScreen){
    digitalWrite(A,HIGH);
  	digitalWrite(B,HIGH);
  	digitalWrite(C,HIGH);
  	digitalWrite(D,HIGH);
  	digitalWrite(E,HIGH);
 	 digitalWrite(F,HIGH);
    digitalWrite(G,HIGH);
  }
	
  unsigned long currentMillis = millis();
  
  
  if(sensor_state == HIGH){
   	cleanScreen=false;
  	sensorActive=true;
  }
  
  
  if(sensorActive==true){
  	 timer(currentMillis);
    digitalWrite(LED_PIN,HIGH);
    if(temp_timer_start>=0){
      
      if(temp_timer_start>15){
      	 
    	animation(currentMillis);
      }
      else{
      	counter(temp_timer_start);
        
      }
    }
    else{
    temp_timer_start = TIMER_START;
      sensorActive=false;
      cleanScreen=true;
      animationCounter = 0;
    }
  }
  
}
void timer(long currentMillis){
	if(currentMillis - previousMillisTimer>TIMER_SPEED){
  	previousMillisTimer += TIMER_SPEED;
    temp_timer_start--;
	Serial.println(temp_timer_start);
  }
}
void counter(int time){
  switch(time){
  	case 15:
    	charF();
     	break;
    case 14:
    	charE();
     	break;
    case 13:
    	charD();
     	break;
    case 12:
    	charC();
     	break;
    case 11:
    	charB();
     	break;
    case 10:
    	charA();
     	break;
    case 9:
    	nine();
     	break;
    case 8:
    	eight();
     	break;
    case 7:
    	seven();
     	break;
    case 6:
    	six();
     	break;
    case 5:
    	five();
     	break;
    case 4:
    	four();
     	break;
    case 3:
    	three();
     	break;
    case 2:
    	two();
        break;
    case 1:
    	one();
     	break;
    case 0:
    	zero();
    	break;
    default:break;
  }

}

void zero(){
  digitalWrite(A,LOW);
  digitalWrite(B,LOW);
  digitalWrite(C,LOW);
  digitalWrite(D,LOW);
  digitalWrite(E,LOW);
  digitalWrite(F,LOW);
  digitalWrite(G,HIGH);	
}

void one(){
  digitalWrite(A,HIGH);
  digitalWrite(B,LOW);
  digitalWrite(C,LOW);
  digitalWrite(D,HIGH);
  digitalWrite(E,HIGH);
  digitalWrite(F,HIGH);
  digitalWrite(G,HIGH);
}

void two(){
  digitalWrite(A,LOW);
  digitalWrite(B,LOW);
  digitalWrite(C,HIGH);
  digitalWrite(D,LOW);
  digitalWrite(E,LOW);
  digitalWrite(F,HIGH);
  digitalWrite(G,LOW);
}

void three(){
  digitalWrite(A,LOW);
  digitalWrite(B,LOW);
  digitalWrite(C,LOW);
  digitalWrite(D,LOW);
  digitalWrite(E,HIGH);
  digitalWrite(F,HIGH);
  digitalWrite(G,LOW);
}
void four(){
  digitalWrite(A,HIGH);
  digitalWrite(B,LOW);
  digitalWrite(C,LOW);
  digitalWrite(D,HIGH);
  digitalWrite(E,HIGH);
  digitalWrite(F,LOW);
  digitalWrite(G,LOW);
}
void five(){
  digitalWrite(A,LOW);
  digitalWrite(B,HIGH);
  digitalWrite(C,LOW);
  digitalWrite(D,LOW);
  digitalWrite(E,HIGH);
  digitalWrite(F,LOW);
  digitalWrite(G,LOW);
}

void six(){
  digitalWrite(A,LOW);
  digitalWrite(B,HIGH);
  digitalWrite(C,LOW);
  digitalWrite(D,LOW);
  digitalWrite(E,LOW);
  digitalWrite(F,LOW);
  digitalWrite(G,LOW);
}

void seven(){
  digitalWrite(A,LOW);
  digitalWrite(B,LOW);
  digitalWrite(C,LOW);
  digitalWrite(D,HIGH);
  digitalWrite(E,HIGH);
  digitalWrite(F,HIGH);
  digitalWrite(G,HIGH);
}
void eight(){
  digitalWrite(A,LOW);
  digitalWrite(B,LOW);
  digitalWrite(C,LOW);
  digitalWrite(D,LOW);
  digitalWrite(E,LOW);
  digitalWrite(F,LOW);
  digitalWrite(G,LOW);
}

void nine(){
  digitalWrite(A,LOW);
  digitalWrite(B,LOW);
  digitalWrite(C,LOW);
  digitalWrite(D,LOW);
  digitalWrite(E,HIGH);
  digitalWrite(F,LOW);
  digitalWrite(G,LOW);
}
void charA(){
  digitalWrite(A,LOW);
  digitalWrite(B,LOW);
  digitalWrite(C,LOW);
  digitalWrite(D,HIGH);
  digitalWrite(E,LOW);
  digitalWrite(F,LOW);
  digitalWrite(G,LOW);
}
void charB(){
  digitalWrite(A,LOW);
  digitalWrite(B,LOW);
  digitalWrite(C,LOW);
  digitalWrite(D,LOW);
  digitalWrite(E,LOW);
  digitalWrite(F,LOW);
  digitalWrite(G,LOW);
}
void charC(){
  digitalWrite(A,LOW);
  digitalWrite(B,HIGH);
  digitalWrite(C,HIGH);
  digitalWrite(D,LOW);
  digitalWrite(E,LOW);
  digitalWrite(F,LOW);
  digitalWrite(G,HIGH);
}
void charD(){
  digitalWrite(A,LOW);
  digitalWrite(B,LOW);
  digitalWrite(C,LOW);
  digitalWrite(D,LOW);
  digitalWrite(E,LOW);
  digitalWrite(F,LOW);
  digitalWrite(G,HIGH);
}
void charE(){
  digitalWrite(A,LOW);
  digitalWrite(B,HIGH);
  digitalWrite(C,HIGH);
  digitalWrite(D,LOW);
  digitalWrite(E,LOW);
  digitalWrite(F,LOW);
  digitalWrite(G,LOW);
}
void charF(){
  digitalWrite(A,LOW);
  digitalWrite(B,HIGH);
  digitalWrite(C,HIGH);
  digitalWrite(D,HIGH);
  digitalWrite(E,LOW);
  digitalWrite(F,LOW);
  digitalWrite(G,LOW);
}


void animation(long currentMillis){
  
  if(currentMillis - previousMillisAnimation>ANIMATION_SPEED){
  
  	previousMillisAnimation += ANIMATION_SPEED;
    
    switch(animationCounter% 3){
    	case 0:
      		digitalWrite(E,HIGH);
  			digitalWrite(F,HIGH);
      		digitalWrite(A,LOW);
  			digitalWrite(B,LOW);
      		break;
      	case 1:
      		digitalWrite(A,HIGH);
  			digitalWrite(B,HIGH);
      		digitalWrite(C,LOW);
  			digitalWrite(D,LOW);
      		break;
      	case 2:
      		digitalWrite(C,HIGH);
  			digitalWrite(D,HIGH);  
      		digitalWrite(E,LOW);
  			digitalWrite(F,LOW);
      		break;
      	default: break;
    	
    }
    animationCounter +=1;
 

  }
}