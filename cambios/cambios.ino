bool derecha=true;
int velocidad=200;
const int motorS1=10; const int motorS2=11;

void setup() {
  pinMode(6,INPUT); /* A y cambio (Inicio)*/
  pinMode(7,INPUT); // P
  pinMode(8,INPUT);
  pinMode(9,INPUT);
  pinMode(10,OUTPUT); /* motorS1 */ 
  pinMode(11,OUTPUT);  //motorS2
}
void loop() {
  bool Inicio=digitalRead(6);
  bool Paro=digitalRead(7);
  bool masVel=digitalRead(8);
  bool menosVel=digitalRead(9);
  if (Inicio && !Paro  ) {
    while(digitalRead(6));
    derecha=!derecha;
  }
  if (masVel)
  {
    while(digitalRead(8));
    velocidad+= 2;
   }
   if(menosVel){
     while(digitalRead(9));
     velocidad-=2;
   }
   if (Paro)
   {
     velocidad=0;
     derecha=true;
   }
   analogWrite(!derecha?motorS1:motorS2,0);
   analogWrite(derecha?motorS1:motorS2,velocidad);
   while(digitalRead(7)); 
}
