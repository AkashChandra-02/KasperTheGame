void setup() {
  // 5 inputs
  // Start/Reset, Photoresistors
  // 6 outputs
  // Buzzer, LED Strip, LED1-4
   pinMode(2,OUTPUT); //LED1
   pinMode(3,OUTPUT); //LED2
   pinMode(4,OUTPUT); //LED3
   pinMode(5,OUTPUT); //LED4
   
   pinMode(6,OUTPUT); //Buzzer
   pinMode(7,OUTPUT); //LEDStrip

  Serial.begin(9600);
  randomSeed(analogRead(0));
  int ranLED;
  int sensor;
  boolean sense = false;
  ranLED = random(2,6);
  digitalWrite(7, LOW);
  //LED Dance
  int myPins[] = {2,3,4,5,4,3,2};
  for(int i = 0; i<8;i++)
  {
    digitalWrite(myPins[i],HIGH);
    delay(500);
    digitalWrite(myPins[i],LOW);
  }
  
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  //Turn on LED
  digitalWrite(ranLED,HIGH);

  Serial.println(ranLED);
  

  while(sense == false)
  {
    int voltageAtResistor = analogRead('A'+ranLED);
    //5v on
    //ambience .5 k ohms
    //not 5 volts off
    int voltage= voltageAtResistor * (5.0 / 1023.0);
    if(voltage > 4.3)
    {
      digitalWrite(7, LOW);
      digitalWrite(ranLED,LOW);
      tone(6,440,1000);
      delay(1500);
      digitalWrite(7, HIGH);    
      sense = true;
    }
  } 
}

void loop() {}
