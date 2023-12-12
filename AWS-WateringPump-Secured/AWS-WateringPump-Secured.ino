// moisture_sensor.ino

#include "secrets.h"
#include <WiFiClientSecure.h>
#include <ArduinoJson.h>
#include "WiFi.h"
#include <PubSubClient.h>



#define AWS_IOT_PUBLISH_TOPIC   "esp32/pub"
#define AWS_IOT_SUBSCRIBE_TOPIC "esp32/sub"
 
WiFiClientSecure net = WiFiClientSecure();
PubSubClient client(net);

void connectAWS(){
  Serial.println("connectAWS Fn");

  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
 
  Serial.println("Connecting to Wi-Fi");
 
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
 
  // Configure WiFiClientSecure to use the AWS IoT device credentials
  net.setCACert(AWS_CERT_CA);
  net.setCertificate(AWS_CERT_CRT);
  net.setPrivateKey(AWS_CERT_PRIVATE);
 
  // Connect to the MQTT broker on the AWS endpoint we defined earlier
  client.setServer(AWS_IOT_ENDPOINT, 8883);
 
  // Create a message handler
  client.setCallback(messageHandler);
 
  Serial.println("Connecting to AWS IOT");
 
  while (!client.connect(THINGNAME))
  {
    Serial.print(".");
    delay(100);
  }
 
  if (!client.connected())
  {
    Serial.println("AWS IoT Timeout!");
    return;
  }
 
  // Subscribe to a topic
  client.subscribe(AWS_IOT_SUBSCRIBE_TOPIC);
 
  Serial.println("AWS IoT Connected!");
}
 
void publishMessage(char* status, int seconds)
{
  StaticJsonDocument<200> doc;
  doc["status"] = status;
  doc["time(s)"] = seconds;
  char jsonBuffer[512];
  serializeJson(doc, jsonBuffer);
  client.publish(AWS_IOT_PUBLISH_TOPIC, jsonBuffer);
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
  connectAWS();
  pinMode(relay4, OUTPUT);
}

void loop() {

  Serial.println("Desliga o motor");
  digitalWrite(relay4, HIGH);
  publishMessage("Motor Desligado", 0);  
  client.loop();
  for(int i = 1; i<=3600*2; i++){ //Set i<=28800 in PROD i<=10 in DEV
    Serial.println(i);
    if ( (i%1800)  == 0 ){
      Serial.println("0.5hs");  
      publishMessage("Im_Alive", i);
      client.loop();      
    }
    delay(1000);
  }
  
  Serial.println("Liga o motor");
  digitalWrite(relay4, LOW);
  for(int i = 1; i<=20; i++){
    Serial.println(i);
    if ( i  == 10 ){ 
      publishMessage("Motor Ligado", i);  
      client.loop();    
    }
    delay(1000);
  }

  Serial.println("....");
}
