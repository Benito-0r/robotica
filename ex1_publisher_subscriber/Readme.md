# Excercise 1: publisher_subscriber

1. Caratteristiche generali dell'implementazione
2. Publisher
3. Subscriber

***

## 1. Caratteristiche generali dell'implementazione

***
Per implementare i 6 giunti è stato utilizzato un tipo di messaggio già esistente nelle librerie di ros: trajectory_msgs::JointTrajectory. Questo messaggio è formato da un vettore per i nomi dei giunti ed un vettore di JointTrajectoryPoint. Quest'ultimi al loro interno sono formati da un vettore per le posizioni ed altri vettori per le velocità accelerazioni ed altro, che in questo esercizio non vengono utilizzati (Inizializzati vuoti/ valori nulli).
Per ogni giunto vengono assegnate 5 posizioni randomiche.
***

## 2. Publisher

***
Il publisher tramite un topic nominato "motor_chatter" invierà dei messaggi formati dal nome dei giunti e dai vettori JointTrajectoryPoint. L'invio è settato ad 1 messaggio al secondo.

## 3. Subscriber

***
Il subscriber tramite un topic nominato "motor_chatter" riceverà dei messaggi, formati dal nome dei giunti e dai vettori dei punti, e li stamperà a video.
