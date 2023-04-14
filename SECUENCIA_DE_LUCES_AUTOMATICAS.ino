/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: SECUENCIA DE LUCES AUTOMATICAS. 
   Dev: Eliezer Denilson Gaitán Corado
   Fecha: 14 de abril
*/
// Definir las salidas de los LEDs
#define LED_0()  digitalWrite(2, HIGH)
#define LED_1()  digitalWrite(3, HIGH)
#define LED_2()  digitalWrite(4, HIGH)
#define LED_3()  digitalWrite(5, HIGH)
#define LED_4()  digitalWrite(6, HIGH)
#define LED_5()  digitalWrite(7, HIGH)
#define LED_6()  digitalWrite(8, HIGH)
#define LED_7()  digitalWrite(9, HIGH)
#define LED_8()  digitalWrite(10, HIGH)
#define LED_9()  digitalWrite(11, HIGH)

// Definir el tiempo de espera entre encendidos
#define WAIT_TIME 500 //tiempo de espera

void setup() {
  // Configurar los pines de los LEDs como salida
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() {
  // Encender los LEDs en orden ascendente
  LED_0();
  delay(WAIT_TIME);
  digitalWrite(2, LOW);
  LED_1();
  delay(WAIT_TIME);
  digitalWrite(3, LOW);
  LED_2();
  delay(WAIT_TIME);
  digitalWrite(4, LOW);
  LED_3();
  delay(WAIT_TIME);
  digitalWrite(5, LOW);
  LED_4();
  delay(WAIT_TIME);
  digitalWrite(6, LOW);
  LED_5();
  delay(WAIT_TIME);
  digitalWrite(7, LOW);
  LED_6();
  delay(WAIT_TIME);
  digitalWrite(8, LOW);
  LED_7();
  delay(WAIT_TIME);
  digitalWrite(9, LOW);
  LED_8();
  delay(WAIT_TIME);
  digitalWrite(10, LOW);
  LED_9();
  delay(WAIT_TIME);
  digitalWrite(11, LOW);

  // Encender los LEDs en orden descendente
  LED_9();
  delay(WAIT_TIME);
  digitalWrite(11, LOW);
  LED_8();
  delay(WAIT_TIME);
  digitalWrite(10, LOW);
  LED_7();
  delay(WAIT_TIME);
  digitalWrite(9, LOW);
  LED_6();
  delay(WAIT_TIME);
  digitalWrite(8, LOW);
  LED_5();
  delay(WAIT_TIME);
  digitalWrite(7, LOW);
  LED_4();
  delay(WAIT_TIME);
  digitalWrite(6, LOW);
  LED_3();
  delay(WAIT_TIME);
  digitalWrite(5, LOW);
  LED_2();
  delay(WAIT_TIME);
  digitalWrite(4, LOW);
  LED_1();
  delay(WAIT_TIME);
  digitalWrite(3, LOW);
  LED_0();
  delay(WAIT_TIME);
  digitalWrite(2, LOW);
}
