# publisher_subscriber_msgs


## 1.Caratteristiche generali dell'implementazione
***
Questo pacchetto implementa un messaggio formato principalmente da due messaggi. Il primo messaggio, InfoJoint è caratterizzato da un vettore di float e rapprensenta il vettore di positions di un qualsiasi giunto. Il messaggio da mandare invece è chiamato JointCustomMsg ed è formato da un vettore di stringhe che permette di assegnare dei nomi ai giunti e da un vettore di InfoJoint in modo da avere per ogni giunto un vettore di positions.