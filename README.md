# Connecting ESP32 to Amazon AWS IoT Core using MQTT

1. [Connecting ESP32 to Amazon AWS IoT Core using MQTT](https://how2electronics.com/connecting-esp32-to-amazon-aws-iot-core-using-mqtt)
2. [Building an AWS IoT Core device using AWS Serverless and an ESP32](https://aws.amazon.com/blogs/compute/building-an-aws-iot-core-device-using-aws-serverless-and-an-esp32)
3. Location in Windows -> C:\Users\IgorA\OneDrive\Área de Trabalho\Arduino\moisture_sensor
4. [T-Display-S3](https://github.com/igoralves1/T-Display-S3)
5. [Serial Monitor displays nothing. #126](https://github.com/Xinyuan-LilyGO/T-Display-S3/issues/126)
6. [Automatic Irrigation](https://www.aliexpress.us/item/3256804642371142.html?spm=a2g0o.order_list.order_list_main.75.40891802e3ZNxU&gatewayAdapt=glo2usa)
7. Location in Windows libraries ->C:\Users\IgorA\OneDrive\Área de Trabalho\Arduino\libraries
8. [lib - PubSubClient.h](https://pubsubclient.knolleary.net)
9. [googlechromelabs.github.io/serial-terminal](https://googlechromelabs.github.io/serial-terminal/)
10. [Postman now supports MQTT](https://blog.postman.com/postman-supports-mqtt-apis/)
11. [Add and manage digital certificates in Postman](https://learning.postman.com/docs/sending-requests/certificates/)
12. [MQTT overview](https://learning.postman.com/docs/sending-requests/mqtt-client/mqtt-client-overview/)
13. [Arduino Client for MQTT](https://pubsubclient.knolleary.net/)
14. [igoralves1/T-Display-S3/tree/main/firmware](https://github.com/igoralves1/T-Display-S3/tree/main/firmware)


### Arduino setup for ESP32

### Arduino

1. In Arduino Preferences, on the Settings tab, enter the `https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json` URL in the `Additional boards manager URLs` input box. 
2. Click OK and the software will install. 
3. Search for ESP32 in Tools → Board Manager and install `esp32` (Arduino-ESP32)
4. Copy everything from this repository lib folder to [Arduino library folder](https://docs.arduino.cc/software/ide-v1/tutorials/installing-libraries#manual-installation) (e.g. `C:\Users\YourName\Documents\Arduino\libraries`)
5. Select the correct settings in the Tools menu as shown below.

| Setting                  | Value                            |
| :----------------------- | :------------------------------- |
| USB CDC On Boot          | Enabled                          |
| CPU Frequency            | 240MHz (WiFi)                    |
| Core Debug Level         | None                             |
| USB DFU On Boot          | Enabled                          |
| Events Run On            | Core 1                           |
| Flash Mode               | QIO 80MHz                        |
| Flash Size               | 16MB (128Mb)                     |
| JTAG Adapter             | Integrated USB JTAG              |
| Arduino Runs On          | Core 1                           |
| USB Firmware MSC On Boot | Disabled                         |
| Partition Scheme         | Huge APP (3MB No OTA/1MB SPIFFS) |
| PSRAM                    | OPI PSRAM                        |
| USB Mode                 | Hardware CDC and JTAG            |