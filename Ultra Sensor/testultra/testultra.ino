class Ultra
{
  int trig,echo;

public:
  Ultra(int pin1, int pin2)
  {
    pinMode(pin1,OUTPUT);
    pinMode(pin2,INPUT);
    trig = pin1;
    echo = pin2;

  }

  long Time()
  {
    digitalWrite(trig,HIGH);
    delayMicroseconds(1000);
    digitalWrite(trig,LOW);
    return(pulseIn(echo,HIGH));
  }
  long Range()
  {
    long x,y;
    digitalWrite(trig,HIGH);
    delayMicroseconds(1000);
    digitalWrite(trig,LOW);
    x = pulseIn(echo,HIGH);
    y= (x/2)/29.1;
    return(y);

  }

};

Ultra AKR(2,3);
String strTime, strRange, strOutput;

void setup()
{
  Serial.begin(9600);
  strTime = "Time; ";
  strRange = "Range: ";
  strOutput = String();
}

void loop()
{  
  strOutput = strTime + AKR.Time();
  Serial.println(strOutput);
  
  strOutput = strRange + AKR.Range() + "CM";
  Serial.println(strOutput);

  delay(1000);
}

