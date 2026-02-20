#!/bin/bash
#
# spob setup script
# DO NOT RUN AS ROOT

set -euo pipefail

SOURCE_DIR="$PWD/templates"
DESTINATION="/var/spob.bs/"

# checks for valid run
if [[ "$EUID" -eq 0 ]]; then
    echo "Error: do not run this script as root."
    exit 1
fi

if [[ ! -d "$SOURCE_DIR" ]]; then
    echo "Error: source directory not found: $SOURCE_DIR"
    exit 1
fi

if [[ ! -d "$PWD/spobutils" ]]; then
    echo "Error: spobutils directory not found: $PWD/spobutils"
    exit 1
fi
#----------------------------------------------------------------

#--- copying project templates
echo "Copying '$SOURCE_DIR' to '$DESTINATION'..."

# create destination dir
sudo mkdir -p "$DESTINATION"

# copy directory with preservation
sudo cp -a "$SOURCE_DIR" "$DESTINATION"

echo "Templates copied successfully"
#----------------------------------------------------------------

#--- building spobutils + putting .so & .h at discoverable paths
echo "Building spobutils ..."

cmake -S $PWD/spobutils -B $PWD/spobutils/build 
cmake --build $PWD/spobutils/build  
sudo cmake --build $PWD/spobutils/build --target install

echo "spobutils built and installed successfully"
#----------------------------------------------------------------

#--- adding alias for spob-bs
{
  echo ""
  echo "# for spob"
  echo "export PATH=\"$PWD:\$PATH\""
  echo "alias spob='spob-bs.sh'"
  echo ""
} >> "$HOME/.bashrc"

echo "Configuration added to $HOME/.bashrc"
echo "Run: source ~/.bashrc"
#----------------------------------------------------------------

echo "Done!"

