#include <Servo.h>
#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN,DHTTYPE);

Servo myservo;  // create servo object to control a servo

int pos = 0;
int pressCount = 0;


void setup() {
  Serial.begin(9600);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  Serial.println("Start");
  dht.begin();
}

void loop() {
  float humid = dht.readHumidity();
  float temp = dht.readTemperature();

  if(isnan(humid)||isnan(temp)){
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  Serial.print(temp); Serial.print("*C,  ");
  Serial.print(humid); Serial.println("%");

  if (temp>=25||pressCount == 0){
    pressBT();
    pressCounter;
  }
  else if (temp < 25 || pressCount == 1){
    pressBT();
    pressCount = 0;
    return pressCount;
  }  
  delay(1500); 
} //void loop close

void pressCounter()
{
  pressCount++;
}

void pressBT(){
  pos+=1;
  if(pos>=180){
    pos = 0;
    myservo.write(pos);
    delay(100);
  }
 }
