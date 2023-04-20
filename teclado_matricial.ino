 #include <Keypad.h>

// Definir el número de filas y columnas del teclado matricial
const byte ROWS = 4;
const byte COLS = 4;

// Definir las teclas en el teclado matricial
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

// Definir los pines conectados al display de 7 segmentos
const int a = 2;
const int b = 3;
const int c = 4;
const int d = 5;
const int e = 6;
const int f = 7;
const int g = 8;
const int DP= 13;
byte rowPins[ROWS] = {9, 10, 11, 12}; // pines de las filas del teclado matricial
byte colPins[COLS] = {A0, A1, A2, A3}; // pines de las columnas del teclado matricial
// Crear objeto Keypad
Keypad keypad = Keypad(makeKeymap(keys),rowPins,colPins, ROWS, COLS);

void setup() {
  // Configurar los pines del display como salida
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(DP, OUTPUT);
  
  // Configurar el puerto serie para imprimir información
  Serial.begin(9600);
}

void loop() {
  // Leer la tecla presionada
  char key = keypad.getKey();
  
  
  // Mostrar la tecla en el display
  /*if (key) {
    displayKey(key);
  } 
    */
  /*La palabra clave "static" indica que la variable
  es persistente y su valor no se pierde entre llamadas
  a la función. En este caso, la variable "lastKeyPressTime" 
  se utiliza para almacenar el momento en que se presionó 
  la última tecla en milisegundos (usando la función millis()
  de Arduino).*/
   static unsigned long lastKeyPressTime = 0;//declara una variable estática de tipo "unsigned long" llamada "lastKeyPressTime" e inicializa su valor a 0.
  if (key != NO_KEY) { //compara la tecla presionada
    lastKeyPressTime = millis();
    displayKey(key);//muestra la tecla en el display, llamando a la funcion
  } else if (millis() - lastKeyPressTime >= 2000) {//sino se presiona ninguna tecla, regresa a numero 0
    displayKey('0');
  }
   
}



void displayKey(char key) {
  // Apagar todos los segmentos
  digitalWrite(a,LOW);
      digitalWrite(b, LOW);
      digitalWrite(c, LOW);
      digitalWrite(d, LOW);
      digitalWrite(e, LOW);
      digitalWrite(f, LOW);
      digitalWrite(g, LOW);
     digitalWrite(DP, LOW);
  
  
  // Mostrar la tecla en el display
  
  switch (key) {
    case '0':
    digitalWrite(g, LOW);    
      digitalWrite(DP, LOW);
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, HIGH);
      digitalWrite(e, HIGH);
      digitalWrite(f, HIGH);
            
      break;
    case '1':
       digitalWrite(a, LOW);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, LOW);
      digitalWrite(e, LOW);
      digitalWrite(f, LOW);
      digitalWrite(g, LOW);
     digitalWrite(DP, LOW);
      break;
    case '2':
       digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(c, LOW);
      digitalWrite(d, HIGH);
      digitalWrite(e, HIGH);
      digitalWrite(f, LOW);
      digitalWrite(g, HIGH);
     digitalWrite(DP, LOW);
      break;
    case '3':
       digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, HIGH);
      digitalWrite(e, LOW);
      digitalWrite(f, LOW);
      digitalWrite(g, HIGH);
     digitalWrite(DP, LOW);
      break;
    case '4':
       digitalWrite(a, LOW);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, LOW);
      digitalWrite(e, LOW);
      digitalWrite(f, HIGH);
      digitalWrite(g, HIGH);
     digitalWrite(DP, LOW);
      break;
    case '5':
       digitalWrite(a, HIGH);
      digitalWrite(b, LOW);
      digitalWrite(c, HIGH);
      digitalWrite(d, HIGH);
      digitalWrite(e, LOW);
      digitalWrite(f, HIGH);
      digitalWrite(g, HIGH);
     digitalWrite(DP, LOW);
      break;
    case '6':
       digitalWrite(a, HIGH);
      digitalWrite(b, LOW);
      digitalWrite(c, HIGH);
      digitalWrite(d, HIGH);
      digitalWrite(e, HIGH);
      digitalWrite(f, HIGH);
      digitalWrite(g, HIGH);
     digitalWrite(DP, LOW);
      break;
    case '7':
       digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, LOW);
      digitalWrite(e, LOW);
      digitalWrite(f, LOW);
      digitalWrite(g, LOW);
     digitalWrite(DP, LOW);
      break;
    case '8':
       digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, HIGH);
      digitalWrite(e, HIGH);
      digitalWrite(f, HIGH);
      digitalWrite(g, HIGH);
     digitalWrite(DP, LOW);
      break;
    case '9':
       digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, HIGH);
      digitalWrite(e, LOW);
      digitalWrite(f, HIGH);
      digitalWrite(g, HIGH);
     digitalWrite(DP, LOW);
      break;
    
    case 'A':
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, LOW);
      digitalWrite(e, HIGH);
      digitalWrite(f, HIGH);
      digitalWrite(g, HIGH);
     digitalWrite(DP, LOW);
      break;
    case 'B':
       digitalWrite(a, LOW);
      digitalWrite(b, LOW);
      digitalWrite(c, HIGH);
      digitalWrite(d, HIGH);
      digitalWrite(e, HIGH);
      digitalWrite(f, HIGH);
      digitalWrite(g, HIGH);
     digitalWrite(DP, LOW);
      break;
    case 'C':
      digitalWrite(a, HIGH);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
      digitalWrite(f, HIGH);
      digitalWrite(d, HIGH);
    digitalWrite(g, LOW);
      digitalWrite(e, HIGH);
     digitalWrite(DP, LOW);
      break;
    case 'D':
      digitalWrite(a, LOW);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, HIGH);
      digitalWrite(e, HIGH);
      digitalWrite(f, LOW);
    digitalWrite(g, HIGH);
    
      digitalWrite(DP, LOW);
      
      
      break;
    case '*':
    digitalWrite(a, HIGH);
      digitalWrite(b, LOW);
      digitalWrite(c, LOW);
    digitalWrite(d, LOW);
      digitalWrite(e, HIGH);
      digitalWrite(f, HIGH);
      digitalWrite(g, HIGH);
      digitalWrite(DP, LOW);
     
      break;
    case '#':
      digitalWrite(a, HIGH);
      digitalWrite(b, LOW);
      digitalWrite(c, LOW);
    digitalWrite(d, HIGH);
      digitalWrite(e, HIGH);
      digitalWrite(f, HIGH);
      digitalWrite(g, HIGH);
     digitalWrite(DP, HIGH);
      break;
    default:
      break;
  }
  
  // Imprimir la tecla en el puerto serie
  Serial.println(key);
  }
