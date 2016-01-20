

int led1 = D0;
int led2 = D7; 

//SYSTEM_MODE(AUTOMATIC);//connect to cloud
SYSTEM_MODE(MANUAL);//do not connect to cloud

void setup() {

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {

  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);

  delay(1000);

  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);

  delay(1000);
}


