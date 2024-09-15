# Código onde é feita a leitura dos sensores pelo Arduino

Os sensores são lidos através da função "lerSensores()".

## lerSensores()
Os sensores são lidos durante um minuto, armazenando 60 valores diferentes em arrays para cada sensor. Após isso, os valores são somados e divididos pelo tempo para conseguir uma média do valor para cada sensor. Esses dados obtidos são enviados para o ESP32 através de comunicação serial.

Após cada mensagem enviada para o ESP, o Arduino espera 15 minutos para realizar outra coleta e envio. O tempo de espera é definido, em segundos, pela variável "espera".

* Variáveis para os pinos analógicos dos sensores:
  - mq3Pin
  - mq5Pin
    
  Através dessas variáveis é definido, no código, a porta analógica em que os sensores estão conectados no Arduino para a leitura dos dados.

* mediaValoresLidosMQ
  * Guarda a média dos valores lidos dos sensores.

* acumuladosMQ
  * Acumula os valores lidos durante 1 minuto para o cálculo da média.

 * valoresLidosMQ[60]
   * Guarda as leituras do sensor para o cálculo da média.





























  
