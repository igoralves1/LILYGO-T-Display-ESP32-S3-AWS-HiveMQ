#include <WiFiClientSecure.h>
#include <ArduinoJson.h>
#include "WiFi.h"
#include <PubSubClient.h>
// #include <esp_task_wdt.h>


const char* ssid = "Frontier5664";
const char* password = "0546758114";
const char* mqttServer = "broker.hivemq.com";
const int mqttPort = 1883;


#define HIVEMQ_IOT_PUBLISH_TOPIC   "esp32/pub"
#define HIVEMQ_IOT_SUBSCRIBE_TOPIC "esp32/sub"
 
//3 seconds WDT
// #define WDT_TIMEOUT 3

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

  // esp_task_wdt_init(WDT_TIMEOUT, true); //enable panic so ESP32 restarts
  // esp_task_wdt_add(NULL); //add current thread to WDT watch

  connectHIVEMQ();
  pinMode(relay4, OUTPUT);
}

// int j = 0;
// int last = millis();

void loop() {

  // resetting WDT every 2s, 5 times only
  // if (millis() - last >= 2000 && j < 5) {
  //     Serial.println("Resetting WDT...");
  //     publishMessage("Resetting WDT...", j); 
  //     esp_task_wdt_reset();
  //     last = millis();
  //     j++;
  //     if (j == 5) {
  //       Serial.println("Stopping WDT reset. CPU should reboot in 3s");
  //       publishMessage("Stopping WDT reset. CPU should reboot in 3s", j);
  //     }
  // }

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
  for(int i = 1; i<=20; i++){
    Serial.println(i);

    publishMessage("Motor Ligado", i);  
    client.loop();    

    delay(1000);
  }

  Serial.println("....");
}

