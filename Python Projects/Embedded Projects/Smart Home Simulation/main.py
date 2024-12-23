'''
            Sensordatensimulation und einfache Datenverarbeitung

***************************** Projektbeschreibung ****************************** 
    Simuliere einen Sensor, der Temperaturwerte ausgibt, und schreibe eine 
    einfache Funktion, die diese Werte verarbeitet.
********************************************************************************

ToDo: 
    - Anzeigen von Max und Min Werten des Sensors
    - Durchschnittstemperatur
    - y-werte sind aktuell durcheinander
'''
# Imports ----------------------------------------------------------------------
import random
import time
import matplotlib.pyplot as plt
import numpy as np
import csv
import pandas as pd


# Class Sensor -----------------------------------------------------------------

class Sensor:
    def __init__(self):
        # Starting value
        self.previous_temp_value = 25


    def createData(self):
        temp_value = random.randint(20, 80)

        return temp_value


    def filterData(self, _temp_value):
        if self.previous_temp_value > _temp_value:
            if (self.previous_temp_value - _temp_value) > 2:
                _temp_value = self.previous_temp_value - 2
        elif (self.previous_temp_value < _temp_value):
            if (self.previous_temp_value + _temp_value) > 2:
                _temp_value = self.previous_temp_value + 2
                
        self.previous_temp_value = _temp_value

        return _temp_value


    def getData(self):
        sensor_temp = self.createData()
        sensor_temp = self.filterData(sensor_temp)

        return sensor_temp


    def storeData(self, _temp_value, _timer):
        row = [_temp_value, _timer]

        with open("SensorData.csv", "a", newline="") as csvfile:
            writer = csv.writer(csvfile)
            writer.writerow(row)

# Class Ui ---------------------------------------------------------------------

class Ui:
    def __init__(self):
        self.temp_data_array = []
        self.time_data_array = []


    def plotData(self):
        # Load the data
        df = pd.read_csv("SensorData.csv")

        # Apply a moving average on the temperature data
        df["Smoothed_Temperatur"] = df["Temperatur"].rolling(window=50, min_periods=1).mean()

        # Plot time on the x-axis and the smoothed temperature on the y-axis
        plt.plot(df["Time"], df["Smoothed_Temperatur"], label="Smoothed Temperature over Time")
        plt.xlabel("Time")
        plt.ylabel("Temperature")
        plt.legend()
        plt.show()



if __name__ == "__main__":
    sensor = Sensor()
    ui = Ui()

    header = ["Temperatur", "Time"]
    timer = 0

    with open("SensorData.csv", "w", newline="") as csvfile:
        writer = csv.writer(csvfile)
        writer.writerow(header)

    # Mainloop
    for i in range(1000):
        sensor_temperature = sensor.getData()
        # time.sleep(0.2)
        timer = round(timer, 1)
        sensor.storeData(sensor_temperature, timer)
        timer += 0.2

    ui.plotData()