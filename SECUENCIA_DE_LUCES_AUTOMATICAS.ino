/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Encender un led por medio de un pulsador
   Dev: Eliezer Denilson Gaitán Corado
   Fecha: 13 de abril
*/
// Definir las salidas de los LEDs
#define LED_0_SET()  digitalWrite(2, HIGH)
#define LED_1_SET()  digitalWrite(3, HIGH)
#define LED_2_SET()  digitalWrite(4, HIGH)
#define LED_3_SET()  digitalWrite(5, HIGH)
#define LED_4_SET()  digitalWrite(6, HIGH)
#define LED_5_SET()  digitalWrite(7, HIGH)
#define LED_6_SET()  digitalWrite(8, HIGH)
#define LED_7_SET()  digitalWrite(9, HIGH)
#define LED_8_SET()  digitalWrite(10, HIGH)
#define LED_9_SET()  digitalWrite(11, HIGH)

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
  LED_0_SET();
  delay(WAIT_TIME);
  digitalWrite(2, LOW);
  LED_1_SET();
  delay(WAIT_TIME);
  digitalWrite(3, LOW);
  LED_2_SET();
  delay(WAIT_TIME);
  digitalWrite(4, LOW);
  LED_3_SET();
  delay(WAIT_TIME);
  digitalWrite(5, LOW);
  LED_4_SET();
  delay(WAIT_TIME);
  digitalWrite(6, LOW);
  LED_5_SET();
  delay(WAIT_TIME);
  digitalWrite(7, LOW);
  LED_6_SET();
  delay(WAIT_TIME);
  digitalWrite(8, LOW);
  LED_7_SET();
  delay(WAIT_TIME);
  digitalWrite(9, LOW);
  LED_8_SET();
  delay(WAIT_TIME);
  digitalWrite(10, LOW);
  LED_9_SET();
  delay(WAIT_TIME);
  digitalWrite(11, LOW);

  // Encender los LEDs en orden descendente
  LED_9_SET();
  delay(WAIT_TIME);
  digitalWrite(11, LOW);
  LED_8_SET();
  delay(WAIT_TIME);
  digitalWrite(10, LOW);
  LED_7_SET();
  delay(WAIT_TIME);
  digitalWrite(9, LOW);
  LED_6_SET();
  delay(WAIT_TIME);
  digitalWrite(8, LOW);
  LED_5_SET();
  delay(WAIT_TIME);
  digitalWrite(7, LOW);
  LED_4_SET();
  delay(WAIT_TIME);
  digitalWrite(6, LOW);
  LED_3_SET();
  delay(WAIT_TIME);
  digitalWrite(5, LOW);
  LED_2_SET();
  delay(WAIT_TIME);
  digitalWrite(4, LOW);
  LED_1_SET();
  delay(WAIT_TIME);
  digitalWrite(3, LOW);
  LED_0_SET();
  delay(WAIT_TIME);
  digitalWrite(2, LOW);
}
