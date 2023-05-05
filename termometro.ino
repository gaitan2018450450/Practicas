/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM  
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: termometro     
   De: Eliezer Denilson Gaitán Corado
*/

//Librerias a utilizar
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <OneWire.h>                
#include <DallasTemperature.h>

//definir pines
#define r 2
#define g 3
#define a 8

//Constructores
OneWire ourWire(6);                
DallasTemperature sensor(&ourWire); 
LiquidCrystal_I2C lcd_dni(0x27,16,2);

void setup()
{
  pinMode(r,OUTPUT);
  pinMode(g,OUTPUT);
  pinMode(a,OUTPUT);

  
delay(1000);
lcd_dni.init();
lcd_dni.backlight();   //Inicio la comunicacion serial
sensor.begin();   //Se inicia el sensor
}
 
void loop() {
sensor.requestTemperatures();   //Lee la temperatura
float temperatura1 = sensor.getTempCByIndex(0); //Nos comunica la temperatura en grados ºC
float temperatura2 = sensor.getTempFByIndex(0); //Nos comunica la temperatura en grados ºF

lcd_dni.setCursor(0,0);
lcd_dni.print("Temperatura= ");
lcd_dni.setCursor(0,1);
lcd_dni.print(temperatura1);
lcd_dni.println("C"); 
lcd_dni.setCursor(6,1); 
lcd_dni.print(" ");
lcd_dni.setCursor(7,1); 
lcd_dni.print(" ");
lcd_dni.setCursor(8,1); 
lcd_dni.print(" ");
lcd_dni.setCursor(9,1); 
lcd_dni.print(temperatura2);
lcd_dni.println("F");
lcd_dni.setCursor(15,1); 
lcd_dni.print("  ");
delay(100);

if(temperatura1 >=30){
  digitalWrite(r,HIGH);
  digitalWrite(g,LOW);
  digitalWrite(a,LOW);
}
if(temperatura1 <=15){
  digitalWrite(r,LOW);
  digitalWrite(g,HIGH);
  digitalWrite(a,LOW);
}
if(temperatura1 >15 && temperatura1 <30){
 digitalWrite(r,LOW);
  digitalWrite(g,LOW);
  digitalWrite(a,HIGH);
  
}
}
