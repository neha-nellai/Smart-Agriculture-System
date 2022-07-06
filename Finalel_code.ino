#define BLYNK_PRINT Serial    
#include <SPI.h>
#include <ESP8266WiFi.h>       
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>

char auth[] = "FVJCJPccDGiWV47_NTmXJtkG5Qpzzl1L"; //Enter the Auth code which was sent by Blink

// Your WiFi credentials.
char ssid[] = "NehaGalaxyM51F1A6";  //Enter your WIFI Name
char pass[] = "12345678";  //Enter your WIFI Password

//DHT dht(DHTPIN, DHTTYPE);
int sensor_pin = A0; // Soil Sensor input at Analog PIN A0
int output_value ;
//int output_value1 ;
BlynkTimer timer;

void sendSensor()
{
  output_value = analogRead(A0);
  output_value = map(output_value,1024,200,0,100);
  Blynk.virtualWrite(V5, output_value);
}

void setup()
{
  
  Serial.begin(9600); // See the connection status in Serial Monitor
  Blynk.begin(auth, ssid, pass,"blynk-cloud.com",8080);

  pinMode(0,OUTPUT);
  Serial.println("Reading From the Sensor ...");
  delay(2000);

  // Setup a function to be called every second
  timer.setInterval(1000L, sendSensor);
}

void loop()
{
  output_value= analogRead(sensor_pin);
  output_value = map(output_value,1024,200,0,100);
  Serial.print("Mositure : ");
  Serial.print(output_value);
  Serial.println("%");
  delay(1000);

 digitalWrite(0,HIGH);
 delay(1000);
 digitalWrite(0,LOW);
 delay(1000);
  Blynk.run(); // Initiates Blynk
  timer.run(); // Initiates SimpleTimer
}
