int LS = 2;
int RS = 3;

void setup() {
  pinMode(LS, INPUT);
  pinMode(RS, INPUT);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop() {
  if ((digitalRead(LS) == HIGH) && (digitalRead(RS) == HIGH)) {
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
  }

  if ((digitalRead(LS) == LOW) && (digitalRead(RS) == HIGH)) {
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    digitalWrite(11, HIGH);
    digitalWrite(10, LOW);
  }

  if ((digitalRead(LS) == HIGH) && (digitalRead(RS) == LOW)) {
    digitalWrite(13, HIGH);
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
  }

  if ((digitalRead(LS) == LOW) && (digitalRead(RS) == LOW)) {
    digitalWrite(13, HIGH);
    digitalWrite(12, LOW);
    digitalWrite(11, HIGH);
    digitalWrite(10, LOW);
  }
}