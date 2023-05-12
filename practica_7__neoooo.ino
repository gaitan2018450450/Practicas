

/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Practica #7 
   De: Eliezer Denilson Gaitán Corado
*/

// Librerias a utilizar
#include <LiquidCrystal_I2C.h>
                                       LiquidCrystal_I2C lcd (0x27, 16, 2);
#include <Servo.h>
                            Servo servoo;

#include <OneWire.h>
#include <DallasTemperature.h>

OneWire oneWireObjeto(13);
DallasTemperature Temp(&oneWireObjeto);

#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel NAH(5, 6, NEO_RGB + NEO_KHZ800);

// DEfinición de pines 
#define rele1 2
#define rele2 3
#define buzer 4
#define neop 6
#define r_presen 8
#define leda 9
#define ledv 10
#define pServo 7
#define ledr 11
#define bot1 A0
#define bot2 12
#define bot3 A1

bool estado_b1 = true;
bool estado_b2 = true;
bool estado_p = false;
byte estado_q = 0;

byte termometroo[] = {
 B00000,
  B00100,
  B00100,
  B00100,
  B01110,
  B01110,
  B00100,
  B00100
};

byte termometro2[] = {
 B00000,
  B00100,
  B00100,
  B00100,
  B01110,
  B01110,
  B00100,
  B00100
};

byte focoo[] = {
 B00000,
  B01110,
  B11111,
  B11111,
  B11111,
  B01110,
  B01110,
  B00100
};
byte focoo2[] = {
 B00000,
  B00100,
  B01110,
  B01110,
  B01110,
  B11111,
  B01110,
  B00000
};

byte persona00[] = {
    B01110,
  B01110,
  B00100,
  B11111,
  B00100,
  B00100,
  B01010,
  B01010

};

byte puertaa[] = {
 B00000,
  B11111,
  B11111,
  B11111,
  B11101,
  B11101,
  B11111,
  B11111
};

byte puertaa2[] = {
  B00000,
  B11111,
  B11111,
  B11111,
  B11101,
  B11101,
  B11111,
  B11111
};

void setup() {
  Serial.begin(9600);
    pinMode(pServo, OUTPUT);
  servoo.attach(pServo); // Declaramos pin del servomotor
  lcd.init();
  lcd.backlight(); //Prendemos LUZ de fondo de LCD
  lcd.clear();
  pinMode(rele1, OUTPUT); //Colocamos las variables en salida (OUTPUT)
  pinMode(rele2, OUTPUT); //Colocamos las variables en salida (OUTPUT)
  pinMode(buzer, OUTPUT); //Colocamos las variables en salida (OUTPUT)
  pinMode(ledr, OUTPUT); //Colocamos las variables en salida (OUTPUT)
  pinMode(ledv, OUTPUT); //Colocamos las variables en salida (OUTPUT)
  pinMode(leda, OUTPUT); //Colocamos las variables en salida (OUTPUT)
  pinMode(bot1, INPUT); //Colocamos las variables en salida (OUTPUT)
  pinMode(bot2, INPUT); //Colocamos las variables en salida (OUTPUT)
  pinMode(bot3, INPUT); //Colocamos las variables en salida (OUTPUT)
  pinMode(r_presen, INPUT); //Colocamos las variables en salida (OUTPUT)

  digitalWrite(rele1, estado_b1);
  digitalWrite(rele2, estado_b2);
  servoo.write(estado_q);
  Temp.begin();
  NAH.begin();
  NAH.clear();
  NAH.show();
  lcd.createChar(0, termometroo);
  lcd.createChar(1, termometro2);
  lcd.createChar(2, focoo);
  lcd.createChar(3, focoo2);
  lcd.createChar(4, persona00);
  lcd.createChar(5, puertaa);
  lcd.createChar(6, puertaa2);
}

void loop() {
  Temp.requestTemperatures();
  int Temperatura = Temp.getTempCByIndex(0); // guardamos da temperatura en una variable
  
 
  // Muestra en pantalla las variables
  lcd.setCursor(9, 1);
  lcd.write(0);
  lcd.print(":   ");
  lcd.print(Temperatura);
  
  lcd.setCursor(0, 1);
  lcd.write(4);
  lcd.print(":   ");
  SINO();
  lcd.setCursor(9, 0);
  foco(estado_b1);
  lcd.print("#1:");
  OnOff(estado_b1);
  lcd.setCursor(0, 0);
  foco(estado_b2);
  lcd.print("#2:");
  OnOff(estado_b2);
  if (digitalRead(bot1) == HIGH) {
    while (digitalRead(bot1) == HIGH);
    estado_b1 = !estado_b1;
    digitalWrite(rele1, estado_b1);
  }
  else if (digitalRead(bot2) == HIGH) {
    while (digitalRead(bot2) == HIGH);
    estado_b2 = !estado_b2;
    digitalWrite(rele2, estado_b2);
  }
  if (digitalRead(bot3) == HIGH && estado_p == true) {
    estado_q = 90;
    Serial.println("Abierto");
    lcd.clear();
    lcd.setCursor(4, 0);
    lcd.print("Puerta");
    lcd.setCursor(5, 1);
    lcd.write(6);
    lcd.print("abierta");
    delay(1500);
    lcd.clear();
    servoo.write(90);
delay(300);
       estado_p = false;
  }
  else if (digitalRead(bot3) == LOW && estado_p == LOW) {
    estado_q = 0;
    Serial.println("Cerrado");
    lcd.clear();
    lcd.setCursor(4, 0);
    lcd.print("Puerta");
    lcd.setCursor(5, 1);
    lcd.write(5);
    lcd.print("cerrada");
    delay(1500);
    lcd.clear();
    servoo.write(0);
    delay(300);
       estado_p = true;
  }
  servoo.write(estado_q);
  if (Temperatura >= 15 && Temperatura < 26) {
    ledrGB(112, 0, 255);
  }
  else if (Temperatura >= 27 && Temperatura < 20) {
    ledrGB(20, 255, 0);
  }
  else if (Temperatura >= 31 && Temperatura < 45) {
    ledrGB(255, 50, 0);
  }
}

void OnOff(bool estadolocal) { 
  if (estadolocal == LOW) {
    lcd.print("ON ");
    digitalWrite(rele1, HIGH);
  }
  else {
    lcd.print("OFF");
        digitalWrite(rele1, LOW);

  }
}

void SINO() { 
  if (digitalRead(r_presen) == HIGH) {
    lcd.print("OPEN");
    tone(buzer, 100);
    for (int i = 0; i < 6; i++) {
      NAH.setPixelColor(i, 0, 255, 0);// 
      NAH.show();
      delay (1000);
    }
    for (int i = 0; i < 6; i++) {
      NAH.setPixelColor(i, 100, 55, 100);
      NAH.show();
      delay (1000);
    }
  }
  else {
    lcd.print("No  ");
    noTone(buzer);
    for (int i = 0; i < 7; i++) {
      NAH.setPixelColor(i, 0, 0, 0);
      NAH.show();
    }
  }
}

void ledrGB(byte R, byte V, byte A) { 
  analogWrite(ledr, R);
  analogWrite(ledv, V);
  analogWrite(leda, A);
}

void foco(bool estadob) {
  if (estadob == HIGH) {
    lcd.write(2);
  }
  else {
    lcd.write(3);
  }
}
