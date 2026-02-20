#!/bin/bash

# DO NOT RUN AS SUDO

# exit immediately if a command fails
set -e

SOURCE_DIR="$PWD/templates"

# check if source directory exists
if [ ! -d "$SOURCE_DIR" ]; then
    echo "Error: Directory '$SOURCE_DIR' does not exist."
    exit 1
fi

DESTINATION="/var/spob.bs/"

echo "Copying '$SOURCE_DIR' to '$DESTINATION'..."

# create destination dir
sudo mkdir -p "$DESTINATION"

# copy directory with preservation
sudo cp -a "$SOURCE_DIR" "$DESTINATION"

echo "Copy completed successfully."

# building spobutils + putting .so & .h at discoverable paths
cmake -S $PWD/spobutils -B $PWD/spobutils/build 
cmake --build $PWD/spobutils/build  
sudo cmake --build $PWD/spobutils/build --target install

# adding alias for spob-bs
{
  echo ""
  echo "# for spob"
  echo "export PATH=\"$PWD:\$PATH\""
  echo "alias spob='spob-bs.sh'"
  echo ""
} >> "$HOME/.bashrc"

echo "Configuration added to $HOME/.bashrc"
echo "Run: source ~/.bashrc"

