#include <Wire.h>
#include <Adafruit_ADS1015.h>
#define pinADS1115sensorHumedad 1 
const int AirValue = 30300;  // Medimos valor en seco (calibrado)
const int WaterValue = 16400;  // Medimos valor en agua (calibrado)

//valores maximos
int maximoValor = 0;
int minimoValor = 0;
int valorMedio = 0;
//

void setupHumedad() {
  ads1115.begin(); //Initialize ads1115
  ads1115.setGain(GAIN_ONE); //Indicamos el tipo de ganancia del ads
}

int loopHumedad() {
//inicialitzacion variables
int16_t adc0;
int16_t humedad;
adc0 = ads1115.readADC_SingleEnded(pinADS1115sensorHumedad);
humedad = 100*AirValue/(AirValue-WaterValue)-adc0*100/(AirValue-WaterValue);
//
//la calibración tiene un 99% de precision por lo que los valores de porcentaje muestran
//unos extremos de 101% y -1%, para evitar esos porcentajes hacemos un control de valores 
if (humedad > 100){
  humedad=100;
}
if (humedad<0){
  humedad=0;
}
//
//guardamos el porcentaje maximo y minimo de humedad
if (humedad > mayor){
  mayor = humedad;
}
if (humedad < menor){
  menor = humedad;
}
return humedad;
}
