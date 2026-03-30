# Documentación

## Entrega

La entrega se realiza vía **aula.usm.cl** en formato `.zip`.

## Multiplicación de matrices
**Algoritmos:** Naive y Strassen.

### Programa principal
El programa principal de esta seccion del proyecto consta de 2 partes.\
Primero un archivo "***matrix_multiplication.cpp***" el cual se encarga de realizar las mediciones de tiempo y memoria del algoritmo y escribir estos resultados en un archivo de texto con el nombre "***algoritmo.txt***", archivo en el cual la informacion era almacenada de la siguiente forma\
"|Tamaño entrada, Tiempo de ejecucion, Pico de memoria".

**Metodo de Uso:** ./matmul \<algoritmo> \<input_path_matrix_A> \<input_path_matrix_B>

Segundo un script de bash "***runner.sh***" el cual se encarga de recorrer el directorio que contiene las matrices de entrada y realiza una ejecucion del programa principal por cada entrada posible.

De esta forma cada par de matriz entrada cuenta con su propia ejecucion del programa principal, con el fin de disminuir lo mas posible el ruido de las respectivas mediciones.

**Realizacion de mediciones:** Para poder realizar todas las mediciones se cuenta con un archivo "***makefile***".
Archivo el cual cuenta con las instrucciones "***make***" y "***make run***", las cuales complilan el programa principal y limpian el directorio de salida de las mediciones para luego ejecutar ***runner.sh*** e iniciar la toma de datos respectivamente.

**Nota:** Para el correcto funcionamiento de estas herramientas es necesario contar con un sistema operativo tipo **Unix** ya que el programa principal hace uso del archivo de cabecera "***sys/resource.h***" para poder realizar la medicion del pico de uso de memoria del programa.

### Scripts
Programa en Python "***plot_generator.py***" el cual realiza las siguientes tareas:

**Lectura de archivos y parseo de informacion:** El script lee los archivos de texto generados por el [programa principal](#programa-principal) y almacena la informacion contenida dentro de estos en arreglos multidimencionales con el siguiente formato [[Tamaño, Tiempo, Memoria, Algoritmo], ...].

**Limpieza de informacion:** Dada la forma en la que fueron tomados los datos al momento de realizar el parseo de los datos se generaron subarreglos vacios por lo que el script igual se encarga de la limpieza de subarreglos vacios o que no cuenten con el formato esperado.

**Creacion del dataset y graficas:** Por ultimo con la informacion y tratada y con un formato estandar el script crea el dataset que sera utilizado para la creacion de los graficos haciendo uso de la libreria ***seaborn*** de Python, graficos que seran guardados en el directorio **plots** del proyecto.

**Metodo de uso y requerimientos:** Para la correcta ejecucion de este script es necesario preparar primero el directorio.

**Creacion de entorno virtual:** Primero es necesario hacer la creacion del entorno virtual de Python para poder instalar las dependencias necesarias del script.

```bash
    python -m venv venv
    source venv/bin/activate
``` 

**Instalacion de dependencias:** Luego de activar el entorno virtual debemos instalar las dependencias **matplotlib**, **pandas** y **seaborn** mediante el administrador de paquetes **pip** de Python.

```bash
    pip install seaborn
    pip install matplotlib
    pip install pandas
``` 

**Ejecucion de script:** Con esto ya podemos ejecutar el script con pyhton3.

```bash
    python3 plot_generator.py
``` 

## Ordenamiento de arreglo unidimensional

**Algoritmos:** MergeSort, QuickSort, std::sort.

### Programa principal
El programa principal de esta seccion del proyecto consta de 2 partes.\
Primero un archivo "***sorting.cpp***" el cual se encarga de realizar las mediciones de tiempo y memoria del algoritmo y escribir estos resultados en un archivo de texto con el nombre "***algoritmo.txt***", archivo en el cual la informacion era almacenada de la siguiente forma:
"|Tamaño entrada, Tiempo de ejecucion, Pico de memoria".\

**Metodo de Uso:** ./sorting \<algoritmo> \<input_path_array>

Segundo un script de bash "***runner.sh***" el cual se encarga de recorrer el directorio que contiene los arreglos de entrada y realiza una ejecucion del programa principal por cada entrada posible.

De esta forma cada arreglo de entrada cuenta con su propia ejecucion del programa principal, con el fin de disminuir lo mas posible el ruido de las respectivas mediciones.

**Realizacion de mediciones:** Para poder realizar todas las mediciones se cuenta con un archivo "***makefile***".
Archivo el cual cuenta con las instrucciones "***make***" y "***make run***", las cuales complilan el programa principal y limpian el directorio de salida de las mediciones para luego ejecutar ***runner.sh*** e iniciar la toma de datos respectivamente.

**Nota:** Para el correcto funcionamiento de estas herramientas es necesario contar con un sistema operativo tipo **Unix** ya que el programa principal hace uso del archivo de cabecera "***sys/resource.h***" para poder realizar la medicion del pico de uso de memoria del programa.



### Scripts
Programa en Python "***plot_generator.py***" el cual realiza las siguientes tareas:

**Lectura de archivos y parseo de informacion:** El script lee los archivos de texto generados por el [programa principal](#programa-principal-1) y almacena la informacion contenida dentro de estos en arreglos multidimencionales con el siguiente formato [[Tamaño, Tiempo, Memoria, Algoritmo], ...].

**Limpieza de informacion:** Dada la forma en la que fueron tomados los datos al momento de realizar el parseo de los datos se generaron subarreglos vacios por lo que el script igual se encarga de la limpieza de subarreglos vacios o que no cuenten con el formato esperado.

**Creacion del dataset y graficas:** Por ultimo con la informacion y tratada y con un formato estandar el script crea el dataset que sera utilizado para la creacion de los graficos haciendo uso de la libreria ***seaborn*** de Python, graficos que seran guardados en el directorio **plots** del proyecto.

**Metodo de uso y requerimientos:** Para la correcta ejecucion de este script es necesario preparar primero el directorio.

**Creacion de entorno virtual:** Primero es necesario hacer la creacion del entorno virtual de Python para poder instalar las dependencias necesarias del script.

```bash
    python -m venv venv
    source venv/bin/activate
``` 

**Instalacion de dependencias:** Luego de activar el entorno virtual debemos instalar las dependencias **matplotlib**, **pandas** y **seaborn** mediante el administrador de paquetes **pip** de Python.

```bash
    pip install seaborn
    pip install matplotlib
    pip install pandas
``` 

**Ejecucion de script:** Con esto ya podemos ejecutar el script con pyhton3.

```bash
    python3 plot_generator.py
``` 
