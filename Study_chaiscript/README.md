## Installation
git clone https://github.com/ChaiScript/ChaiScript.git
cd ChaiScript
git checkout v6.1.0

project structure

|-[ChaiScript]<clone from git>
|-chaiscript-demo/
    ├─ CMakeLists.txt
    ├─ src/
    │  └─ main.cpp
    └─ scripts/
       └─ hello.chai

## Run example
mkdir build
cd build
cmake .. 
make
cd ..
```
./build/chaiscript_demo 

Hello from ChaiScript!
add(10,32) = 42
```