#!/bin/bash

# Define the target directories
TARGET_DIRS=("Exception_Handling" "Special_Case" "Threads" "Signal_Handling")

# Loop through each directory
for DIR in "${TARGET_DIRS[@]}"; do
    if [ -d "$DIR" ]; then
        # Find and delete all matching files
        find "$DIR" -type f \( -name "*.exe" -o -name "*.i" -o -name "*.ii" -o -name "*.s" -o -name "*.o" \) -exec rm -f {} \;
        echo "All matching files in '$DIR' have been deleted."
    else
        echo "Directory '$DIR' does not exist."
    fi
done
