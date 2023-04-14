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

#define push1 3
#define push2 4
#define r 5
#define b 6
#define g 7
#define setpinInput(pin)        pinMode(pin,INPUT)      //Macro para configurar entradas
#define setpinInputPullup(pin)  pinMode(pin, INPUT_PULLUP)  //Macro para configurar entradas con pullup interno
#define setpinOutput(pin)       pinMode(pin, OUTPUT)      //Macro para configurar salidas.
#define hi(pin)                digitalWrite(pin, HIGH)   //Macro para encender un pin
#define lo(pin)                digitalWrite(pin, LOW)    //Macro para apagar un pin

   void setup() {
    setpinInput(push1);
    setpinInput(push2);
    setpinOutput(r);
    setpinOutput(g);
    setpinOutput(b);
 
  
  }
  
  void loop() {
  bool  b1 = digitalRead(push1);
  bool  b2 = digitalRead(push2);

  if (b1==HIGH && b2==LOW){
    delay (100);
     hi(g);
     hi(r);
     lo (b);
     
  
  }

  else if (b1 == HIGH && b2 == LOW){
    delay (100);
     hi(g);
     hi(r);
       lo (b);
  }

   if (b1==LOW && b2==HIGH){
    delay (100);
     hi(g);
     hi(b);
        lo (r);
     
  
  }

  else if (b1 == LOW && b2 == HIGH){
    delay (100);
     hi(g);
     hi(b);
     lo (r);
  }
  
    if (b1==HIGH && b2==HIGH){
    delay (100);
     
     hi(b);
        hi (r);
      lo(g);
     
  
  }

  else if (b1 == HIGH && b2 == HIGH){
    delay (100);
     
     hi(b);
     hi (r);
    hi(g);
  }
  
  
  
  
  if (b1==LOW && b2==LOW){
   delay (100);
   hi(r);
  delay(500);
 lo(r);  
  hi(g);
  delay(500);
  lo(g);
  hi(b);
  delay(500);
  lo(b);

  }
  }
