#include <SoftwareSerial.h> //Librería que permite establecer comunicación serie en otros pins
//Aquí conectamos los pins RXD,TDX del módulo Bluetooth.
SoftwareSerial BT(10,11); //10 RX, 11 TX.
int giro1=2; //Pin LED Red
int velocidad=3;//Pin LED Green
int giro2=4; //Pin LED Blue
 
void setup()
{
  BT.begin(9600);  //Velocidad del puerto del módulo Bluetooth
  pinMode(giro1,OUTPUT);
  pinMode(velocidad,OUTPUT);
  pinMode(giro2,OUTPUT);
}
void loop()
{
  //Cuando haya datos disponibles
  while (BT.available()>0)
  {
    int valor1 = BT.parseInt(); //Leemos el primer valor entero (Red) y lo almacenamos en la variable
    int valor2 = BT.parseInt(); //Leemos el segundo valor entero (Green) y lo almacenamos en la variable
    int valor3 = BT.parseInt(); //Leemos el último valor entero (Blue) y lo almacenamos en la variable
    //Cuando lea el carácter fin de línea ('\n') quiere decir que ha finalizado el envío de los tres valores
    if (BT.read() == '\n')
    {
      //Enviamos los valores de los tres colores al LED RGB através de PWM
      analogWrite(giro1,valor1);
      analogWrite(giro2,valor2);
      analogWrite(velocidad,valor3);
    }
  }
}
