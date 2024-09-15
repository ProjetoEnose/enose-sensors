from websocket_server import WebsocketServer
import MySQLdb

mq3 = 0
porcentmq3 = 0
mq5 = 0
porcentmq5 = 0

con = MySQLdb.connect("localhost", "root", "", "websocket")



# Função chamada quando um novo cliente se conecta
def new_client(client, server):
    print(f"Cliente {client['id']} conectado")

# Função chamada quando uma mensagem é recebida 
def message_received(client, server, message):
    sensor_values = message.split("-")

    mq3 = float(sensor_values[0])  
    mq5 = float(sensor_values[1])

    porcentmq3 = (mq3 * 100.0) / 1024.0
    porcentmq5 = (mq5 * 100.0) / 1024.0

    print("Valor MQ-3: "+str(mq3))
    print("% MQ-5: "+str(porcentmq3))
    
    print("Valor MQ-5: "+str(mq5))
    print("% MQ-5: "+str(porcentmq5))
    print("")

    try:
        cursor = con.cursor()  # Inicia um cursor do banco de dados
        cursor.execute("INSERT INTO sensor(MQ3, MQ5, PORCENT_MQ3,PORCENT_MQ5) VALUES(%s, %s, %s, %s)", (mq3,mq5,porcentmq3,porcentmq5))  # Comando para inserir valores no banco
        con.commit()  # Executa o comando do banco de dados
    except MySQLdb.IntegrityError:
        print("Falha ao inserir valores no banco de dados.")
    finally:
        cursor.close()
    
    server.send_message(client, "Mensagem recebida com sucesso")

# Criação do servidor WebSocket
server = WebsocketServer(host='<Endereço IP>', port=8765)
server.set_fn_new_client(new_client)
server.set_fn_message_received(message_received)

print("Servidor WebSocket iniciado...")



server.run_forever()