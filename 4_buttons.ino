#include <Stepper.h>
int Button = 8;
int Button2 = 9;
int Button3 = 10;
int Button4 = 11;
int button_cond1;
int button_cond2;
int button_cond3;
int button_cond4;
int del = 8;
const int stepsPerRevolution = 2048;  // change this to fit the number of steps per revolution
// for your motor
// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 2, 4, 3, 5);
int stepCount = 0;         // number of steps the motor has taken
int steps;

void Forward() { // should go forward by 50 steps
    int stepCount = 0; 
    while (stepCount < 2614.58) {
    steps = 1;
    myStepper.step(-steps);
    stepCount++;
    // delay(del);
    //    Serial.print("Forward steps :");
    //    Serial.println(stepCount);
    }
    
}

void setup() {
    myStepper.setSpeed(12);
    // initialize the serial port:
    Serial.begin(9600);
    pinMode(Button, INPUT_PULLUP);

    //myStepper.setSpeed(60);
}
void loop() {
  // step one step:
    button_cond1 = digitalRead(Button);
    button_cond2 = digitalRead(Button2);
    button_cond3 = digitalRead(Button3);
    button_cond4 = digitalRead(Button4);

    //run the loops depending on which button is pressed (the first one that is high takes priority)
    if (button_cond1 == HIGH) forwardLoop(1);
    else if (button_cond2 == HIGH) Load();
    else if (button_cond3 == HIGH) forwardLoop(10);
    else if (button_cond4 == HIGH) forwardLoop(20);
}

//move the motor forward, then wait a 5 second delay. loops the amount of time given to it
void forwardLoop(int loops){
    for(int i=0 ; i < loops ; i++){
        Forward();
        delay(1000);
    }
}
void Load() { // should go forward by 50 steps
    int stepCount = 0; 
    while (stepCount < 335.77) {
    steps = 1;
    myStepper.step(-steps);
    stepCount++;
    // delay(del);
    //    Serial.print("Forward steps :");
    //    Serial.println(stepCount);
    }}
