CREATE DATABASE websocket;
USE websocket;

CREATE TABLE sensor(
	MQ3 FLOAT,
	MQ5 FLOAT,
	HORA TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP
);

SELECT * FROM sensor;

#DELETE FROM sensor;
#DROP DATABASE websocket;
