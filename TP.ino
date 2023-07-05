const int pinA = 2;
const int pinB = 3;
const int pinC = 4;
const int pinD = 6;
const int pinE = 7;
const int pinF = 8;
const int pinG = 9;
const int pinDot = 5;

const int pinBarrier = 10;

const int pinSensor1 = 11;
const int pinSensor2 = 12;

int nAutos = 0;

void setup() { 
  // Se ponen los pines del display como out
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
  pinMode(pinE, OUTPUT);
  pinMode(pinF, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(pinDot, OUTPUT);

  // Se pone el pin de barrera como out
  pinMode(pinBarrier, OUTPUT);

  // Se ponen los pines de los botones como in
  pinMode(pinSensor1, INPUT_PULLUP);
  pinMode(pinSensor2, INPUT_PULLUP);

  cycleDisplaySegments();
  blinkLED();
  //cycleDisplayNumbers();
}

void loop() {
  
  while(true) {
    int sensor1 = digitalRead(pinSensor1);
    int sensor2 = digitalRead(pinSensor2);
    displayNumber(nAutos);
    delay(50);

    if (sensor1 == digitalRead(pinSensor1) && sensor1 == HIGH && sensor2 == digitalRead(pinSensor2) && sensor2 == HIGH) {
      bajarBarrera();
    } else if (sensor1 == digitalRead(pinSensor1) && sensor1 == LOW && sensor2 == digitalRead(pinSensor2) && sensor2 == HIGH && nAutos<10) {
      subirBarrera();
      state10A();
    } else if (sensor1 == digitalRead(pinSensor1) && sensor1 == HIGH && sensor2 == digitalRead(pinSensor2) && sensor2 == LOW) {
      subirBarrera();
      state01B();
    }
  }
}

void state10A() {
  while(true) {
    int sensor1 = digitalRead(pinSensor1);
    int sensor2 = digitalRead(pinSensor2);
    displayNumber(nAutos);
    delay(50);
  
    if (sensor1 == digitalRead(pinSensor1) && sensor1 == HIGH && sensor2 == digitalRead(pinSensor2) && sensor2 == HIGH){
      return;
    } else if (sensor1 == digitalRead(pinSensor1) && sensor1 == LOW && sensor2 == digitalRead(pinSensor2) && sensor2 == LOW) {
      state11A();
    }
  }
}

void state11A() {
  while(true) {
    int sensor1 = digitalRead(pinSensor1);
    int sensor2 = digitalRead(pinSensor2);
    displayNumber(nAutos);
    delay(50);

    if (sensor1 == digitalRead(pinSensor1) && sensor1 == HIGH && sensor2 == digitalRead(pinSensor2) && sensor2 == HIGH) {
      return;
    } else if (sensor1 == digitalRead(pinSensor1) && sensor1 == LOW && sensor2 == digitalRead(pinSensor2) && sensor2 == HIGH) {
      return;
    } else if (sensor1 == digitalRead(pinSensor1) && sensor1 == HIGH && sensor2 == digitalRead(pinSensor2) && sensor2 == LOW) {
      state01A();
    }
  }
}

void state01A() {
  while(true) {
    int sensor1 = digitalRead(pinSensor1);
    int sensor2 = digitalRead(pinSensor2);
    displayNumber(nAutos);
    delay(50);
    
    if (sensor1 == digitalRead(pinSensor1) && sensor1 == HIGH && sensor2 == digitalRead(pinSensor2) && sensor2 == HIGH) {
      nAutos++;
      return;
    } else if (sensor1 == digitalRead(pinSensor1) && sensor1 == LOW && sensor2 == digitalRead(pinSensor2) && sensor2 == LOW) {
      return;
    }
  }
}

void state01B() {
  while(true) {
    int sensor1 = digitalRead(pinSensor1);
    int sensor2 = digitalRead(pinSensor2);
    displayNumber(nAutos);
    delay(50);
  
    if (sensor1 == digitalRead(pinSensor1) && sensor1 == HIGH && sensor2 == digitalRead(pinSensor2) && sensor2 == HIGH){
      return;
    } else if (sensor1 == digitalRead(pinSensor1) && sensor1 == LOW && sensor2 == digitalRead(pinSensor2) && sensor2 == LOW) {
      state11B();
    }
  }
}

void state11B() {
  while(true) {
    int sensor1 = digitalRead(pinSensor1);
    int sensor2 = digitalRead(pinSensor2);
    displayNumber(nAutos);
    delay(50);

    if (sensor1 == digitalRead(pinSensor1) && sensor1 == HIGH && sensor2 == digitalRead(pinSensor2) && sensor2 == HIGH) {
      return;
    } else if (sensor1 == digitalRead(pinSensor1) && sensor1 == LOW && sensor2 == digitalRead(pinSensor2) && sensor2 == HIGH) {
      state10B();
    } else if (sensor1 == digitalRead(pinSensor1) && sensor1 == HIGH && sensor2 == digitalRead(pinSensor2) && sensor2 == LOW) {
      return;
    }
  }
}

void state10B() {
  while(true) {
    int sensor1 = digitalRead(pinSensor1);
    int sensor2 = digitalRead(pinSensor2);
    displayNumber(nAutos);
    delay(50);
    
    if (sensor1 == digitalRead(pinSensor1) && sensor1 == HIGH && sensor2 == digitalRead(pinSensor2) && sensor2 == HIGH) {
      if (nAutos>0) {
        nAutos--;  
      }
      return;
    } else if (sensor1 == digitalRead(pinSensor1) && sensor1 == LOW && sensor2 == digitalRead(pinSensor2) && sensor2 == LOW) {
      return;
    }
  }
}

void subirBarrera() {
  // Con la barrera alta, LED en rojo apagada.
  digitalWrite(pinBarrier, LOW);
}

void bajarBarrera() {
  // Con la barrera baja, LED en rojo prendido.
  digitalWrite(pinBarrier, HIGH);
}

void blinkLED() {
  digitalWrite(pinBarrier, HIGH);
  delay(500);
  digitalWrite(pinBarrier, LOW);
}

void cycleDisplayNumbers () {
  int i;
  for (i=0; i<=10; i++) {
    displayNumber(i);
    delay(500);
  }
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
  digitalWrite(pinDot, LOW);
  return;
}

void displayNumber (int aux) {
  switch(aux) {
    case 0:
      display0();
      break;
    case 1:
      display1();
      break;
    case 2:
      display2();
      break;
    case 3:
      display3();
      break;      
    case 4:
      display4();
      break;
    case 5:
      display5();
      break;
    case 6:
      display6();
      break;
    case 7:
      display7();
      break;      
    case 8:
      display8();
      break;
    case 9:
      display9();
      break;
    case 10:
      displayF();
      break; 
    }
  }

void display0 () {
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, LOW);
    digitalWrite(pinDot, LOW);
}

void display1 () {
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, LOW);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, LOW);
    digitalWrite(pinG, LOW);
    digitalWrite(pinDot, LOW);
}

void display2 () {
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, LOW);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, LOW);
    digitalWrite(pinG, HIGH);
    digitalWrite(pinDot, LOW);
}

void display3 () {
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, LOW);
    digitalWrite(pinG, HIGH);
    digitalWrite(pinDot, LOW);
}

void display4 () {
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, LOW);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, HIGH);
    digitalWrite(pinDot, LOW);
}

void display5 () {
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, LOW);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, HIGH);
    digitalWrite(pinDot, LOW);
}

void display6 () {
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, LOW);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, HIGH);
    digitalWrite(pinDot, LOW);
}

void display7 () {
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, LOW);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, LOW);
    digitalWrite(pinG, LOW);
    digitalWrite(pinDot, LOW);
}

void display8 () {
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, HIGH);
    digitalWrite(pinDot, LOW);
}

void display9 () {
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, LOW);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, HIGH);
    digitalWrite(pinDot, LOW);
}

void displayF () {
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, LOW);
    digitalWrite(pinC, LOW);
    digitalWrite(pinD, LOW);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, HIGH);
    digitalWrite(pinDot, LOW);
}


void cycleDisplaySegments () {
  blinkPin(pinA);
  blinkPin(pinB);
  blinkPin(pinC);
  blinkPin(pinD);
  blinkPin(pinE);
  blinkPin(pinF);
  blinkPin(pinG);
  blinkPin(pinDot);
  return;
}

void blinkPin (const int aux) {
  digitalWrite(aux, HIGH);
  delay(250);
  digitalWrite(aux, LOW);
}
