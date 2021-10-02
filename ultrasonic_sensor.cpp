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
  long duration, distance, inches, cm;
  digitalWrite(trigPin, LOW);        
  delayMicroseconds(2);              
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);           
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
  distance = (duration/2) / 29.1;
  if (distance >= 2000 || distance <= 0)
  {
    Serial.println("Out of range");
  }
  else 
  {
    Serial.print(distance);
    Serial.println(" cm");
    Serial.print(inches);
    Serial.print("in, ");
    Serial.print(cm);
    Serial.print("cm");
    Serial.println();
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
long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}

void setup() {

  Bridge.begin();

  Console.begin();

  while (!Console) {

    ; // wait for Console port to connect.

  }

  Console.println("ASCII Table ~ Character Map");
}
