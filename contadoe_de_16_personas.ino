/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM  
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: LCD   
   De: Eliezer Denilson Gaitán Corado
*/
//libreria a utilizar
#include <LiquidCrystal.h>
#define trig 10   
#define echo    9
#define RS  12
#define e  11
#define D4  6
#define D5  4
#define D6  3
#define D7  2
#define buzzer 13

byte arriba[] = {
  B00100,
  B01110,
  B00100,
  B00101,
  B01110,
  B10100,
  B00100,
  B01010
};
byte abajo[] = {
 B00100,
  B01110,
  B00100,
  B10100,
  B01110,
  B00101,
  B00100,
  B01010
};

int contar = 0;


LiquidCrystal dni_LCD(RS, e, D4, D5, D6, D7); //Permite usar la LCD
void setup()
{
  dni_LCD.begin(16,2); //LCD de 16x2
  
  
  dni_LCD.createChar(1,arriba);
  dni_LCD.createChar(2,abajo);
  dni_LCD.setCursor(0,0);
  pinMode(trig, OUTPUT);
  pinMode(echo,INPUT);
}

void loop()
{
    long sensor, distancia; 
    delay(500);
    digitalWrite(trig, HIGH);
    delayMicroseconds(2);
    digitalWrite (trig, LOW);
    delayMicroseconds(5);
    sensor = pulseIn(echo, HIGH);
    distancia = sensor/59;
  
    if(distancia >= 6 && distancia <= 11){
     contar++;
       dni_LCD.setCursor(0,0);
       dni_LCD.setCursor(0,0);
       dni_LCD.print("CONTADOR: ");
       dni_LCD.setCursor(0,1);
       dni_LCD.print(contar);
}
     
    //al contar el numero maximo 16, sonara el buzzer y aparecera el muñequito
    if(contar>16){
      tone(buzzer,100);
      dni_LCD.clear();
      dni_LCD.setCursor(0,0);
      dni_LCD.write(1);
      dni_LCD.write(1);
      dni_LCD.write(1);
      dni_LCD.write(1);
      dni_LCD.write(1);
      dni_LCD.write(1);
      dni_LCD.write(1);
      dni_LCD.write(1);
      dni_LCD.write(1);
      dni_LCD.write(1);
      dni_LCD.write(1);
      dni_LCD.write(1);
      dni_LCD.write(1);
      dni_LCD.write(1);
      dni_LCD.write(1);
      dni_LCD.write(1);
      delay(1000);
      dni_LCD.setCursor(0,0);
      dni_LCD.write(2);
      dni_LCD.write(2);
      dni_LCD.write(2);
      dni_LCD.write(2);
      dni_LCD.write(2);
      dni_LCD.write(2);
      dni_LCD.write(2);
      dni_LCD.write(2);
      dni_LCD.write(2);
      dni_LCD.write(2);
      dni_LCD.write(2);
      dni_LCD.write(2);
      dni_LCD.write(2);
      dni_LCD.write(2);
      dni_LCD.write(2);
      dni_LCD.write(2);
      delay(1000);

      
    }
    }
