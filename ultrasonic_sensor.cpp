#define trigPin 13
#define echoPin 12
#define onepin 11
void setup() 
{
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(onepin,OUTPUT);
}
void loop() 
{
  long duration, distance;
  digitalWrite(trigPin, LOW);        
  delayMicroseconds(2);              
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);           
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  if (distance >= 2000 || distance <= 0)
  {
    Serial.println("Out of range");
  }
  else 
  {
    Serial.print(distance);
    Serial.println(" cm");
  }
  if (distance<=10)
  {
      digitalWrite(onepin,HIGH);
  }
  else
  {
    digitalWrite(onepin,LOW);
  }
  
  delay(500);
}

void setup() {

  Bridge.begin();

  Console.begin();

  while (!Console) {

    ; // wait for Console port to connect.

  }

  Console.println("ASCII Table ~ Character Map");
}
