# Armado del circuito:

En el programa están definidos qué número de pin es cada cosa (segmento, botón, LED de barrera).
El número de PIN coincide con el número de pin digital. Por ejemplo, el pin 4 es el D4 del Arduino.

Para pin del display correspondiente a un segmento, poner un resistor de 220, si no se quema.
El display tiene 2 pines para tierra, con conectar uno solo alcanza.

Para el LED que simula la barrera también poner un resistor de 220.

Los pulsadores se conectan entre el pin del Arduino y a tierra.

Por las dudas, las pistas del protoboard de tierra (la azul que está al costado) a veces
están partidas en dos. Es decir, hay que conectar manualmente una mitad azul del protoboard
con la otra (estando las dos azules del mismo lado). En la foto que subí se ve que atrás
de los cables hay un cablecito re chiquito negro que hace eso. 
