#include <lm35library.h>

#define pinInput 13 // Utilizando pino 13 do arduíno como entrada
LM35Temperature lm35(pinInput); // Instanciando a classe LM35Temperature

void setup() {
  
  Serial.begin(9600);
  Serial.println("Selecione uma opcao: ");
  Serial.println("Digite 'C' para Celsius");
  Serial.println("Digite 'K' para Kelvin");
  Serial.println("Digite 'F' para Fahrenheit");

}

void loop() {
  
  if (Serial.available()) {
    
    char unidade = Serial.read(); // Lê a opcao escolhida
    lm35.readTemperature(unidade); // Chamada da função que converte a temperatura
  
  }

}