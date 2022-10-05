int LED

void setup() {
  LED = 10
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop() {
  
  if(Serial.available())
  {
    LED = Serial.readString();
    if(LED == "on")
    {
      digitalWrite(10,HIGH);

    }
    else if(LED == "off")
    {
      digitalWrite(10, LOW);
    }
  }
