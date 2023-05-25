#include <LiquidCrystal_I2C.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 2  // Pin para el bus OneWire

#define VENT_PIN 3     // Pin del ventilador
#define FOCO_PIN 6     // Pin del foco de calor

#define LDR_PIN_1 A0   // Pin analógico para LDR 1
#define LDR_PIN_2 A1   // Pin analógico para LDR 2
#define LDR_PIN_3 A2   // Pin analógico para LDR 3

#define LDR_VALOR 300 // Valor umbral para detección de huevos

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Dirección I2C: 0x27, 16 columnas y 2 filas

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

int numEggs = 0; // Contador de huevos

// Variables para las animaciones de temperatura
byte calorAnimacion[8] = {
  0b00000,
  0b11001,
  0b10101,
  0b10101,
  0b10011,
  0b10001,
  0b00000,
  0b00000
};

byte hieloAnimacion[8] = {
  0b00000,
  0b00100,
  0b00100,
  0b01110,
  0b11111,
  0b11111,
  0b01110,
  0b00000
};

byte Animacioneggs[8] = {
  0b00000,
  0b00100,
  0b01110,
  0b11111,
  0b11111,
  0b11111,
  0b01110,
  0b00000
};

void setup() {
  lcd.init();  // Inicializar la pantalla I2C

  lcd.backlight();  // Encender la retroiluminación (si la pantalla lo soporta)

  lcd.print("Incubadora Bros");

  pinMode(VENT_PIN, OUTPUT);
  pinMode(FOCO_PIN, OUTPUT);

  sensors.begin();

  // Cargar las animaciones personalizadas en la memoria del LCD
  lcd.createChar(1, calorAnimacion);
  lcd.createChar(2, hieloAnimacion);
  lcd.createChar(3, Animacioneggs);
}

void loop() {
  sensors.requestTemperatures();  // Obtener la temperatura del sensor

  float temperatura = sensors.getTempCByIndex(0);  // Obtener la temperatura en grados Celsius

  lcd.setCursor(0, 1);
  lcd.print("Temp: ");

  if (temperatura <= 38.0) {
    lcd.write(1); // Mostrar la animación de temperatura alta
  } else if (temperatura >= 36.0) {
    lcd.write(2); // Mostrar la animación de temperatura baja
  } else {
    lcd.print(temperatura);
    lcd.write(0xDF); // Símbolo de grado
    lcd.print("C ");
  }
  if (temperatura <= 38.0) {
    digitalWrite(VENT_PIN, HIGH);  // Encender el ventilador
  } else if (temperatura >= 36.0) {
    digitalWrite(VENT_PIN, LOW);   // Apagar el ventilador
  }

  // Lectura de los valores de los LDR
  int ldrValor1 = analogRead(LDR_PIN_1);
  int ldrValor2 = analogRead(LDR_PIN_2);
  int ldrValor3 = analogRead(LDR_PIN_3);
  

  // Contar los huevos detectados por los LDR
  int Contadordeeggs = 0;
  if (ldrValor1 <= LDR_VALOR) Contadordeeggs++;
  if (ldrValor2 <= LDR_VALOR) Contadordeeggs++;
  if (ldrValor3 <= LDR_VALOR) Contadordeeggs++;
  

  // Actualizar el contador de huevos en el LCD
  lcd.setCursor(14, 1);
  lcd.print("  "); // Limpiar el espacio
  lcd.setCursor(14, 1);
  lcd.print("  "); // Limpiar el espacio anterior
  lcd.setCursor(14, 1);
  lcd.print(Contadordeeggs);

  // Animación de caracteres para el contador de huevos
  lcd.write(3); // Mostrar la animación de huevos
  

  // Si se detecta un cambio en la cantidad de huevos
  if (Contadordeeggs  != numEggs) {
    numEggs == Contadordeeggs;
    // Realizar alguna acción cuando se saque o se agregue un huevo
    if (numEggs > 0) {
      // Acciones cuando se agrega un huevo
      digitalWrite(FOCO_PIN, HIGH);  // Encender el foco de calor
      delay(500); // Esperar 5 segundos para simular el tiempo de incubación
    } else {
      // Acciones cuando se saca un huevo
      digitalWrite(FOCO_PIN, LOW);   // Apagar el foco de calor
      delay(200); // Esperar 2 segundos antes de encender el foco de calor nuevamente
    }
  }
}
