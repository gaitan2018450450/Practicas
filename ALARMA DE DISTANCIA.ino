/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM  
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: ALARMA DE DISTANCIA     
   De: Eliezer Denilson Gaitán Corado
*/
//libreria a utilizar

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define led1 2
#define led23 3
#define led4 4
#define led5 6
#define led67 7
#define led8 8
#define led9 9
#define led10 10
#define buzzer 11
#define trig 13   
#define echo    12

//Crear el objeto lcd 16 x 2 
LiquidCrystal_I2C lcd_dni(0x27,16,2);  

void setup() {
  // Inicializar la LCD
  lcd_dni.init();
  //Encendemos la luz de fondo.
  lcd_dni.backlight();
  //Colocamos como entradas y salidas 
  pinMode(led1,OUTPUT);
  pinMode(led23,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(led5,OUTPUT);
  pinMode(led67,OUTPUT);
  pinMode(led8,OUTPUT);
  pinMode(led9,OUTPUT);
  pinMode(led10,OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo,INPUT);
  pinMode(buzzer, OUTPUT); 

} 
void loop() {
    int distancin=dis();
    if(distancin >=45){
      lcd_dni.clear();
      lcd_dni.print("Fuera de alcance");
      digitalWrite(led1,LOW);
      digitalWrite(led23,LOW);
      digitalWrite(led4,LOW);
      digitalWrite(led5,LOW);
      digitalWrite(led67,LOW);
      digitalWrite(led8,LOW);
      digitalWrite(led9,LOW);
      digitalWrite(led10,LOW);      
    }
    if(distancin >=30 && distancin <=40){
      lcd_dni.clear();
      lcd_dni.print("Persona");
      lcd_dni.setCursor(0,1);
      lcd_dni.println("acercandose     ");
      lcd_dni.setCursor(1,0);
      digitalWrite(led1,HIGH);
      digitalWrite(led23,HIGH);
      
    }
     if(distancin >=15 && distancin <=25){
      lcd_dni.clear();
      lcd_dni.print("Cuidado,");
      lcd_dni.setCursor(0,1);
      lcd_dni.println("Espacio Privado! ");
      lcd_dni.setCursor(1,0);
      digitalWrite(led1,HIGH);
      digitalWrite(led23,HIGH);
      digitalWrite(led4,HIGH);
      digitalWrite(led5,HIGH);
      digitalWrite(led67,HIGH);
      delay(500);
      tone(buzzer, 100);
      delay(2000); 
      noTone(buzzer);
    }
    if(distancin >=5 && distancin <=10){
      lcd_dni.clear();
      lcd_dni.print("Invadiendo");
      lcd_dni.setCursor(0,1);
      lcd_dni.print("Espacio Privado");
      lcd_dni.setCursor(1,0);
      digitalWrite(led1,HIGH);
      digitalWrite(led23,HIGH);
      digitalWrite(led4,HIGH);
      digitalWrite(led5,HIGH);
      digitalWrite(led67,HIGH);
      digitalWrite(led8,HIGH);
      digitalWrite(led9,HIGH);
      digitalWrite(led10,HIGH);
      tone(buzzer, 500);
      delay(2000);
      noTone(buzzer); 
    }
}

int dis(){
   long sensor, distancia; 
    delay(500);
    digitalWrite(trig, HIGH);
    delayMicroseconds(2);
    digitalWrite (trig, LOW);
    delayMicroseconds(5);
    sensor = pulseIn(echo, HIGH);
    distancia = sensor/59;
    return distancia;
}
