#!/bin/bash

# Define the target directory
TARGET_DIR="./Exception_Handling"

# Check if the directory exists
if [ -d "$TARGET_DIR" ]; then
    # Find and delete all .exe files in the Exception folder
    find "$TARGET_DIR" -type f \( -name "*.exe" -o -name "*.i" -o -name "*.ii" -o -name "*.s" -o -name "*.o" \) -exec rm -f {} \;
    echo "All .exe files in '$TARGET_DIR' have been deleted."
else
    echo "Directory '$TARGET_DIR' does not exist."
fi
