void initMQTT() 
{
  MQTT.setServer(BROKER_MQTT, BROKER_PORT);
  MQTT.setCallback(mqtt_callback);

}

void mqtt_callback(char* topic, byte* payload, unsigned int length){
    String msg;
    String topico;
          //obtem a string do payload recebido
    for(int i = 0; i < length; i++) {
       char c = (char)payload[i];
       msg += c;
    }
    for(int i = 0; i < length; i++) {
       char c = (char)topic[i];
       topico += c;
    } 

    Serial.print("Mensagem Recebida: ");
    Serial.print(msg);
    Serial.print(" no tópico: ");
    Serial.println(topic);
    Serial.println(TOPICO_SUB_LED1);

    if (strcmp(topic, TOPICO_SUB_LED1) == 0){
        defineStateLED1(msg);
    }
    else if (strcmp(topic, TOPICO_SUB_LED2) == 0){
        defineStateLED2(msg); 
    }
    else if (strcmp(topic, TOPICO_SUB_LED3) == 0){
        defineStateLED3(msg); 
    }
}
