// OBS: OS CODIGOS DE CORES ESTAO INVERTIDOS
// include TFT and SPI libraries
#include <TFT.h>  
#include <SPI.h>
#include <DHT.h>
#define DHTPIN 2 //pino digital 2 conectado ao DHT11
#define DHTTYPE DHT11 //define que o sensor e o DHT11

DHT dht(DHTPIN, DHTTYPE); //inicializando o DHT11

// pin definition for Arduino UNO
#define cs   10
#define dc   9
#define rst  8

// create an instance of the library
TFT TFTscreen = TFT(cs, dc, rst);




void setup() {

  dht.begin();
  //initialize the library
  TFTscreen.begin();

  // seta o fundo da tela para preto
  TFTscreen.background(255, 255, 255);
  //set the text size
  TFTscreen.setTextSize(2);
  // inverte a tela (1 e paisagem, 2 e retrato, 3 e paisagem invertido e 4 e retrato invertido)
  TFTscreen.setRotation(3);
}

void loop() {
  
  delay(2000); //delay de 2s entre medicoes

  // preenche o espaco dos valores, permitindo que eles sejam atualizados
  TFTscreen.stroke(255, 255, 255);
  TFTscreen.fill(255, 255, 255);
  TFTscreen.rect(50, 47, 60, 15);
  TFTscreen.rect(85, 67, 60, 15);

  float umid = dht.readHumidity(); // registra o valor da temperatura
  float temp = dht.readTemperature();
  char temp_string[0];
  char umid_string[60];
  dtostrf(temp, 5, 1, temp_string);
  dtostrf(umid, 5, 1, umid_string);


  // seta a cor do texto para branco
  TFTscreen.stroke(0, 0, 0);
  
  // print "menu" no topo da tela, alinhado ao meio 
  TFTscreen.text("Menu", 53, 27);

  // print "Temp" logo abaixo do "menu", alinhado à esquerda
  TFTscreen.text("Temp:     C", 0, 47);
  // print do valor da temperatura
  TFTscreen.text(temp_string, 50, 47);

  // print "Umidade" logo abaixo do "temperatura", alinhado à esquerda
  TFTscreen.text("Umidade:      /", 0, 67);
  // print do valor da temperatura
  TFTscreen.text(umid_string, 85, 67);
}