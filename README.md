# Alcoholímetro con Arduino

Este repositorio contiene el proyecto escolar de un **alcoholímetro** con arduino con el sensor de alcohol Ethanol Mq-3 como parte del trabajo final de la materoa de Arquitectura de Computadoras II.

# Funcionamiento general

Mediante el sensor de alcohol Ethanol Mq-3, el sistema detecta el nivel de alcohol en el aire, en caso de que se supere el umbral permitdo, inicia la alarma activando el buzzer, encendiendo el led rojo y escribiendo en la pantalla el mensaje: "Borracho"

## Componentes

Los componentes que utiliza el proyecto son: 

- Arduino Uno
- Protoboard
- Sensor de Alcohol Ethanol Mq-3
- 1 Led rojo y 1 Led Verde
- 2 Resistencias de 220 Ohms
- 1 Buzzer
- 1 Pantalla LCD 16x2
- Variedad de cables (MH,MM)

## Despliegue

Para el despliegue, es necesario montar el circuito como se muestra en el diagrama que se encuentra en el repositorio, y conectarlo mediante una cable de transmisión de datos a una computadora. Dentro del IDE de Arduino, es necesario instalar las librerías de "Wire" y "LiquidCrystal_I2C" para que funcione correctamente la pantalla LCD. Una vez hecho eso, solo es correr el código y el proyecto estará funcionando.

>**Nota:** Es posible cambiar las conexiones del diagrama siempre y cuando también cambies su contra parte en las declaraciones de variables del código