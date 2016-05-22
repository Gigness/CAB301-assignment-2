import pandas as pd
import numpy as np
import matplotlib.pyplot as plt


# ----------------------------------------------------------------------------------------------------------------------


df = pd.read_csv("data_2500_35000_2500_25.csv")
print df.head()

df.to_csv("test.csv")

# mean data
inputs = df["n"].unique().tolist()
mean_ops_brute = []
mean_time_brute = []
mean_ops_median = []
mean_time_median = []

# normalised data
inputs_normalized = []
mean_ops_brute_normalised = []
mean_time_brute_normalised = []
mean_ops_median_normalised = []
mean_time_median_normalised = []


# calc mean
for n in inputs:
    ops_median = df["operations_median"][df["n"] == n]
    mean_ops_median.append(ops_median.mean())
    
    time_median = df["time_median"][df["n"] == n]
    mean_time_median.append(time_median.mean())
    
    ops_brute = df["operations_brute"][df["n"] == n]
    mean_ops_brute.append(ops_brute.mean())
    
    time_brute = df["time_brute"][df["n"] == n]
    mean_time_brute.append(time_brute.mean())

# perform normalisation
for i in xrange(len(inputs)):
    inputs_normalized.append(float(inputs[i])/max(inputs))
    mean_ops_brute_normalised.append(mean_ops_brute[i]/max(mean_ops_brute))
    mean_time_brute_normalised.append(mean_time_brute[i]/max(mean_time_brute))
    mean_ops_median_normalised.append(mean_ops_median[i]/max(mean_ops_median))
    mean_time_median_normalised.append(mean_time_median[i]/max(mean_time_median))


# generate expected results
theoretical_input = np.linspace(0, 1, 100)
theoretical_output_brute = [n*n for n in theoretical_input]
theoretical_output_median = [n for n in theoretical_input]
# ----------------------------------------------------------------------------------------------------------------------


def grouped_plots():
    # mean plots
    plt.figure()
    plt.subplot(221)
    plt.plot(inputs, mean_ops_brute)
    plt.subplot(222)
    plt.plot(inputs, mean_time_brute)
    plt.subplot(223)
    plt.plot(inputs, mean_ops_median)
    plt.subplot(224)
    plt.plot(inputs, mean_time_median)

    # original plots
    plt.figure()
    plt.subplot(221)
    plt.scatter(df["n"], df["operations_brute"])
    plt.subplot(222)
    plt.scatter(df["n"], df["time_brute"])
    plt.subplot(223)
    plt.scatter(df["n"], df["operations_median"])
    plt.subplot(224)
    plt.scatter(df["n"], df["time_median"])
    plt.axis((0, 35000, 0, 0.0025))

    # normalised plots
    plt.figure()
    plt.subplot(221)
    plt.plot(inputs_normalized, mean_ops_brute_normalised)
    plt.subplot(222)
    plt.plot(inputs_normalized, mean_time_brute_normalised)
    plt.subplot(223)
    plt.plot(inputs_normalized, mean_ops_median_normalised)
    plt.subplot(224)
    plt.plot(inputs_normalized, mean_time_median_normalised)
    plt.axis((0, 1, 0, 1))
    plt.show()


def bfm_norm_plots():
    plt.figure()
    plt.hold(True)
    plt.plot(inputs_normalized, mean_ops_brute_normalised, label='experimental')
    plt.plot(theoretical_input, theoretical_output_brute, label='theoretical', color='r')
    plt.legend(loc='upper left')
    plt.title("Brute Force Median: Normalised Operations with Theoretical Expectation")

    plt.figure()
    plt.hold(True)
    plt.plot(inputs_normalized, mean_time_brute_normalised, label='experimental')
    plt.plot(theoretical_input, theoretical_output_brute, label='theoretical', color='r')
    plt.legend(loc='upper left')
    plt.title("Brute Force Median: Normalised Time with Theoretical Expectation")
    plt.show()
    

def m_norm_plots():
    plt.figure()
    plt.hold(True)
    plt.plot(inputs_normalized, mean_ops_median_normalised, label='experimental')
    plt.plot(theoretical_input, theoretical_output_median, label='theoretical', color='r')
    plt.legend(loc='upper left')
    plt.title("Median: Normalised Operations with Theoretical Expectation")

    plt.figure()
    plt.hold(True)
    plt.plot(inputs_normalized, mean_time_median_normalised, label='experimental')
    plt.plot(theoretical_input, theoretical_output_median, label='theoretical', color='r')
    plt.legend(loc='upper left')
    plt.title("Median: Normalised Time with Theoretical Expectation")
    plt.show()


def m_mean_plots():
    plt.figure()
    plt.plot(inputs, mean_ops_brute, label='Mean Ops')
    plt.title("Brute Force Median: Mean Operations")

    plt.figure()
    plt.plot(inputs, mean_time_brute, label='Mean Time')
    plt.title("Brute Force Median: Mean Time")

    plt.show()


def bfm_mean_plots():
    plt.figure()
    plt.plot(inputs, mean_ops_median, label="Mean Ops")
    plt.title("Median: Mean Operations")

    plt.figure()
    plt.plot(inputs, mean_time_median, label="Mean Time")
    plt.title("Median: Mean Time")

    plt.show()


def raw_data_plots():
    plt.figure()
    plt.scatter(df["n"], df["operations_median"], label="Operations")
    plt.title("Median: Operations Data")
    plt.axis((0, 37500, -10000, 175000))

    plt.figure()
    plt.scatter(df["n"], df["time_median"], label="Operations")
    plt.title("Median: Time Data")
    plt.axis((0, 37500, -0.0005, 0.003))

    plt.figure()
    plt.scatter(df["n"], df["operations_brute"], label="Operations")
    plt.title("Brute Force Median: Operations Data")


    plt.figure()
    plt.scatter(df["n"], df["time_brute"], label="Operations")
    plt.title("Brute Force Median: Time Data")
    plt.axis((0, 37500, -1, 12))

    plt.show()


raw_data_plots()

bfm_norm_plots()

m_norm_plots()

grouped_plots()
