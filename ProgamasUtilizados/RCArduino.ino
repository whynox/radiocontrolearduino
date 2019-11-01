/* Parte para a definição dos pinos da Ponte H e dos canais do receptor */

#define pinIN1 11
#define pinIN2 10
#define pinIN3 9
#define pinIN4 6
#define ch1 5
#define ch2 3

/*  Parte utilizada para declarar as variáveis */

/* variáveis para a modulação da direção do robô. */
int pDireita = 100;
int pEsquerda = 100;

/* variáveis feitas para receber o pulso dos canais do receptor */
int duracao1;
int duracao2;

/*Variáveis criadas para bloquear ou liberar parte do código quando necessário */
int acionador = 0;

void setup() {

  pinMode(pinIN1, OUTPUT);
  pinMode(pinIN2, OUTPUT);
  pinMode(pinIN3, OUTPUT);
  pinMode(pinIN4, OUTPUT);
  pinMode(ch1, INPUT);
  pinMode(ch2, INPUT);
}

void loop() {

  duracao1 = pulseInLong(ch1, HIGH, 25000);
  duracao2 = pulseInLong(ch2, HIGH, 25000);

  if (duracao1 != 0) {

    acionador = 1;
  }

  if (acionador == 1) {

    if (((duracao1 == 0) && (duracao2 != 0)) || ((duracao2 == 0) && (duracao1 != 0))) {

      digitalWrite(pinIN1, HIGH);
      digitalWrite(pinIN2, HIGH);
      digitalWrite(pinIN3, HIGH);
      digitalWrite(pinIN4, HIGH);

    } else {

      duracao1 = constrain(duracao1, 1000, 2000);
      duracao2 = constrain(duracao2, 1000, 2000);

      if (duracao1 > 1520) {
        // Direita                                                                                                                                                                                          

        pDireita = map(duracao1, 1520, 2000, 100, 0);
        pEsquerda = 100;
        
      } else if (duracao1 < 1460) {
        // Esquerda                                                                                          

        pDireita = 100;
        pEsquerda = map(duracao1, 1460, 1000, 100, 0);
 
      }
      if (duracao2 > 1535) {
        // Frente                                           

        int velocidade = map(duracao2, 1535, 2000, 0, 255);

        analogWrite(pinIN2, velocidade * pDireita / 100);
        analogWrite(pinIN1, 0);

        analogWrite(pinIN3, velocidade * pEsquerda / 100);
        analogWrite(pinIN4, 0);

      } else if (duracao2 < 1485) {
        // Trás

        int velocidade = map(duracao2, 1485, 1000, 0, 255);

        analogWrite(pinIN2, 0);
        analogWrite(pinIN1, velocidade * pDireita / 100);

        analogWrite(pinIN3, 0);
        analogWrite(pinIN4, velocidade * pEsquerda / 100);       
      }
    }
  }
}
