const int sensorPin=A0;
const float baselineTemp = 20.0;

void setup()
{
  Serial.begin(9600);
  
  for(int pinNumber = 2; pinNumber<5; pinNumber++)
  {
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
}

void loop()
{
  int sensorVal = analogRead(sensorPin);
  
  Serial.print("Sensor Value: "); Serial.print(sensorVal);
  
  float voltage = (sensorVal/1024.0) * 5.0;
  Serial.print(", Volts: "); Serial.print(voltage); 
  
  float tempC = (voltage - .5) * 100;
  Serial.print(", Celciius: "); Serial.print(tempC); 
  
  float tempF = (tempC * 9/5) + 32;
  Serial.print(", fFahrenheit: "); Serial.print(tempF); 
  
  Serial.print("\r\n");
  delay(250);
}
