#include <ESP8266WiFi.h> // Importa a Biblioteca ESP8266WiFi
#include <PubSubClient.h> // Importa a Biblioteca PubSubClient
#include "StringSplitter.h"


//****************************************
//  Dispositivo de Controle de Iluminação
//  Sub -> (Comando = 1, Comando = 0) -> Se (Comando == 1) Liga Lampada, Se (Comando == 0) Desliga Lampada
//  Pub -> (Comando = 1, Comando = 0) -> Se (Comando == 1) Respota "On", Se (Comando == 0) Respota "Off"
//****************************************


#define TOPICO_SUB_LED1  "******************************"
#define TOPICO_PUB_LED1  "******************************"

#define TOPICO_SUB_LED2  "******************************"
#define TOPICO_PUB_LED2  "******************************"

#define TOPICO_SUB_LED3  "******************************"
#define TOPICO_PUB_LED3  "******************************"

// REDE WIFI

const char* SSID = "Moura";           //Nome da Minha rede Wifi
const char* PASSWORD  = "****";   // Senha da Minha rede Wifi


//MQTT
const char* BROKER_MQTT ="mqtt.autodomo.io"; //"10.0.0.198";  // Endereço do Servidor Broker;
int BROKER_PORT = 1883;                         // Porta do Servidor

// USER/PASSWORD MQTT

const char* User_MQTT = "*******";           // Usuario MQTT
const char* Pass_MQTT = "************";         // Senha MQTT
 

int Rele1 = 5;
int Rele2 = 4;
int Rele3 = 0; //R
int Contagem = 0;

WiFiClient espClient; // Cria o objeto espClient
PubSubClient MQTT(espClient); // Instancia o Cliente MQTT passando o objeto espClient

//void mqtt_callback(char* topic, byte* payload, unsigned int length);

void setup() {
  // put your setup code here, to run once:
  InitPinos();
  InitSerial();
  initWiFi();
  initMQTT();
}


void loop() {
  // put your main code here, to run repeatedly:
  verificaConexaoWIFIMQTT();
  MQTT.loop();
//delay(1000);
}
