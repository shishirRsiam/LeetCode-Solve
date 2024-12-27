import os
import random

# Generate 5 datasets with lengths divisible by 1000 and values between 1 and 1000
dataset_lengths = [1000, 2000, 3000, 4000, 5000]
datasets = {
    f"dataset_{length}.txt": [random.randint(1, 1000) for _ in range(length)]
    for length in dataset_lengths
}

# Define the output directory
output_dir = os.getcwd() + "./data"
os.makedirs(output_dir, exist_ok=True)  # Create the directory if it doesn't exist

# Save each dataset to a separate file
file_paths = []
for file_name, data in datasets.items():
    # Convert the list to a string like: [2, 434, 545, 54]
    data_str = f"[{', '.join(map(str, data))}]"
    
    # Define the file path
    file_path = os.path.join(output_dir, file_name)
    print(data_str)
    # Write the data to the file
    with open(file_path, "w") as f:
        f.write(data_str)
    
    # Store the file path
    file_paths.append(file_path)

# Print the paths where datasets are saved
print(f"Datasets saved to {os.path.abspath(output_dir)}")
print(file_paths)
