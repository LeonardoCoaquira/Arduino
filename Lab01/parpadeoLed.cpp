// C++ code
//
/*
  This program blinks pin 13 of the Arduino (the
  built-in LED)
*/

const int ledPin = 13; // Pin del LED

void parpadear(int repeticiones, int tiempoParpadeo) {
  for (int i = 0; i < repeticiones; i++) { // Cantidad de veces a repetir
    digitalWrite(ledPin, HIGH); // Encendido de LED
    delay(tiempoParpadeo); // Tiempo de espera
    digitalWrite(ledPin, LOW); // Apagado del LED
    delay(tiempoParpadeo); // Tiempo de espera
  }
}

void setup() {
  pinMode(ledPin, OUTPUT); // Se define el pin del LED como salida
  Serial.begin(9600); // Se inicia la comunicación serial a 9600 baudios
}

void loop() {
  if (Serial.available()) {
    char comando = Serial.read(); // Lectura del caracter
    switch (comando) { // Se pasa a comprobar el caracter
      case 'A':
        parpadear(2, 500); // Llamada a la funcion
        break;
      case 'B':
        parpadear(4, 500);
        break;
      case 'C':
        parpadear(1, 1000);
        break;
      case 'D':
        parpadear(1,2000);
        break;
      default:
        break;
    }
  }
}