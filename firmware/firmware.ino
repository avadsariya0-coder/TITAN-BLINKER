int Button1 = D0;
int Button2 = D1;
int Button3 = D2;

int LED1 = D3;
int LED2 = D4;
int LED3 = D5;

long But1Time = 0;
long But2time = 0;

bool LED1State = false;
bool LED2State = false;
bool LED3State = false;

bool LastButton1 = HIGH;
bool LastButton2 = HIGH;
bool LastButton3 = HIGH;

long PressStart3 = 0;
long LastPress3 = 0;

void setup(){

  pinMode(Button1,INPUT_PULLUP);
  pinMode(Button2,INPUT_PULLUP);
  pinMode(Button3,INPUT_PULLUP);

  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(LED3,OUTPUT);
}

void loop(){

  bool CurrentButton1 = digitalRead(Button1);
  bool CurrentButton2 = digitalRead(Button2);
  bool CurrentButton3 = digitalRead(Button3);

  if(CurrentButton1 == LOW && LastButton1 == 
  HIGH){
    LED1State = !LED1State;

    But1Time = millis();

    delay(50);
  }

  if (CurrentButton2 == LOW && LastButton2 ==
  HIGH){

    LED2State =!LED2State;

    But2time = millis();

    delay(50);
  }

  if(abs(But2time - But1Time)<=2000){

    digitalWrite(LED2,HIGH);
  }else{
    digitalWrite(LED2,LED2State);
  }

if(CurrentButton3 == LOW && LastButton3 ==
HIGH){
  PressStart3 = millis();
}
if (CurrentButton3 == LOW){
  if (millis()- PressStart3 >= 2000){
    LED3State = true;
  }
}

if(CurrentButton3 == LOW && LastButton3 ==
HIGH){
  if (millis() - LastPress3 <= 400){
    LED3State = false;
  }
  LastPress3 = millis();
  delay(50);
}
digitalWrite(LED3,LED3State);

LastButton1 = CurrentButton1;
LastButton2 = CurrentButton2;
LastButton3 = CurrentButton3;
}
