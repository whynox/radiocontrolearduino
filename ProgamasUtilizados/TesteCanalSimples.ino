/* --------------------------------------------------------------------------------- */
/* Esse programa foi usado para ler os canais e capturar a duração exata dos pulsos  */ 
/* de ambos canais. Sendo o canal 01 para direção e o canal 02 para aceleração.      */
/* Podendo ser implementado no código principal, porém tomar cuidado com o delay que */
/* irá interferir no tempo de resposta da aceleração e da direção.                   */
/* Se for usado no código principal o ideal é deixar as funções e o delay como       */ 
/* comentário e usar somente quando for necessário.                                  */  
/* --------------------------------------------------------------------------------- */

/* --- DECLARAÇÃO DE PINOS --- */

#define ch1 5
#define ch2 3

/* --- DECLARAÇÃO DE VARIÁVEIS DOS CANAIS --- */

int canal_01, canal_02;

void setup() {
     pinMode(ch1, INPUT); //Entrada para o canal 3 do rádio
     pinMode(ch2, INPUT); //Entrada para o canal 5 do rádio
}

void loop() {
     LeitorDeCanais();
     TesteDeCanais();

     delay (500);
}
void LeitorDeCanais() { // Faz a leitura dos canais ativos do rádio.

     canal_01 = pulseIn (ch1, HIGH, 25000); //MAXIMO DE TEMPO QUE ELE ESPERA PRO EVENTO OCORRER 25000 microsegundos.                    
     canal_02 = pulseIn (ch2, HIGH, 25000); //25000 microsegundos -> 25 milisegundos, 0,0025s; vem 1 segundo por padrão.  
       
}
void TesteDeCanais() { // Testa os canais via serial monitor
     Serial.println("=================");
     Serial.print("Canal 01:  ");
     Serial.println(canal_01);
     Serial.print("Canal 02:  ");
     Serial.println(canal_02); 
}
