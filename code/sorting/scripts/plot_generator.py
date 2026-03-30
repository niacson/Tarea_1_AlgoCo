import numpy as np
import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt

rootDir = (
    "/home/ignacio/Downloads/tarea-1-algoco/template-tarea-1/code/sorting/data/{}/{}"
)


aux = []


def fixData(data, algo):
    for row in data:
        if len(row) == 3:
            aux.append([int(row[0]), int(row[1]), int(row[2]), algo])


def buildPlots(path, xVar, yVar, df):
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
    ax.set_xscale("log")
    ax.set_yscale("log")
    plt.savefig(path)
    plt.close()


sortDataPath = rootDir.format("measurements", "s.txt")
mergeDataPath = rootDir.format("measurements", "m.txt")
quickDataPath = rootDir.format("measurements", "q.txt")

rawSortData = open(sortDataPath, "r")
rawMergeData = open(mergeDataPath, "r")
rawQuickData = open(quickDataPath, "r")

# Formato de la informacion: [[size, duration, memory], ..]
sortData = [row.split(",") for row in rawSortData.read().split("|")]
mergeData = [row.split(",") for row in rawMergeData.read().split("|")]
quickData = [row.split(",") for row in rawQuickData.read().split("|")]

# Eliminacion de filas vacias
fixData(sortData, "sort")
fixData(mergeData, "merge")
fixData(quickData, "quick")

# Creacion del dataframe a partir de datos arreglados
df = pd.DataFrame(aux, columns=["size", "time", "memory", "algorithm"])
df.sort_values("size")

# Setteo para usar cuadricula
sns.set_style("whitegrid")

# Creacion de los graficos
buildPlots(rootDir.format("plots", "sizeVStime"), "size", "time", df)
buildPlots(rootDir.format("plots", "sizeVSmemory"), "size", "memory", df)
