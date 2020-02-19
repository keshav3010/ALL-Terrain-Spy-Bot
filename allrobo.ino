int lm1=2,lm2=3,rm1=4,rm2=5;
int b=9;
void Forward()
{
  analogWrite(lm1,255);
  analogWrite(lm2,0);
  analogWrite(rm1,255);
  analogWrite(rm2,0);
}

void Stop()
{
  analogWrite(lm1,0);
  analogWrite(lm2,0);
  analogWrite(rm1,0);
  analogWrite(rm2,0);
}


void Reverse()
{
  analogWrite(lm1,0);
  analogWrite(lm2,255);
  analogWrite(rm1,0);
  analogWrite(rm2,255);
}


void Right()
{
  analogWrite(lm1,255);
  analogWrite(lm2,0);
  analogWrite(rm1,0);
  analogWrite(rm2,255);
}

void Left()
{
  analogWrite(lm1,0);
  analogWrite(lm2,255);
  analogWrite(rm1,255);
  analogWrite(rm2,0);
}
const int chD=12;
const int chB=10;  //Constant variables relating to pin locations
int ch2;
const int chC=11;  //Constant variables relating to pin locations
int ch3;//Varibles to store and display the values of each channel
int ch4;                                                
// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(115200);
  // Set input pins
  pinMode(chB, INPUT);
  pinMode(chC, INPUT);
  pinMode(chD, INPUT);
  pinMode(lm1,OUTPUT);
  pinMode(lm2,OUTPUT);
  pinMode(rm1,OUTPUT);
  pinMode(rm2,OUTPUT);
  pinMode(b,OUTPUT);
  
}

//Main Program
void loop()
{

 ch2 = pulseIn (chB,HIGH);
 ch3 = pulseIn (chC,HIGH);
 ch4 = pulseIn (chD,HIGH);
 

 Serial.print(ch2);
 Serial.print(ch3);
 Serial.print(ch4);
 Serial.println();
 if((ch2>1300&&ch2<1700)&&(ch3<1700&&ch3>1300))
 {
  Stop();
  
 }
  else if(ch3<1300)
  {
    Left();
  }

  //right
  else if(ch3>1700)
  {
    Right();
   }
  //left 
  else if(ch2>1700)
  {
    Forward();

  }

  else if(ch2<1300)
  {
    Reverse();
  }
  if(ch4>1500)
  {
    analogWrite(b,100);
  }
  else if(ch4<1500)
  {
    
    analogWrite(b,0);
  }
}  
  


