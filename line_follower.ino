#define IR1 A0
#define IR2 A1
#define IR3 A2
#define IR4 A3
#define IR5 A4
#define IR6 A5
#define IR7 3
#define IR8 2
#define EnA 6
#define EnB 5
#define IN1 10
#define IN2 9
#define IN3 8
#define IN4 7
int i;
int ir[8];
const float Kp=3.5, Ki=0, Kd=1;
int P=0,I=0,D=0;
int PreviousErr = 0, Integral=0, error=0;
int initSpeed = 40;

void setup() {
  Serial.begin(9600);
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  pinMode(IR3, INPUT);
  pinMode(IR4, INPUT);
  pinMode(IR5, INPUT);
  pinMode(IR6, INPUT);
  pinMode(IR7, INPUT);
  pinMode(IR8, INPUT);
  pinMode(EnA, OUTPUT);
  pinMode(EnB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  delay(1000);
  forward(50,50,500);
}

void loop() {
  ir[0] = digitalRead(IR1);
  ir[1] = digitalRead(IR2);
  ir[2] = digitalRead(IR3);
  ir[3] = digitalRead(IR4);
  ir[4] = digitalRead(IR5);
  ir[5] = digitalRead(IR6);
  ir[6] = digitalRead(IR7);
  ir[7] = digitalRead(IR8);

for(i=0;i<7;i++)
 {
   Serial.print(ir[i]+"|");

 }
  // Serial.print(ir[0]);
  // Serial.print(" | ");
  // Serial.print(ir[1]);
  // Serial.print(" | ");
  // Serial.print(ir[2]);
  // Serial.print(" | ");
  // Serial.print(ir[3]);
  // Serial.print(" | ");
  // Serial.print(ir[4]);
  // Serial.print(" | ");
  // Serial.print(ir[5]);
  // Serial.print(" | ");
  // Serial.print(ir[6]);
  // Serial.print(" | ");
  // Serial.println(ir[7]);

  int active = ir[1]+ir[2]+ir[3]+ir[4]+ir[5]+ir[6];
  error = (ir[1]*20+ir[2]*15+ir[3]*10-ir[4]*10-ir[5]*15-ir[6]*20)/active;
  Serial.println(error);
  pid();
  detect90(); 
}

void forward(int RightSpeed, int LeftSpeed, int del){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(EnA, RightSpeed);
  analogWrite(EnB, LeftSpeed);
  delay(del);
  }

void left(int fSpeed, int rSpeed, int del){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(EnA, fSpeed);
  analogWrite(EnB, rSpeed);
  delay(del);
  }

void right(int fSpeed, int rSpeed, int del){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(EnA, rSpeed);
  analogWrite(EnB, fSpeed);
  delay(del);
  }

void pid(){
  P = error;
  I = I+Integral;
  D = error-PreviousErr;

  int correction = P*Kp + I*Ki + D*Kd;
  
  Integral = I;
  PreviousErr = error;

  int LS = initSpeed + correction;
  int RS = initSpeed - correction;

  if(LS < 0) LS = 0;
  else if(LS > 255) LS = 255;

  if(RS < 0) RS = 0;
  else if(RS > 255) RS = 255;

  Serial.println(RS);
  Serial.println(LS);
  forward(RS, LS, 0);
  }

void detect90(){
  if ((ir[7]&&ir[0]))left(50,10,200);// ==0
  else if (ir[0])right(50,10,500);
  else if (ir[7])left(50,10,500);
  }
