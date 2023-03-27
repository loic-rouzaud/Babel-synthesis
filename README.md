
# Babel

## How to use it ?

**Clone the Vcpkg repository**
```bash
git clone https://github.com/Microsoft/vcpkg.git
```

**Run the bootstrap script to build vcpkg**

```bash
./vcpkg/bootstrap-vcpkg.sh
```

```bash
cd server
```

***OR***

```bash
cd client
```

**Build your project**

```bash
cmake -B [build directory] -S . -DCMAKE_TOOLCHAIN_FILE=[path to vcpkg]/scripts/buildsystems/vcpkg.cmake
```

```bash
cmake --build [build directory]
```

**Run the project**

```bash
./Server
```

```bash
./Client
```