#include <Ultrasonic.h>

HC_SR04 sensorRosa(4,5); 
HC_SR04 sensorVerde(2,3);  


int maoRosaPorta = 9; 
int maoVerdePorta = 10;

float maoVerde = sensorVerde.distance();
float maoRosa = sensorRosa.distance();

bool isXicara = false;


void setup(){

  pinMode(maoRosaPorta, OUTPUT); 
  pinMode(maoVerdePorta, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  displaySerial();

  float maoVerdeFreeze = maoVerde;
  maoVerde = sensorVerde.distance();

  isXicara = captaDistanciaXicara ();
  if (isXicara == true){
    posicao(maoRosaPorta, 90);
  }
  else{
    float maoRosaFreeze = maoRosa;
    posicao(maoRosaPorta, 0);
  }
  captaTamanhoBebida(maoVerdeFreeze, maoVerde, isXicara);
 
delay(200);
}

//compartimento
bool captaDistanciaXicara (){
  if(sensorRosa.distance() < 20){
    return true;
  }
  else{
    return false;
  }
}
  
//tamanho da bebida - OBS o tamanho Longo ou Curto só pode ser ativado se for detectado xícara
void captaTamanhoBebida (float maoVerdeFreeze, float maoVerde, bool isXicara) {
 if(isXicara == true){
  if(maoVerdeFreeze != maoVerde){
    if(sensorVerde.distance() < 30){
      posicao(maoVerdePorta, 0);
      delay(2000);
      posicao(maoVerdePorta, 90);
     
    }
    else{
      posicao(maoVerdePorta, 180);
      delay(1000);
      posicao(maoVerdePorta, 90);

    }
  }
 }
}

void displaySerial(){
  Serial.println(String("Distancia xicara: ") + sensorRosa.distance() +String(" cm"));
  Serial.println(String("Distancia tamanho: ") + sensorVerde.distance() +String(" cm"));
}

void posicao(int servo, int posicao){
  int microPulso = map(posicao,0,180,1000,2000);
  digitalWrite(servo, HIGH);
  delayMicroseconds(microPulso);
  digitalWrite(servo, LOW);
  delay(10);                   
}

