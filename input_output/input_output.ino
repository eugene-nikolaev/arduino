int val1 = 0;
int val2 = 0;
int val3 = 0;
int val4 = 0;
int val5 = 0;

int outVal1 = 0;
int outVal2 = 0;
int outVal3 = 0;
int outVal4 = 0;

void setup() {
  // Numbers hardcoded for samples - better define in variables
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  
  pinMode(9,  OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
}

void loop()  { 
  int val1 = digitalRead(4);
  int val2 = digitalRead(5);
  int val3 = digitalRead(6);
  int val4 = digitalRead(7);
  int val5 = digitalRead(8);

  // !!!
  // Here some code which convert val1-val5 state to outVal1-outVal4 state
  // !!!
  
  digitalWrite(9, outVal1);
  digitalWrite(10, outVal2);
  digitalWrite(11, outVal3);
  digitalWrite(12, outVal4);  

  delay(40); // some relevent delay if needed
}
