#include "lm35library.h"
#include "Arduino.h"

LM35Temperature::LM35Temperature(int pin) {

  _pin = pin;
  pinMode(_pin, INPUT);
}

float LM35Temperature::readTemperature(char unidade) {

  int rawValue = analogRead(_pin); //Leitura do valor cru do sensor
  float voltage = rawValue * (5.0 / 1024.0); //Calcula a tensão total do valor cru
  float temperatureCelsius = (voltage - 0.5) * 100.0; //Conversão para Celsius

  switch (unidade) {
    case 'C':
      return temperatureCelsius;
    case 'K':
      return temperatureCelsius + 273.15;
    case 'F':
      return (temperatureCelsius * 9.0 / 5.0) + 32.0;
    default:
      Serial.println("voce nao selecionou uma opcao");
  }
}
