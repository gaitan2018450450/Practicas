/*
Fundación Kinal
Centro Educativo Técnico Labral Kinal 
Electrónica
Grado: Quinto
Sección: A
Curso: Taller de Electrónica Digital y Reparación de Computadoras I
Nombre: Eliezer Denilson Gaitan Corado
Carné: 2018450 
*/

#define LEDv 10
#define LEDr 11
#define SENSOR 4
#define RELE 6
#define PMI(pin) pinMode(pin,INPUT)
#define PMO(pin) pinMode(pin,OUTPUT)
#define DW1(pin) digitalWrite(pin,HIGH)
#define DW0(pin) digitalWrite(pin,LOW)
void setup() {
  
PMI(SENSOR);
PMO(LEDv);
PMO(LEDr);
PMO(RELE);
}

void loop() {

int TRAS = digitalRead(TRAS);
if (TRAS == LOW) {
DW0(RELE);
DW0(LEDr);
DW1(LEDv);
}
if (TRAS* == HIGH) {
  DW1(RELE);
  DW0(LEDv);
  DW1(LEDr);
}

}
