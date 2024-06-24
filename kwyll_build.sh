#!/bin/bash

cd install
zip kwyll_build.zip -r . -i@../file_list.txt 
cp kwyll_build.zip ..
cd ..
