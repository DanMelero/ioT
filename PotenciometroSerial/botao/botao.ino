int btnA = 2;
int btnB = 3;
int pot2 = A0;
int pot1 = A1;

int btnStA; 
int btnStB; 

int potValor1;
int potValor2;

String aStr = "A";
String bStr = "B";



void setup() {
  pinMode(btnA, INPUT_PULLUP);  
  pinMode(btnB, INPUT_PULLUP);  
  Serial.begin(9600);           
}

void loop() {
  btnStA = digitalRead(btnA);
  btnStB = digitalRead(btnB);

  potValor1 = analogRead(pot1);
  potValor2 = analogRead(pot2);



  if ((btnStA == LOW)){ 
    Serial.print(aStr + potValor1);
    delay(1000);                                            
  }

  if ((btnStB == LOW)){
    Serial.print(bStr + potValor2);
    delay(1000);                                            

}

}