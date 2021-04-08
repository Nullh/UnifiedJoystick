 const int xPin = A1;
const int yPin = A0;
const int switchPin = 8;
const int selectorPin = 9;
const int upOutPin = 7; // blue
const int downOutPin = 6; // green
const int leftOutPin = 5; // red
const int rightOutPin = 4; // yellow
const int fireOutPin = 3; // white


int yValue = 0;
int yPotValue = 0;
int xValue = 0;
int xPotValue = 0;
int buttonValue = 0;
int selectorState = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(switchPin, INPUT);
  pinMode(upOutPin, OUTPUT);
  pinMode(downOutPin, OUTPUT);
  pinMode(leftOutPin, OUTPUT);
  pinMode(rightOutPin, OUTPUT);
  pinMode(fireOutPin, OUTPUT);
  pinMode(selectorPin, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  yPotValue = analogRead(yPin);
  yValue = map(yPotValue, 0, 1024, 0, 255);

  xPotValue = analogRead(xPin);
  xValue = map(xPotValue, 0, 1024, 0, 255);

  buttonValue = digitalRead(switchPin);
  selectorState = digitalRead(selectorPin);

  Serial.print("x value = ");
  Serial.print(xValue);
  Serial.print(", y value = ");
  Serial.print(yValue);
  Serial.print(", button = ");
  Serial.print(buttonValue);
  Serial.print(", selector = ");
  Serial.print(selectorState);

  if (buttonValue == 1) {
    switchOn(fireOutPin, selectorState);
    Serial.print(", FIRE on");
  } else {
    switchOff(fireOutPin, selectorState);
    Serial.print(", FIRE off");
  }

  if (yValue <= 100) {
    switchOn(upOutPin, selectorState);
    Serial.print(", UP on");
  } else {
    switchOff(upOutPin, selectorState);
    Serial.print(", UP off");
  }

  if (yValue >= 200) {
    switchOn(downOutPin, selectorState);
  } else {
    switchOff(downOutPin, selectorState);
  }

  if (xValue <= 100) {
    switchOn(leftOutPin, selectorState);
  } else {
    switchOff(leftOutPin, selectorState);
  }

  if (xValue >= 200) {
    switchOn(rightOutPin, selectorState);
  } else {
    switchOff(rightOutPin, selectorState);
  }
  Serial.println("");
  delay(2);
}

void switchOn(int writePin, int selectorState){
  if (selectorState == HIGH) {
    digitalWrite(writePin, HIGH);
  } else {
    digitalWrite(writePin, LOW);
  }
}

void switchOff(int writePin, int selectorState){
  if (selectorState == LOW) {
    digitalWrite(writePin, HIGH);
  } else {
    digitalWrite(writePin, LOW);
  }
}
