# publisher_subscriber_custom

1. Caratteristiche generali dell'implementazione
2. Publisher
3. Subscriber

***

## 1. Caratteristiche generali dell'implementazione

***
Per implementare i 6 giunti è stato utilizzato un tipo di messaggio customizzato che si trova all'interno del package publisher_subscriber_msgs. Questo messaggio è formato da un vettore per i nomi dei giunti ed un vettore di InfoJoint. Quest'ultimo al suo interno è formato da un vettore per le posizioni.
Per ogni giunto vengono assegnate 5 posizioni randomiche.
***

## 2. Publisher

***
Il publisher tramite un topic nominato "motor_chatter" invierà dei messaggi formati dal nome dei giunti e dai vettori InfoJoint. L'invio è settato ad 1 messaggio al secondo.

## 3. Subscriber

***
Il subscriber tramite un topic nominato "motor_chatter" riceverà dei messaggi, formati dal nome dei giunti e dai vettori delle positions, e li stamperà a video.
