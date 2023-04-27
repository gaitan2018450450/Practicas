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
//se definen los pines
#define trig 10
#define echo 11
#define a  2
#define b  3
#define c  4
#define d  6
#define e  7
#define f  8
#define g  9
#define PD 13
#define rele 12

int contador = 0;  
void setup() {
 
  pinMode(trig, OUTPUT);//definimos la variable trig como salida
  pinMode(echo,INPUT);//definimos la variable echo como entrada
  pinMode(rele,OUTPUT);//definimos la variable rele como salida 
  digitalWrite(rele, LOW);
  pinMode(a,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(c,OUTPUT);
  pinMode(d,OUTPUT);
  pinMode(e,OUTPUT);
  pinMode(f,OUTPUT);
  pinMode(g,OUTPUT);
  pinMode(PD,OUTPUT);

}
void loop() {

long sensor, distancia; //variables para saber ditancia
delay(500);
  digitalWrite(trig,LOW);
  delayMicroseconds(5);
  digitalWrite(trig,HIGH);
  delayMicroseconds(15);
  digitalWrite(trig,LOW);  
  sensor = pulseIn(echo,HIGH);
  distancia = sensor/59;
 if(distancia > 6 && distancia < 10){
     contador++;
     tomar_numero(contador);
 }
 if(contador >= 10){
  digitalWrite(rele,HIGH);
 }
}
//Se nombran loa numeros para el contador
  void tomar_numero(int contador){
    switch(contador){
      case 0:
       numero_0();
       break;
      case 1:
       numero_1();
       break;
      case 2:
       numero_2();
       break;
      case 3:
       numero_3();
       break;
      case 4:
       numero_4();
       break;
      case 5:
       numero_5();
       break;
      case 6:
       numero_6();
       break;
       case 7:
       numero_7();
       break;
       case 8:
       numero_8();
       break;
       case 9:
       numero_9();
       break;       
    }
    }
    //Se mostraran los numeros en el display de 7 segmentos
//numero 0
void numero_0(){
     digitalWrite(a,HIGH);
     digitalWrite(b,HIGH);
     digitalWrite(c,HIGH);
     digitalWrite(d,HIGH);
     digitalWrite(e,HIGH);
     digitalWrite(f,HIGH);
     digitalWrite(g,LOW);
     digitalWrite(PD,LOW);
     
   }
//numero 1
void numero_1(){
     digitalWrite(a,LOW);
     digitalWrite(b,HIGH);
     digitalWrite(c,HIGH);
     digitalWrite(d,LOW);
     digitalWrite(e,LOW);
     digitalWrite(f,LOW);
     digitalWrite(g,LOW);
     digitalWrite(PD,LOW);
   }
//numero 2
void numero_2(){
     digitalWrite(a,HIGH);
     digitalWrite(b,HIGH);
     digitalWrite(c,LOW);
     digitalWrite(d,HIGH);
     digitalWrite(e,HIGH);
     digitalWrite(f,LOW);
     digitalWrite(g,HIGH);
     digitalWrite(PD,LOW);
   }
//numero 3
   void numero_3(){
     digitalWrite(a, HIGH);
     digitalWrite(b, HIGH);
     digitalWrite(c, HIGH);
     digitalWrite(d, HIGH);
     digitalWrite(e, LOW);
     digitalWrite(f, LOW);
     digitalWrite(g, HIGH);
     digitalWrite(PD,LOW);
   }
//numero 4
    void numero_4(){
     digitalWrite(a,LOW);
     digitalWrite(b,HIGH);
     digitalWrite(c,HIGH);
     digitalWrite(d,LOW);
     digitalWrite(e,LOW);
     digitalWrite(f,HIGH);
     digitalWrite(g,HIGH);
     digitalWrite(PD,LOW);
}
//numero 5
 void numero_5(){
     digitalWrite(a,HIGH);
     digitalWrite(b,LOW);
     digitalWrite(c,HIGH);
     digitalWrite(d,HIGH);
     digitalWrite(e,LOW);
     digitalWrite(f,HIGH);
     digitalWrite(g,HIGH);
     digitalWrite(PD,LOW);
   }
//numero 6
   void numero_6(){
     digitalWrite(a,HIGH);
     digitalWrite(b,LOW);
     digitalWrite(c,HIGH);
     digitalWrite(d,HIGH);
     digitalWrite(e,HIGH);
     digitalWrite(f,HIGH);
     digitalWrite(g,HIGH);
     digitalWrite(PD,LOW);
   }
//numero 7
   void numero_7(){
     digitalWrite(a,HIGH);
     digitalWrite(b,HIGH);
     digitalWrite(c,HIGH);
     digitalWrite(d,LOW);
     digitalWrite(e,LOW);
     digitalWrite(f,LOW);
     digitalWrite(g,LOW);
     digitalWrite(PD,LOW);
   }
//numero 8
   void numero_8(){
     digitalWrite(a,HIGH);
     digitalWrite(b,HIGH);
     digitalWrite(c,HIGH);
     digitalWrite(d,HIGH);
     digitalWrite(e,HIGH);
     digitalWrite(f,HIGH);
     digitalWrite(g,HIGH);
     digitalWrite(PD,LOW);
   }
//numero 9
   void numero_9(){
     digitalWrite(a,HIGH);
     digitalWrite(b,HIGH);
     digitalWrite(c,HIGH);
     digitalWrite(d,HIGH);
     digitalWrite(e,LOW);
     digitalWrite(f,HIGH);
     digitalWrite(g,HIGH);
     digitalWrite(PD,LOW);
    }
