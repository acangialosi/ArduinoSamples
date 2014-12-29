const int sensorPin=A0;
float baselineTemp = 20.0;

void setup()
{
  Serial.begin(9600);
  
  for(int pinNumber = 2; pinNumber<5; pinNumber++)
  {
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }

  int sensorVal = 0;
  int sample; 
  for(sample = 0; sample < 5; sample++)
  {
    delay(1);
    sensorVal += analogRead(sensorPin);
  }
  sensorVal = sensorVal / sample;
  
  baselineTemp = (((sensorVal/1024.0) * 5.0) - .5) * 100;
  Serial.print("Baseline Temp: "); Serial.println(baselineTemp);
}

void loop()
{
  Serial.print("Baseline Temp: "); Serial.print(baselineTemp);

  int sensorVal = analogRead(sensorPin);
  
  Serial.print("Sensor Value: "); Serial.print(sensorVal);
  
  float voltage = (sensorVal/1024.0) * 5.0;
  Serial.print(", Volts: "); Serial.print(voltage); 
  
  float tempC = (voltage - .5) * 100;
  Serial.print(", Celciius: "); Serial.print(tempC); 
  
  float tempF = (tempC * 9/5) + 32;
  Serial.print(", Fahrenheit: "); Serial.print(tempF); 
  
  Serial.println("");
  
  if(tempC < baselineTemp)
  {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
  else if(tempC >= baselineTemp + 2 && tempC < baselineTemp + 4)
  {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }  
  else if(tempC >= baselineTemp + 4 && tempC < baselineTemp + 6)
  {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  }
  else if(tempC >= baselineTemp + 6)
  {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }    
  
  delay(1);
}
