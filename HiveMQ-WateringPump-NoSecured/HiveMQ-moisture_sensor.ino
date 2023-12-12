#include <WiFiClientSecure.h>
#include <ArduinoJson.h>
#include "WiFi.h"
#include <PubSubClient.h>

const char* ssid = "Frontier5664";
const char* password = "0546758114";
const char* mqttServer = "broker.hivemq.com";
const int mqttPort = 1883;


#define HIVEMQ_IOT_PUBLISH_TOPIC   "esp32/pub"
#define HIVEMQ_IOT_SUBSCRIBE_TOPIC "esp32/sub"
 
WiFiClient espClient;
PubSubClient client(espClient);


void connectHIVEMQ(){
  Serial.println("connectHIVEMQ Fn");

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
 
  Serial.println("Connecting to Wi-Fi");
 
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
 

 
  // Connect to the MQTT broker on the AWS endpoint we defined earlier
  client.setServer(mqttServer, mqttPort);
 
  // Create a message handler
  client.setCallback(messageHandler);
 
  Serial.println("Connecting to HIVEMQ IOT");
 
  while (!client.connect(THINGNAME))
  {
    Serial.print(".");
    delay(100);
  }
 
  if (!client.connected())
  {
    Serial.println("HIVEMQ Timeout!");
    return;
  }
 
  // Subscribe to a topic
  client.subscribe(HIVEMQ_IOT_SUBSCRIBE_TOPIC);
 
  Serial.println("HIVEMQ Connected!");
}
 
void publishMessage(char* status, int seconds){
  StaticJsonDocument<200> doc;
  doc["status"] = status;
  doc["time(s)"] = seconds;
  char jsonBuffer[512];
  serializeJson(doc, jsonBuffer);
  client.publish(HIVEMQ_IOT_PUBLISH_TOPIC, jsonBuffer);
}
 
void messageHandler(char* topic, byte* payload, unsigned int length){
  Serial.print("incoming: ");
  Serial.println(topic);
  
  StaticJsonDocument<200> doc;
  deserializeJson(doc, payload);
  const char* message = doc["message"];
  Serial.println(message);
}

const int relay4 = 16;

void setup() {
  Serial.begin(115200);
  Serial.println("Setup()");
  connectHIVEMQ();
  pinMode(relay4, OUTPUT);
}

void loop() {

  Serial.println("Desliga o motor");
  digitalWrite(relay4, HIGH);
  publishMessage("Motor Desligado", 0);  
  client.loop();
  for(int i = 1; i<=3600; i++){ //Set i<=28800 in PROD i<=10 in DEV
    Serial.println(i);
    if ( (i%60)  == 0 ){
      Serial.println("+ 1 Min");  
      publishMessage("+ 1 Min", i);
      client.loop();      
    }
    client.loop(); 
    delay(1000);
  }
  
  Serial.println("Liga o motor");
  digitalWrite(relay4, LOW);
  for(int i = 1; i<=15; i++){
    Serial.println(i);

    publishMessage("Motor Ligado", i);  
    client.loop();    

    delay(1000);
  }

  Serial.println("....");
}

