#!/bin/bash


sh ./media/logo.sh
echo "Building project"
qmake
echo "Building makefile"
make

echo "Starting node..."
./server-echo-test
echo "Node successfully started."
