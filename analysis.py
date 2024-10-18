import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

# Read the data from the CSV file
data = pd.read_csv("/home/dark-zone/Codeing Zone/cv/Data.csv", names=["Size", "Time", "Swaps", "Comparisons", "Pivot"])

# Separate data based on pivot choice and drop duplicates based on 'Size'
first_pivot = data[data["Pivot"] == 'F'].drop_duplicates(subset="Size").set_index("Size")
middle_pivot = data[data["Pivot"] == 'M'].drop_duplicates(subset="Size").set_index("Size")
last_pivot = data[data["Pivot"] == 'E'].drop_duplicates(subset="Size").set_index("Size")

# Merge the dataframes on the 'Size' index to ensure all have the same size data
merged_data = pd.concat([first_pivot, middle_pivot, last_pivot], axis=1, keys=['F', 'M', 'E'], sort=False)

# Set the bar width
bar_width = 0.25

# Set positions of bars on the x-axis
r1 = np.arange(len(merged_data.index))
r2 = [x + bar_width for x in r1]
r3 = [x + bar_width for x in r2]

# Create a figure with 3 subplots (1 row, 3 columns)
fig, axes = plt.subplots(1, 3, figsize=(18, 6))

# Plot comparisons for each pivot choice as a bar chart
axes[0].bar(r1, merged_data['F', 'Comparisons'], color='b', width=bar_width, label="First Pivot")
axes[0].bar(r2, merged_data['M', 'Comparisons'], color='g', width=bar_width, label="Middle Pivot")
axes[0].bar(r3, merged_data['E', 'Comparisons'], color='r', width=bar_width, label="Last Pivot")
axes[0].set_title("Comparisons vs Array Size")
axes[0].set_xlabel("Array Size")
axes[0].set_ylabel("Number of Comparisons")
axes[0].set_xticks([r + bar_width for r in range(len(merged_data.index))])
axes[0].set_xticklabels(merged_data.index)
axes[0].legend()
axes[0].grid(True)

# Plot swaps for each pivot choice as a bar chart
axes[1].bar(r1, merged_data['F', 'Swaps'], color='b', width=bar_width, label="First Pivot")
axes[1].bar(r2, merged_data['M', 'Swaps'], color='g', width=bar_width, label="Middle Pivot")
axes[1].bar(r3, merged_data['E', 'Swaps'], color='r', width=bar_width, label="Last Pivot")
axes[1].set_title("Swaps vs Array Size")
axes[1].set_xlabel("Array Size")
axes[1].set_ylabel("Number of Swaps")
axes[1].set_xticks([r + bar_width for r in range(len(merged_data.index))])
axes[1].set_xticklabels(merged_data.index)
axes[1].legend()
axes[1].grid(True)

# Plot execution time for each pivot choice as a bar chart
axes[2].bar(r1, merged_data['F', 'Time'], color='b', width=bar_width, label="First Pivot")
axes[2].bar(r2, merged_data['M', 'Time'], color='g', width=bar_width, label="Middle Pivot")
axes[2].bar(r3, merged_data['E', 'Time'], color='r', width=bar_width, label="Last Pivot")
axes[2].set_title("Execution Time vs Array Size")
axes[2].set_xlabel("Array Size")
axes[2].set_ylabel("Execution Time (seconds)")
axes[2].set_xticks([r + bar_width for r in range(len(merged_data.index))])
axes[2].set_xticklabels(merged_data.index)
axes[2].legend()
axes[2].grid(True)

# Adjust the layout so that labels and titles fit well
plt.tight_layout()

# Display all the plots in a single window
plt.show()
