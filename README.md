# RPIPicoCPPUTest
Template Project for CPPUTest on Raspberry PI Pico

## Versions of Template

### Baremetal
A framework to work just under Pico SDK.

### FreeRTOS
WIP - not yet ready

## Structure

Test code is run from the *test* folder. Main code in the *src* folder.

File list should be defined in *src.files.cmake*.

## Build process
Build main binary
```
mkdir build
cd build
cmake ..
make
```
Binary is build/src/*.elf or  build/src/*.uf2



To build the unti test binary.
```
mkdir build
cd build
cmake ..
make test
```
Binary is build/test/test.elf or build/test/test.uf2 



