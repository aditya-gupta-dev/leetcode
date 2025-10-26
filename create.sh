#!/bin/bash

if [ "$#" -lt 1 ]; then
    echo "create_error: provide id of problem statement"
    exit 1
fi

mkdir $1
cd $1 
go mod init $1
touch main.go 
