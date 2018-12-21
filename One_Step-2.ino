char command;
String string;
String string2;
int steps_from_command;
//These next three lines declare the pins that were used to connect the arduino board to the microstep driver
const int stepPin = 5; 
const int dirPin = 3; 
const int enPin = 2;

//#include <AFMotor.h>

// Connect a stepper motor with 200 steps per revolution
// to motor port #1 (M1 and M2)
//AF_Stepper motor(200, 1);
//AF_Stepper motor(200, 1);
  void setup()
  {
    //Declaring and setting up the serial port
   Serial.begin(9600);
   //This tests to see if there is a signal in the serial monitor
   //While there is no signal in the serial monitor it prints Stepper test
   Serial.println("Stepper test!");
     while(!Serial){}
   // motor.setSpeed(150);

//All of the pins declared above are outputting information to the microstep driver
    pinMode(stepPin, OUTPUT);
    pinMode(dirPin, OUTPUT);
    pinMode(enPin, OUTPUT);
  }

  void loop()
  {
    //If the serial monitor isn't busy this is preparing it to take a string as an input and tell the microstep driver to do something
    if (Serial.available() > 0) 
    {string = "";
 Serial.println("Stepper test1");
  }
    
    while(Serial.available() > 0)
    {
      command = ((byte)Serial.read());
     //Serial.println(command);
     //If the serial monitor gets a command, we stop checking if it's busy     
      if(command == ':')
      {
        break;
      }      
      else
      {
        string += command;
      }
      delay(1);
    }

// now we get the number
while(Serial.available() > 0)
    {
      command = ((byte)Serial.read());
     //Serial.println(command);
      if(command == ':')
      {
        break;
      }
      else
      {
        string2 += command;
      }  
      delay(1);
    }
//
steps_from_command=string2.toInt();
string2="";
// now we check what is string  
 //This is telling the motor if it should rotate forward or backward
    if(string == "F")
    {
      Forward(steps_from_command);
      string="";
      
    }
    
    if(string == "B")
    {
      Backward(steps_from_command);
      string="";
   
    }
 }

 
// These subroutines need to be adopted considering the particular stepping motor controller that you are using
    void Forward(int steps)
    {  
      //While i is less than the int steps, it will increment and cause the motor to move forward one setp
      //this will keep happenning unil the motor has moved the number of steps
       digitalWrite(dirPin, HIGH);
      for(int i=0; i<steps; i++){
        digitalWrite(stepPin, HIGH);
        delay(1);
        digitalWrite(stepPin, LOW);
        delay(1);
        }


//          motor.step(steps, FORWARD, SINGLE);
         // digitalWrite(13, HIGH);
         // delay(50);
   Serial.println("Forward  OK");
          delay(20);
    }
  //This does the same thing as above but in a different direction.  
    void  Backward(int steps)
    {
      digitalWrite(dirPin, LOW);
      for(int i=0; i<steps; i++){
        digitalWrite(stepPin, HIGH);
        delay(1);
        digitalWrite(stepPin, LOW);
        delay(1);
        }
        
//      motor.step(steps, BACKWARD, SINGLE); 
      //digitalWrite(13, LOW);
      //delay(50);
     Serial.println("BACKWARD OK");
     delay(20);
    }
    
