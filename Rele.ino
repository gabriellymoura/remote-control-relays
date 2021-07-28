void defineStateLED1(String msg){
    if (msg == "1"){
      digitalWrite(Rele1, HIGH);
      MQTT.publish(TOPICO_PUB_LED1, "1");
    }else if (msg == "0"){
      MQTT.publish(TOPICO_PUB_LED1, "0");
      digitalWrite(Rele1, LOW);
    }else if (msg == "restart"){
     ESP.reset();    }
}
void defineStateLED2(String msg){
    if (msg == "1"){
      digitalWrite(Rele2, HIGH);
      MQTT.publish(TOPICO_PUB_LED2, "1");
    }else if (msg == "0"){
      MQTT.publish(TOPICO_PUB_LED2, "0");
      digitalWrite(Rele2, LOW);
    }else if (msg == "restart"){
     ESP.reset();    }
}
void defineStateLED3(String msg){
    if (msg == "1"){
      digitalWrite(Rele3, HIGH);
      MQTT.publish(TOPICO_PUB_LED3, "1");
    }else if (msg == "0"){
      MQTT.publish(TOPICO_PUB_LED3, "0");
      digitalWrite(Rele3, LOW);
    }else if (msg == "restart"){
     ESP.reset();    }
}
