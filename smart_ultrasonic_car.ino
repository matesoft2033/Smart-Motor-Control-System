#define mt_1 3
#define mt_2 11
#define echo 5
#define trig 4
#define V 0.034

#define max_speed 255
#define med_speed 128
#define spec_speed1 86
#define spec_speed2 44
#define spec_speed3 2
#define stop 0
#define time 1000

int impulseTime;
float S;
int analog1;

void setup()
{
  Serial.begin(9600);
  pinMode(mt_1, OUTPUT);
  pinMode(mt_2, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void loop()
{
  digitalWrite(trig, 1);
  delayMicroseconds(10);
  digitalWrite(trig, 0);
  
  impulseTime = pulseIn(echo, 1);
  S = (V * impulseTime) / 2;
  
  if (S > 50) {
  	analogWrite(mt_1, max_speed);
    analogWrite(mt_2, max_speed);
  }
  if (S >= 40 && S <= 50) {
  	analogWrite(mt_1, med_speed);
    analogWrite(mt_2, med_speed);
  }
  if (S >= 30 && S < 40) {
  	analogWrite(mt_1, spec_speed1);
    analogWrite(mt_2, spec_speed1);
  }
  if (S >=20 && S < 30) {
  	analogWrite(mt_1, spec_speed2);
    analogWrite(mt_2, spec_speed2);
  }
  if (S > 10 && S < 20) {
  	analogWrite(mt_1, spec_speed3);
    analogWrite(mt_2, spec_speed3);
  }
  if (S <= 10) {
  	analogWrite(mt_1, stop);
    analogWrite(mt_2, stop);
    
    analogWrite(mt_2, max_speed);
    analogWrite(mt_1, stop);
    
  }
}