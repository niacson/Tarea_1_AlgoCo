import numpy as np
import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt

rootDir = (
    "/home/ignacio/Downloads/tarea-1-algoco/template-tarea-1/code/sorting/data/{}/{}"
)


def fixData(data):
    aux = []
    for row in data:
        if len(row) == 3:
            aux.append([int(row[0]), int(row[1]), int(row[2])])
    aux.sort()
    return np.array(aux)


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

# Creacion de los dataframes para realizar plots
sortDF = pd.DataFrame(fixData(sortData), columns=["size", "time", "memory"])
mergeDF = pd.DataFrame(fixData(mergeData), columns=["size", "time", "memory"])
quickDF = pd.DataFrame(fixData(quickData), columns=["size", "time", "memory"])

ax = sns.lineplot(data=quickDF, x="size", y="time")
ax.set_xscale("log")
ax.set_yscale("log")
plt.savefig(rootDir.format("plots", "prueba.png"))
