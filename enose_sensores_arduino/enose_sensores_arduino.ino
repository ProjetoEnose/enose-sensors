////////////////////////VARIÁVEIS//////////////////////////////
//////////////////////////////////////////////////////////////

// Pinos analógicos dos sensores MQ
const int mq3Pin = A0; 
const int mq5Pin = A1;

float mediaValoresLidosMQ3 = 0;
float acumuladosMQ3 = 0;

float mediaValoresLidosMQ5 = 0;
float acumuladosMQ5 = 0;

int tempo = 5; //tempo em segundos para o registro de dados
int espera = 0; //Tempo em segundos para delay
float valoresLidosMQ3[5];
float valoresLidosMQ5[5];

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

void setup() {
  Serial.begin(115200); 
}


void loop() {
  if(espera == 900){ 
    lerSensores();
    String mensagem = String(mediaValoresLidosMQ3) + "-" + String(mediaValoresLidosMQ5);
    Serial.println(mensagem);
    espera = 0;
  }
  
  delay(1000); 
  espera++;
}

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

void lerSensores(){
  for (int i=0; i<tempo; i++) {
    int leituraMQ3 = analogRead(mq3Pin);
    int leituraMQ5 = analogRead(mq5Pin);

    float valorSensorMQ3 = (leituraMQ3 * 100.0) / 1024.0; 
    float valorSensorMQ5 = (leituraMQ5 * 100.0) / 1024.0;  

    valoresLidosMQ3[i] = valorSensorMQ3;  
    valoresLidosMQ5[i] = valorSensorMQ5;   
    delay(1000);
  }

  for (byte i=0; i<tempo; i++) {
    acumuladosMQ3 += valoresLidosMQ3[i];
    acumuladosMQ5 += valoresLidosMQ5[i];
  }

  mediaValoresLidosMQ3 = acumuladosMQ3 / tempo;
  mediaValoresLidosMQ5 = acumuladosMQ5 / tempo;

  acumuladosMQ3 = 0;
  acumuladosMQ5 = 0;
}