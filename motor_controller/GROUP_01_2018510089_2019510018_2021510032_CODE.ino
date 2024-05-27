// Global variable.
int MOTOR_STEPS =4;

// Pin locations for the 7 segment display.
const int A = 9;
const int B = 8;
const int C = 5;
const int D = 6;
const int E = 7;
const int F = 10;
const int G = 11;

// Pins for left and right buttons.
const int leftButton = 12;
const int rightButton = 13;

// Pins for motor driver .
const int pinDriver1 = 3;
const int pinDriver2 = 2;
const int pinEnable = 4;

// Current MOTOR_STEP.
int currentStep = 0;

// Variables to hold button presses.
bool rightButtonPressed = false;
bool leftButtonPressed = false;


void setup()
{
  Serial.begin(9600); 
  
  // Set up pin modes.
  pinMode(G, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(leftButton, INPUT);
  pinMode(rightButton, INPUT);
  pinMode(pinDriver1, OUTPUT);
  pinMode(pinDriver2, OUTPUT);
  pinMode(pinEnable, OUTPUT);
  // Display zero at the beginning.
  zero(); 
  
 //If MOTOR_STEPS is not between  0 and 10, the user will be notified and a default value will be assigned.
  if (MOTOR_STEPS > 10 || MOTOR_STEPS < 0)
  {
    Serial.println("MOTOR_STEPS value should be between 0 and 10 (both included).");
    Serial.flush();
    Serial.println("Assigned default value 5 to MOTOR_STEPS.");
    Serial.flush();
    MOTOR_STEPS = 5;
  }
}

void loop()
{  
 
  // Checking for the left button.
  if (digitalRead(leftButton) == HIGH && currentStep > -MOTOR_STEPS
     && !leftButtonPressed)
  {
    currentStep--;
    updateDisplay();
    changeSpeed();
    leftButtonPressed = true;
  }
  else if (digitalRead(leftButton) == LOW)
  {
    leftButtonPressed = false;
  }
  
  // Checking for the right button.
  if (digitalRead(rightButton) == HIGH && currentStep < MOTOR_STEPS 
     &&!rightButtonPressed)
    
      
  {
    currentStep++;
    updateDisplay();
    changeSpeed();
    rightButtonPressed = true;
  }
  else if (digitalRead(rightButton) == LOW)
  {
    rightButtonPressed = false;
  }
  }


void changeSpeed()
{
  // Calculating the duty cycle percentage.
   int analogInput = map(abs(currentStep), 0, MOTOR_STEPS, 0, 255);

  if (currentStep == 0)  // Stop motor.
  {
    digitalWrite(pinEnable, 0);
  }
  else if (currentStep < 0) 
  {// spin motor counter-clockwise.
    digitalWrite(pinDriver1, LOW);
    digitalWrite(pinDriver2, HIGH);
    analogWrite(pinEnable, analogInput);
  }
  else if (currentStep > 0)
  { // spin motor clockwise.
    digitalWrite(pinDriver1, HIGH);
    digitalWrite(pinDriver2, LOW);
    analogWrite(pinEnable, analogInput);
  }
}

//display the number on the seven segment display.
void updateDisplay()
{
 switch(abs(currentStep)){
case 0:
zero();
break;
case 1:
one();
break;
case 2:
two();
break;
case 3:
three();
break;
case 4:
four();
break;
case 5:
five();
break;
case 6:
six();
break;
case 7:
seven();
break;
case 8:
eight();
break;
case 9:
nine();
break;
case 10:
ten();
break;
default:
break;
}
}

//seven segment codes
void zero()
{
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);
}

void one()
{
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}

void two()
{
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, LOW);
}

void three()
{
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, LOW);
}

void four()
{
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
}

void five()
{
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, HIGH);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
}

void six()
{
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
}

void seven()
{
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}

void eight()
{
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
}

void nine()
{
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, HIGH);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
}

void ten()
{
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
}