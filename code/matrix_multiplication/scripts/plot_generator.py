import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt

rootDir = "/home/ignacio/Downloads/tarea-1-algoco/template-tarea-1/code/matrix_multiplication/data/{}/{}"


aux = []


def fixData(data, algo):
    for row in data:
        if len(row) == 3:
            aux.append([int(row[0]), int(row[1]), int(row[2]), algo])


def buildPlots(path, tittle, xVar, yVar, yLabel, df):
    plt.figure()
    ax = sns.lineplot(
        data=df,
        x=xVar,
        y=yVar,
        hue="algorithm",
        estimator="mean",
        style="algorithm",
        markers=True,
        dashes=False,
        palette="flare",
    )
    ax.set_xlabel("Tamaño")
    ax.set_ylabel(yLabel)
    ax.set_title(tittle)
    plt.savefig(path)
    plt.close()


strassenDataPath = rootDir.format("measurements", "s.txt")
naiveDataPath = rootDir.format("measurements", "n.txt")

rawStrassenData = open(strassenDataPath, "r")
rawNaiveData = open(naiveDataPath, "r")

# Formato de la informacion: [[size, duration, memory], ..]
strassenData = [row.split(",") for row in rawStrassenData.read().split("|")]
naiveData = [row.split(",") for row in rawNaiveData.read().split("|")]

# Eliminacion de filas vacias
fixData(strassenData, "strassen")
fixData(naiveData, "naive")

# Creacion del dataframe a partir de datos arreglados
df = pd.DataFrame(aux, columns=["size", "time", "memory", "algorithm"])
df.sort_values("size")

# Setteo para usar cuadricula
sns.set_style("whitegrid")

# Creacion de los graficos
buildPlots(
    rootDir.format("plots", "sizeVStime"),
    "Tamaño vs Tiempo",
    "size",
    "time",
    "Tiempo [ns]",
    df,
)
buildPlots(
    rootDir.format("plots", "sizeVSmemory"),
    "Tamaño vs Memoria",
    "size",
    "memory",
    "Memoria [kb]",
    df,
)
