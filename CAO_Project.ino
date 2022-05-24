#include <OneWire.h>
#include <DallasTemperature.h>

// GPIO where the DS18B20 is connected to
const int oneWireBus = 4; 

    int ld = 18;
    int buzz=19;

// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(oneWireBus);

// Pass our oneWire reference to Dallas Temperature sensor 
DallasTemperature sensors(&oneWire);

void setup() {

  pinMode(ld,OUTPUT);
  pinMode(buzz,OUTPUT);
  // Start the Serial Monitor
  Serial.begin(115200);
  // Start the DS18B20 sensor
  sensors.begin();

}

void loop() {
  sensors.requestTemperatures(); 
  float temperatureC = sensors.getTempCByIndex(0);
  float temperatureF = sensors.getTempFByIndex(0);
  Serial.print(temperatureC);
  Serial.println("ºC");
  Serial.print(temperatureF);
  Serial.println("ºF");
  delay(1000);

  if(temperatureC>50){

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

    
  
