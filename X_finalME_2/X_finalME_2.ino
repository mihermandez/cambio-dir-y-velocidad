bool derecha=true;
int velocidad;
const int motor1=10;
const int motor2=11;

void setup() {
  pinMode(6,INPUT); // A y cambio
  pinMode(7,INPUT); // P
  pinMode(8,INPUT); // +
  pinMode(9,INPUT); // -
  pinMode(10,OUTPUT); // motor1
  pinMode(11,OUTPUT); // motor2
  Serial.begin(4800);
}

void loop() {
  bool Inicio=digitalRead(6);
  bool Paro=digitalRead(7);
  bool masVel=digitalRead(8);
  bool menosVel=digitalRead(9);
  
  if (Inicio && !Paro)
  {
    while(digitalRead(6));
    derecha=!derecha;
    velocidad=180;
  }
  if (Paro)
  {
     velocidad=0;
     Serial.println("Detenido");
     delay(400);
     analogWrite(motor1,0);
     analogWrite(motor2,0);
  }
  if (derecha==true)
  {
    if (masVel)
    {
      while(digitalRead(8));
      velocidad+= 5;
    }
    if(menosVel)
    {
      while(digitalRead(9));
      velocidad-=5;
    }
    if (velocidad!=0)
    {
      analogWrite(motor2,velocidad);
      analogWrite(motor1,0);
      Serial.print("Girando a la derecha. Velocidad = ");
      Serial.println(velocidad);
      delay(400);
    }
  }
  else if (derecha==false)
  {
    if (masVel)
    {
      while(digitalRead(8));
      velocidad+= 5;
    }
    if(menosVel)
    {
      while(digitalRead(9));
      velocidad-=5;
    }
    if (velocidad!=0)
    {
      analogWrite(motor1,velocidad);
      analogWrite(motor2,0);
      Serial.print("Girando a la izquierda. Velocidad = ");
      Serial.println(velocidad);
      delay(400);
    }
  }
 }
