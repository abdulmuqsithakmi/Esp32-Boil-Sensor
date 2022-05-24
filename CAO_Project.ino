#include<WiFi.h>
#include<HTTPClient.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// GPIO where the DS18B20 is connected to
const int oneWireBus = 4; 

const char* ssid     = "Redmi 9";
const char* password = "muqsit19";

const char* serverName = "https://maker.ifttt.com/trigger/boil/with/key/ny0_SyEvlquuIfxWGVIMPtmDAVeNea9_1JTiG7K_Wje";


    int ld = 18;
    int buzz=19;


OneWire oneWire(oneWireBus);


DallasTemperature sensors(&oneWire);

void setup() {

  pinMode(ld,OUTPUT);
  pinMode(buzz,OUTPUT);
  // Start the Serial Monitor
  Serial.begin(115200);
  // Start the DS18B20 sensor
  sensors.begin();

  
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.println("Connecting...");
    }

    Serial.println("");
    Serial.println("WiFi connected to :");
    Serial.println(ssid);
    Serial.println("IP : ");
    Serial.println(WiFi.localIP());


}

void loop() {
  sensors.requestTemperatures(); 
  
  float temperatureC = sensors.getTempCByIndex(0);
  
  Serial.print(temperatureC);
  Serial.println("ºC");
  
  delay(1000);

  if(temperatureC>31){

    HTTPClient http;

      http.begin(serverName);

      http.addHeader("Content-Type", "application/json");
      String httpRequestData = "{\"value1\":\"The Milk is Boiled\"}";
      int httpResponseCode = http.POST(httpRequestData);

      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);

      http.end();

    while(1){
    digitalWrite(ld,HIGH);
    for(int i=0;i<200;i++){

      digitalWrite(buzz,HIGH);
      delay(2);
      digitalWrite(buzz,LOW);
      delay(2);
    }

    

    for(int j=0;j<100;j++){

      digitalWrite(buzz,HIGH);
      delay(3);
      digitalWrite(buzz,LOW);
      delay(3);
    }
    

  }

  }
  }

    
  
