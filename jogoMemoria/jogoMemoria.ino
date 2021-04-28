
String a;
String dificuldade;
String resposta;
int tempo;
int gap;
bool iniciarJogo = false;
bool entrada = true;
bool demo, resp, pA, gameOver = false;


void setup(){
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  Serial.begin(9600);
  }


void loop(){
  if(entrada == true){
  Serial.println("Digite S para iniciar o jogo e N para sair: ");
  while(Serial.available()==0){}
  a = Serial.readString();
    if(a.equalsIgnoreCase("s")){
        iniciarJogo = true;
        entrada = false;
      }
    else{
      while(a.equalsIgnoreCase("n")){
        Serial.println("Game over!!");
        }
      }
    }
  int cont = 0;
  int i = 0;
 if(iniciarJogo == true){
    Serial.println("Escolha o nivel de dificuldade de 1 a 9: ");
    while(Serial.available()==0){}
    dificuldade = Serial.readString();
    iniciarJogo == false;
    }
  switch(dificuldade.toInt()){
    case 1:
      i = 3;
      gap = 1000;
      tempo = 10;
      break;
    case 2:
      i = 3;
      gap = 800;
      tempo = 9;
      break;
    case 3:
      i = 4;
      gap = 700;
      tempo = 8;
      break;
    case 4:
      i = 4;
      gap = 600;
      tempo = 7;
      break;
    case 5:
      i = 5;
      gap = 500;
      tempo = 7;
      break;  
    case 6:
      i = 5;
      gap = 400;
      tempo = 6;
      break;
    case 7:
      i = 6;
      gap = 300;
      tempo = 6;
      break;
    case 8:
      i = 6;
      gap = 250;
      tempo = 6;
      break;
    case 9:
      i = 7;
      tempo = 5;
      gap = 200;
      break;
    }

  int sequencia[i];
  while (cont < i){
    sequencia[cont] = random(8, 11);
    digitalWrite(sequencia[cont], HIGH);
    delay(gap);
    digitalWrite(sequencia[cont], LOW);
    cont = cont + 1;
    delay(gap);
    }
    
  String seqStr = "";
  for (int y = 0; y < i; y++){
    if(sequencia[y] == 8){
    seqStr = seqStr + "1";
    }
  else if(sequencia[y] == 9){
    seqStr = seqStr + "2";
    }
  else if(sequencia[y] == 10){
    seqStr = seqStr + "3";
    }
    demo = true;
  }

  if (seqStr != ""){
    demo = true;
    }
  
  if(demo == true){
    contarTempo(tempo);
    resposta = Serial.readString();
    demo = false;
    resp = true;
  }
  if(resp == true){
    if(seqStr == resposta){
      Serial.println("Resposta correta!");
      pA = true;
      }
    else{
      Serial.println("Resposta errada! Tente novamente!");
      resp = false;
      pA= true;
    }
  }
  if(pA == true){
  Serial.println("Quer jogar de novo? S para SIM e N para NAO");
  while(Serial.available() == 0){}
  String playAgain = Serial.readString();
  if(playAgain.equalsIgnoreCase("s") && pA == true){
    iniciarJogo = true;
    pA == false;
    }
  else{
    while(playAgain.equalsIgnoreCase("n") && pA == true){
      Serial.println("Game over!!");
    }
  }
}
 
  delay(100);
}


void contarTempo(int tempo){
  Serial.println("Digite a sequencia das cores de acordo com os numeros");
  Serial.println(" ");
  int contTempo = 1;
  Serial.print("Tempo restante para a resposta: ");
  while (contTempo < tempo){
    tempo--;
    delay(1000);
    Serial.println(tempo);
  }
}




