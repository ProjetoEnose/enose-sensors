# Código para o ESP32

Responsável por coletar os dados do arduino e enviál-los para o servidor Websocket responsável por gravá-los no banco de dados.<br>
É necessário informar o id e a senha da rede wifi e o endereço ip e porta do servidor Websocket.<br>
Com as conexões feitas, o ESP recebera as informações do Arduino via comunicação serial e enviará para o servidor logo em seguida.

## WebsocketsClient

É utilizada a biblioteca <WebSocketsClient.h>, disponível em https://github.com/Links2004/arduinoWebSockets.
