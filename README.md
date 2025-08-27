# 🍝 philosophers

**philosophers** es un proyecto de [42 School](https://42.fr) cuyo objetivo es simular el clásico **problema de los filósofos comensales**.  
El reto consiste en gestionar correctamente múltiples procesos o hilos que compiten por recursos limitados (los tenedores), evitando **condiciones de carrera**, **interbloqueos** y **hambre**.


## 🧠 Objetivos del Proyecto

- Comprender problemas de concurrencia y sincronización en sistemas.  
- Aprender a trabajar con **threads** (`pthread`) y **mutex**.  
- Evitar **deadlocks** y garantizar que ningún filósofo muera de inanición.  
- Gestionar correctamente el tiempo (pensar, comer, dormir).  
- Reforzar la importancia de la programación determinista y segura en entornos paralelos.  


## ✅ Funcionalidades Implementadas

- Simulación del comportamiento de cada filósofo como un **thread independiente**.  
- Uso de **mutex** para proteger los recursos (tenedores).  
- Control de tiempos:  
  - `time_to_die` → tiempo máximo que un filósofo puede estar sin comer.  
  - `time_to_eat` → tiempo que tarda en comer.  
  - `time_to_sleep` → tiempo que tarda en dormir.  
- Gestión de estado: pensar → comer → dormir → repetir.  
- Detección de la muerte de un filósofo y finalización de la simulación.  
- Opción de configurar el número de veces que debe comer cada filósofo.  


## 🛠️ Ejecución

Compilar el programa con:
```
make
```
Ejecutar la simulación:
```
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```
Ejemplo:
```
./philo 5 800 200 200
```
📌 Simula 5 filósofos, cada uno muere si pasa 800 ms sin comer, tardan 200 ms en comer y 200 ms en dormir.

Ejemplo con número de comidas:
```
./philo 5 800 200 200 7
```
📌 La simulación termina cuando cada filósofo ha comido 7 veces.
