//definimos las variables 
int trig = 3;
int echo = 7;
long sensor;
long distancia;
int buzzer = 8; 


//definimos las notas de la canción
int c=261;
int d=294;
int e=329;
int f=349;
int g=391;
int gS=415;
int a=440;
int aS=455;
int b=466;
int cH=523;
int cSH=554;
int dH=587;
int dSH=622;
int eH=659;
int fH=698;
int fSH=740;
int gH=783;
int gSH=830;
int aH=880;

void setup()    
{    
 pinMode(trig, OUTPUT);
 pinMode(echo, INPUT);
 
  pinMode(buzzer, OUTPUT); // definimos la variable buzzer como una salida.
 
}    
     
void loop()  
{  
  digitalWrite(3, HIGH);
delayMicroseconds(10);
digitalWrite (3, LOW);
  sensor = pulseIn(7, HIGH);
 distancia = sensor/59;

 //haremos que nos de una nota exacta de distancia a distancia
if(distancia == 4 && distancia <6 ){
tone(buzzer, a, 500);
 delay(500+50);
}
if(distancia == 7 && distancia <9){
tone(buzzer, f, 350);
 delay(350+50);
}
if(distancia == 10 && distancia <12){
tone(buzzer, cH, 150);
 delay(150+50);
}
if(distancia == 13 && distancia <15){
tone(buzzer, eH, 500);
 delay(500+50);
}
if(distancia == 16 && distancia <18){
tone(buzzer,fH, 350 );
 delay(350+50);
}
if(distancia == 19&& distancia <21){
tone(buzzer,gS, 500 );
 delay(500+50);
}
if(distancia == 22 && distancia <24){
tone(buzzer,aH, 500);
 delay(500+50);
}
if(distancia == 25 && distancia <27){
tone(buzzer,gSH, 250 );
delay(250+50);
}
if(distancia == 28 && distancia <30){
tone(buzzer,gH, 250);
delay(250+50);
}
if(distancia == 31 && distancia <33){
tone(buzzer,fSH, 125 );
delay(125+50);
}
if(distancia == 34 && distancia <36){
tone(buzzer,aS, 250);
delay(250+50);
}
if(distancia == 37 && distancia <39){
tone(buzzer,dSH, 500);
delay(500+50);
}
if(distancia == 40 && distancia <42){
tone(buzzer,dH, 250);
delay(250+50);
}
if(distancia == 43 && distancia <45){
tone(buzzer,cSH, 250);
delay(250+50);
}
if(distancia == 46 && distancia <48){
tone(buzzer,b, 125);
delay(125+50);
}
if(distancia == 49 && distancia <51){
tone(buzzer,c, 125);
delay(125+50);
}
}
