import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
from pathlib import Path

rootDir = Path(__file__).resolve().parent.parent


aux = []


def fixData(data, algo):
    for row in data:
        if len(row) == 3:
            aux.append([int(row[0]), int(row[1]), int(row[2]), algo])


def buildPlots(path, tittle, xVar, yVar, yLabel, df):
    plt.figure(figsize=(12, 6))
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
    ax.set_xscale("log", base=2)
    ax.set_yscale("log")
    plt.savefig(path)
    plt.close()


def buildBarPlot(path, xVar, xLabel, yVar, yLabel, df):
    plt.figure()
    ax = sns.barplot(data=df, x=xVar, y=yVar, palette="flare", hue=xVar)
    ax.set_xlabel(xLabel)
    ax.set_ylabel(yLabel)
    plt.savefig(path)
    plt.close()


strassenDataPath = rootDir / "data" / "measurements" / "s.txt"
naiveDataPath = rootDir / "data" / "measurements" / "n.txt"

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
sns.set_style("darkgrid")

# Creacion de los graficos
buildPlots(
    rootDir / "data" / "plots" / "sizeVStime.png",
    "Tamaño vs Tiempo",
    "size",
    "time",
    "Tiempo [ns]",
    df,
)
buildPlots(
    rootDir / "data" / "plots" / "sizeVSmemory.png",
    "Tamaño vs Memoria",
    "size",
    "memory",
    "Memoria [kb]",
    df,
)

# Creacion de graficos de barra
buildBarPlot(
    rootDir / "data" / "plots" / "time.png",
    "algorithm",
    "Algoritmo",
    "time",
    "Tiempo [ns]",
    df,
)
buildBarPlot(
    rootDir / "data" / "plots" / "memory.png",
    "algorithm",
    "Algoritmo",
    "memory",
    "Memoria [kb]",
    df,
)

# Creacion de tablas de datos
dataTimeTable = (
    df.groupby(["size", "algorithm"])["time"]
    .agg(mean="mean", std="std", count="count")
    .reset_index()
)

dataMemTable = (
    df.groupby(["size", "algorithm"])["memory"]
    .agg(mean="mean", std="std", count="count")
    .reset_index()
)

print("Tiempo")
print(dataTimeTable.to_latex())

print("Memoria")
print(dataMemTable.to_latex())
