// Definición de los pines de los botones de avance y retroceso
#define PIN_AVANCE 2
#define PIN_RETROCESO 3

int indiceSeleccionado = 0;// Definición del índice de la golosina seleccionada inicialmente sera usado para la funcion void

void setup() {
  Serial.begin(9600);// Inicialización del monitor serial
  Serial.println("Eliga su producto");
  pinMode(PIN_AVANCE, INPUT_PULLUP);// Configuración de los pines de los botones
  pinMode(PIN_RETROCESO, INPUT_PULLUP);

  
}
// Definición de la estructura para cada golosina
struct Golosina {
  char nombre[20]; // nombre de la golosina
  float precio; // precio de la golosina
  int cantidad; // cantidad de la golosina
  char reserva[20]; // reserva de la golosina
  float ppl;//precio del lote 

};
// Definición de las golosinas
Golosina golosinas[4] = {
  {"Chicle", 0.5,10,"No hay en bodega",0}, // nombre, precio, cantidad, reserva y precio por lote
  {"Chocolate",10,5,"hay 3 en bodega",80},
  {"CHIPS", 5,15, "No hay en bodega",75},
  {"Gomitas",2,3,"hay 40 en bodega",86}
};

void loop() {
  if (digitalRead(PIN_AVANCE) == LOW) { // Verificación del botón de avance
     indiceSeleccionado++;// Incremento del índice de la golosina seleccionada
    if (indiceSeleccionado >= 4) { // Si el índice es mayor al número de golosinas, lo reiniciamos
      indiceSeleccionado = 0;
    }
   
    mostrarGolosinaSeleccionada(); // Muestra la golosina seleccionada en el monitor serial
    while (digitalRead(PIN_AVANCE) == LOW) { // Espera a que se libere el botón de avance
      } // Espera a que se libere el botón de avance
  }

  // Verificación del botón de retroceso
  if (digitalRead(PIN_RETROCESO) == LOW) {
    // Decremento del índice de la golosina seleccionada
    indiceSeleccionado--;
    // Si el índice es menor a cero, lo reiniciamos
    if (indiceSeleccionado < 0) {
      indiceSeleccionado = 3;
    }
        // Muestra la golosina seleccionada en el monitor serial
    mostrarGolosinaSeleccionada();
    // Espera a que se libere el botón de retroceso
    while (digitalRead(PIN_RETROCESO) == LOW) {}
  }
}
// Función que muestra la golosina seleccionada en el monitor serial
void mostrarGolosinaSeleccionada() {
  Serial.print("Golosina seleccionada: ");//IMPRIME en pantalla
  Serial.println(golosinas[indiceSeleccionado].nombre);//IMPRIME en pantalla
  Serial.print("Precio: ");//IMPRIME en pantalla
  Serial.print("Q ");//IMPRIME el tipo de moneda en la pantalla
  Serial.println(golosinas[indiceSeleccionado].precio);//IMPRIME en pantalla
  Serial.print("Cantidad: ");//IMPRIME en pantalla
  Serial.println(golosinas[indiceSeleccionado].cantidad);//IMPRIME en pantalla
  Serial.print("Reserva: ");//IMPRIME en pantalla
  Serial.println(golosinas[indiceSeleccionado].reserva);//IMPRIME en pantalla
  Serial.print("PPL: ");//IMPRIME en pantalla
  Serial.print("Q ");//IMPRIME el tipo de moneda en la pantalla
  Serial.println(golosinas[indiceSeleccionado].ppl);//IMPRIME en pantalla
}
