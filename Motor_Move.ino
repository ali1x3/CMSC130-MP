String Bval;
int mspeed;
String Direction;
int speed;
int speed_increment;
float hrt;

void setup(){
  Serial.begin(9600);
  Bval = "";
  mspeed = 120;
  Direction = "";
  speed = 70;
  speed_increment = 10;
  hrt = 0.5;

  pinMode(2, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop(){
  while (Serial.available() > 0) {
    Bval = Bval + ((char)(Serial.read()));
    delay(2);
  }
  //Serial.print(String(Direction));
  if(String(Bval).charAt(0)=='#'){
    Direction = Bval;
    if(String(Direction).charAt(1) == 'W'){ //Forward
    Serial.print("Test");
        digitalWrite(2,HIGH);
        analogWrite(5,speed);
        digitalWrite(4,LOW);
        analogWrite(6,(speed));
    } 
    else if(String(Direction).charAt(1) == 'Q'){ //Left Forward
        digitalWrite(2,HIGH);
        analogWrite(5,speed*(1-hrt));
        digitalWrite(4,LOW);
        analogWrite(6,(speed*(1+hrt)));
    } 
    else if(String(Direction).charAt(1) == 'E'){ //Right Forward
        digitalWrite(2,HIGH);
        analogWrite(5,speed*(1+hrt));
        digitalWrite(4,LOW);
        analogWrite(6,(speed*(1-hrt)));
    } 
    else if(String(Direction).charAt(1) == 'S'){ //Stop
        digitalWrite(2,LOW);
        analogWrite(5,0);
        digitalWrite(4,HIGH);
        analogWrite(6,0);
    } 
    else if(String(Direction).charAt(1) == 'X'){ //Back
        digitalWrite(2,LOW);
        analogWrite(5,speed);
        digitalWrite(4,HIGH);
        analogWrite(6,speed);
    } 
    else if(String(Direction).charAt(1) == 'Z'){ //Left Back
        digitalWrite(2,LOW);
        analogWrite(5,speed*(1-hrt));
        digitalWrite(4,HIGH);
        analogWrite(6,speed*(1+hrt));
    } 
    else if(String(Direction).charAt(1) == 'C'){ //Right Back
        digitalWrite(2,LOW);
        analogWrite(5,speed*(1+hrt));
        digitalWrite(4,HIGH);
        analogWrite(6,speed*(1-hrt));
    } 
    else if(String(Direction).charAt(1) == 'A'){ //Rotate Left
        digitalWrite(2,LOW);
        analogWrite(5,speed);
        digitalWrite(4,LOW);
        analogWrite(6,speed);
    } 
    else if(String(Direction).charAt(1) == 'D'){ //Rotate Right
        digitalWrite(2,HIGH);
        analogWrite(5,speed);
        digitalWrite(4,HIGH);
        analogWrite(6,speed);
    } 
    else{
      digitalWrite(2,HIGH);
      analogWrite(5,0);
      digitalWrite(4,HIGH);
      analogWrite(6,0);
    }
  }
  else if(String(Bval).charAt(0)=='%'){
    if(String(Bval).charAt(1)=='I'){
      speed=speed+speed_increment;
    }
    else if(String(Bval).charAt(1)=='R'){
      speed=40;
    }
    else if(String(Bval).charAt(1)=='L'){
      speed=speed-speed_increment;
    }
    else{
    }
    Bval = "";
  }
  Bval = "";
}
