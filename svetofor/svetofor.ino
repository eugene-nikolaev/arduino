int redPin = 4;
int yellowPin = 8;
int greenPin = 6;
int arrowPin = 10;

void setup(){
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(arrowPin, OUTPUT);
}

void loop(){
  digitalWrite(redPin, HIGH);
  digitalWrite(yellowPin, LOW);
  digitalWrite(greenPin, LOW);
  digitalWrite(arrowPin, LOW);
  delay(2000);
  digitalWrite(arrowPin, HIGH);
  delay(2000);
  digitalWrite(redPin, HIGH);
  digitalWrite(yellowPin, HIGH);
  delay(2000);
  digitalWrite(redPin, LOW);
  digitalWrite(yellowPin, LOW);
  digitalWrite(greenPin, HIGH);
  delay(2000);
  for(int i = 1; i <= 10; i++) {
    int val = digitalRead(greenPin);
    if (val == HIGH) {        
      digitalWrite(greenPin, LOW); 
      digitalWrite(arrowPin, LOW); 
    } else {
      digitalWrite(greenPin, HIGH);
      digitalWrite(arrowPin, HIGH); 
    }
    delay(500);
  }
  digitalWrite(greenPin, LOW);
  digitalWrite(yellowPin, HIGH);
  digitalWrite(arrowPin, LOW);
  delay(1500);
  digitalWrite(redPin, HIGH);
  digitalWrite(yellowPin, LOW);
  delay(2000);
}
