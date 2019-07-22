#include <LiquidCrystal.h>
LiquidCrystal lcd (7, 8, 9, 10, 11, 12);
#include <SPI.h>
int ledPin = 13;
volatile byte rpmcount;
unsigned int rpm;
unsigned long timeold;
int prueba0=A0;
int prueba1=A1;

void rpm_fun()
{
 rpmcount++; 
}

void setup() {
  lcd.begin(16, 2);
  attachInterrupt(0, rpm_fun, FALLING);
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
  
  rpmcount = 0;
  rpm = 0;
  timeold = 0;
}

void loop(){
  int lectura0=analogRead(prueba0);
  lectura0 = map(lectura0, 0, 1023, 0, 255);
  int lectura1=analogRead(prueba1);
  lectura1 = map(lectura1, 0, 1023, 0, 255);
  delay(500);
  Serial.print(lectura0);
  Serial.print(lectura1);
  
  delay(1000);
  detachInterrupt(0);
  
  rpm= 30*1000/(millis() - timeold)*rpmcount;
  timeold = millis();
  rpmcount = 0;
  
  if (lectura0==0 && lectura1==0){
    Serial.println("Detenido");
    lcd.clear();
    lcd.setCursor(1,0);
    lcd.print("Motor detenido ");   // acá no :v puro LCD
    lcd.setCursor(14,1);
    lcd.print("   ");
    delay(750);
  }else
  if (lectura0 >= 3 && lectura1 == 0)
  {
    Serial.print("Giro1 a rpm= ");
    Serial.println(rpm);
    lcd.clear();
    lcd.print("Girando.");
    lcd.setCursor(9,0);
    lcd.print("RPM=");
    lcd.print(rpm);
    attachInterrupt(0, rpm_fun, FALLING);
    lcd.setCursor(1,3);
    lcd.print("S. Horario    ");*/
    delay(1000);
  }else
  if (lectura1 >= 3 && lectura0 == 0)
  {
    Serial.print("Giro2 a rpm= ");
    Serial.println(rpm);
    lcd.clear();
    lcd.print("Girando.");
    lcd.setCursor(9,0);
    lcd.print("RPM=");
    lcd.print(rpm);
    attachInterrupt(0, rpm_fun, FALLING);
    lcd.setCursor(1,1);
    lcd.print("S. Antihorario    ");
    delay(1000);
  }
}

