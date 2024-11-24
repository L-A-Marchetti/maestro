#!/bin/bash

# Note that this installation script only works
# in the context of downloading the library,
# i.e. in the case where install.sh is next to
# maestro.h and libmaestro.a. To use this script
# as a developer, you will need to change the
# include and build paths.

# Function to check if a command succeeded
check_success() {
    if [ $? -ne 0 ]; then
        echo "Error: $1 failed. Exiting."
        exit 1
    fi
}

# Create header directory
echo "Creating header directory..."
sudo mkdir -p /usr/local/include/maestro
check_success "Creating header directory"

# Copy header files
echo "Copying header files..."
sudo cp maestro.h /usr/local/include/maestro/
check_success "Copying header files"

sudo chmod 644 /usr/local/include/maestro/*.h
check_success "Setting permissions for header files"

# Copy library
echo "Copying library..."
sudo cp libmaestro.a /usr/local/lib/
check_success "Copying library"

sudo chmod 644 /usr/local/lib/libmaestro.a
check_success "Setting permissions for library"

# Update library cache
echo "Updating library cache..."
sudo ldconfig
check_success "Updating library cache"

echo "Maestro library installation completed successfully!"
