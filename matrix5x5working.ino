//update from SAnwandter

#define ROW1 2
#define ROW2 3
#define ROW3 4
#define ROW4 5
#define ROW5 6

#define COL1 7
#define COL2 8
#define COL3 9
#define COL4 10
#define COL5 11


const byte rows[] = {ROW1, ROW2, ROW3, ROW4, ROW5};
const byte col[] = {COL1, COL2, COL3, COL4,COL5};

//(1 = OFF, 0 = ON)
byte Heart[] = {B11011,B10101,B01110,B01010,B10101};
byte Pumkin[] = {B10001,B01110,B01110,B10001,B11011};
byte P[] = {B01111,B01111,B00001,B01110,B00001};
byte O[] = {B10001,B01110,B01110,B01110,B10001};
byte L[] = {B00000,B01110,B01111,B01111,B01111};
byte Y[] = {B11011,B11011,B10101,B01110,B01110};
byte M[] = {B01110,B01110,B01010,B00100,B01110};
byte I[] = {B00000,B11011,B11011,B11011,B00000};
byte S[] = {B00001,B11110,B10001,B01111,B10000};
byte H[] = {B01110,B01110,B00000,B01110,B01110};
byte G[] = {B00000,B01110,B01100,B01111,B00000};
byte A[] = {B01110,B01110,B00000,B01110,B10001};
byte B[] = {B00001,B01110,B00001,B01110,B00001};
byte R[] = {B01110,B01110,B00001,B01110,B00001};
byte D[] = {B00001,B01110,B01110,B01110,B00001};

float time = 0;

void setup() 
{
    Serial.begin(9600);
    for (byte i = 2; i <= 11; i++){
      pinMode(i, OUTPUT);
    }
}

void loop() {
  delay(5);
  time+=1;
  // Mishi();
  // Polly();
  // Gabi();
  // Radi();
  display(Pumkin);
}

void display(byte buffer[]) { 
  for (byte i = 0; i < 5; i++){
    digitalWrite(rows[i], HIGH);
    for (byte a = 0; a < 5; a++){
      digitalWrite(col[a],   (buffer[i] >> a) & 0x01);
      delayMicroseconds(100);

      digitalWrite(col[a], 1);
    }
    digitalWrite(rows[i], LOW);
  }
}

void Radi(){
  if(time < 100){
    display(R);
  }else if(time < 200){
    display(A);
  }
  else if(time < 300){
    display(D);
  }
  else if(time < 400){
    display(I);
  }
  else if(time < 500){
    display(Heart);
  }
  else if(time < 600){
    time = 0;
  }
}

void Gabi(){
  if(time < 100){
    display(G);
  }else if(time < 200){
    display(A);
  }
  else if(time < 300){
    display(B);
  }
  else if(time < 400){
    display(I);
  }
  else if(time < 500){
    display(Heart);
  }
  else if(time < 600){
    time = 0;
  }
}

void Mishi(){
  if(time < 100){
    display(M);
  }else if(time < 200){
    display(I);
  }
  else if(time < 300){
    display(S);
  }
  else if(time < 400){
    display(H);
  }
  else if(time < 500){
    display(I);
  }
  else if(time < 700){
    display(Heart);
  }
  else if(time < 800){
    time = 0;
  }
}

void Polly(){
  if(time < 100){
    display(P);
  }else if(time < 200){
    display(O);
  }
  else if(time < 300){
    display(L);
  }
  else if(time < 400){
    display(L);
  }
  else if(time < 500){
    display(Y);
  }
  else if(time < 700){
    display(Heart);
  }
  else if(time < 800){
    time = 0;
  }
}

