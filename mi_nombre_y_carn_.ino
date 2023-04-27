/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM  
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: LCD   
   Dev: Eliezer Denilson Gaitán Corado
*/
#include <LiquidCrystal.h>
int rs= 12;
int E= 11;
int D4= 6;
int D5= 4;
int D6= 3;
int D7= 2;

LiquidCrystal dni_LCD(rs,E,D4,D5,D6,D7);

void setup() {
dni_LCD.begin(16,2);
}
void loop() {
dni_LCD.setCursor(1,0);
dni_LCD.print("Eliezer Corado ");
dni_LCD.setCursor(0,1);
dni_LCD.print("2018450");
}
