#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11); // RX, TX

void setup() {
  pinMode(13, OUTPUT);

  Serial.begin(9600);
  BTSerial.begin(9600);
}

void loop() {

  while (BTSerial.available() > 0) {

    char receivedChar = BTSerial.read();

    Serial.print("Mensaje recibido: ");
    Serial.println(receivedChar);

    if (receivedChar == '1') {

      Serial.println("Se recibió comando de encendido");
      digitalWrite(13, HIGH);

      BTSerial.println("Se encendio el LED");
      

    } 
    else if (receivedChar == '0') {

      Serial.println("Se recibió comando de apagado");
      digitalWrite(13, LOW);

      BTSerial.println("Se apago el LED");

    } 
    else {

      Serial.println("Se recibió comando inválido");
      BTSerial.println("No hubo accion, comando invalido");

    }
  }
}
