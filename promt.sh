#!/bin/bash

# Generate a list of files
find include src \( -name "*.h" -o -name "*.cpp" \) > files.txt

# Read each file name, print the name and file content
while IFS= read -r p; do
  echo -e "```$p```"
  sudo cat "$p"
done <files.txt > prompt.txt

# Remove the temporary file
rm files.txt
