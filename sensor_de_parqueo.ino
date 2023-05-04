/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM  
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: SENSOR DE PARQUEO     
   De: Eliezer Denilson Gaitán Corado
*/

//librerias a utilizar
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//definir pines
#define trig 13   
#define echo 12

byte relleno[] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};
LiquidCrystal_I2C lcd_dni(0x27,16,2);
void setup() {
  lcd_dni.init();
  lcd_dni.backlight();
  pinMode(trig, OUTPUT);
  pinMode(echo,INPUT);
  lcd_dni.createChar(1,relleno); //se le llamara "relleno" a los cuadros que se utilizaran. 
}
void loop() {
  int distancin=dis();
    if(distancin >=50){  //distancia de 50cm.
      lcd_dni.clear();
      lcd_dni.setCursor(7,0);
      lcd_dni.print("50");  
      lcd_dni.setCursor(6,0); 
      lcd_dni.write(1);
      lcd_dni.setCursor(5,0); 
      lcd_dni.write(1);
      lcd_dni.setCursor(4,0); 
      lcd_dni.write(1);
      lcd_dni.setCursor(9,0); 
      lcd_dni.write(1);
      lcd_dni.setCursor(10,0); 
      lcd_dni.write(1);
      lcd_dni.setCursor(11,0); 
      lcd_dni.write(1);
      lcd_dni.setCursor(6,1); 
      lcd_dni.print("Libre");   //palabra a mostrar a los 50cm.
    }
    if(distancin >=30 && distancin <=45){   //distancia de 30cm.
      lcd_dni.clear();
      lcd_dni.setCursor(7,0);
      lcd_dni.print("30");
      lcd_dni.setCursor(6,0); 
      lcd_dni.write(1);
      lcd_dni.setCursor(5,0); 
      lcd_dni.write(1);
      lcd_dni.setCursor(4,0); 
      lcd_dni.write(1);
      lcd_dni.setCursor(3,0); 
      lcd_dni.write(1);
      lcd_dni.setCursor(2,0); 
      lcd_dni.write(1);
      lcd_dni.setCursor(9,0); 
      lcd_dni.write(1);
      lcd_dni.setCursor(10,0); 
      lcd_dni.write(1);
      lcd_dni.setCursor(11,0); 
      lcd_dni.write(1);
      lcd_dni.setCursor(12,0); 
      lcd_dni.write(1);
      lcd_dni.setCursor(13,0); 
      lcd_dni.write(1);
      lcd_dni.setCursor(5,1); 
      lcd_dni.print("Cuidado");        //palabra a mostrar a los 30cm.
    }
     if(distancin >=8 && distancin <=15){       //distancia de 10cm.
      lcd_dni.clear();
      lcd_dni.setCursor(7,0);
      lcd_dni.print("10");
      lcd_dni.setCursor(6,0); 
      lcd_dni.write(1);
      lcd_dni.setCursor(5,0); 
      lcd_dni.write(1);
      lcd_dni.setCursor(4,0); 
      lcd_dni.write(1);
      lcd_dni.setCursor(3,0); 
      lcd_dni.write(1);
      lcd_dni.setCursor(2,0); 
      lcd_dni.write(1);
      lcd_dni.setCursor(1,0); 
      lcd_dni.write(1);
      lcd_dni.setCursor(0,0); 
      lcd_dni.write(1);
      lcd_dni.setCursor(9,0); 
      lcd_dni.write(1);
      lcd_dni.setCursor(10,0); 
      lcd_dni.write(1);
      lcd_dni.setCursor(11,0); 
      lcd_dni.write(1);
      lcd_dni.setCursor(12,0); 
      lcd_dni.write(1);
      lcd_dni.setCursor(13,0); 
      lcd_dni.write(1);
      lcd_dni.setCursor(14,0); 
      lcd_dni.write(1);
      lcd_dni.setCursor(15,0); 
      lcd_dni.write(1);
      lcd_dni.setCursor(16,0); 
      lcd_dni.write(1);
      lcd_dni.setCursor(6,1); 
      lcd_dni.print("Alto");      //palabra a mostrar a los 10cm.
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
