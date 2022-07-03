#include <MQ7.h>



#include <ESP8266WiFi.h>

#include <ThingSpeak.h>

MQ7 mq7(A0, 5.0);

WiFiClient client;

long myChannelNumber = 1307401;
const char myWriteAPIKey[] = "ASXFL4ZRR8U181LV";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  WiFi.begin("GPONWIFI_4588", "00000054D5");
  while(WiFi.status() != WL_CONNECTED)
  {
    delay(200);
    Serial.print("..");
  }
  Serial.println();
  Serial.println("NodeMCU is connected!");
  Serial.println(WiFi.localIP());
 
  ThingSpeak.begin(client);
}

void loop() {
  // put your main code here, to run repeatedly:
 float ppm = mq7.getPPM();
int sensorValue =  mq7.getPPM();
  Serial.println(sensorValue, mq7.getPPM());
  ThingSpeak.setField( 1, ppm);
ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
   
 
 
 
  delay(20000);
}
