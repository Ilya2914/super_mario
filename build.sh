#!/bin/bash

BUILD_TYPE="Ninja"
BUILD_SUFFIX="ninja"

if ! command -v ninja &> /dev/null; then
    echo "Ninja not found. Using default generator."
    BUILD_TYPE="Unix Makefiles"
    BUILD_SUFFIX="make"
fi

BUILD_FOLDER="build_$BUILD_SUFFIX"
SOURCE_FOLDER="src"

mkdir -p "$BUILD_FOLDER"

cd "$BUILD_FOLDER" || exit

cmake -G "$BUILD_TYPE" "../$SOURCE_FOLDER"
cmake --build .

cd ..
