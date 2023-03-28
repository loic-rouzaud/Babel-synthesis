# VCPKG USAGE

# ON LINUX IN THE BABEL DIRECTORY

# OBLIGATORY Dependencies : Qt6

**Clone the Vcpkg repository**

```bash
git clone https://github.com/Microsoft/vcpkg.git
```

**Run the bootstrap script to build vcpkg**

```bash
./vcpkg/bootstrap-vcpkg.sh
```

```bash
sudo ./vcpkg/vcpkg integrate install
```

**COPY THE -DCMAKE**

```bash
cd src/server
```

```bash
cmake -B Build -S . **PAST THE -DCMAKE YOU COPY BEFORE**
```

```bash
cmake --build Build
```

```bash
./Build/Server
```

***AND IN ANOTHER TERMINAL***

```bash
cd src/client
```

```bash
cmake -B Build -S . **PAST THE -DCMAKE YOU COPY BEFORE**
```

```bash
cmake --build Build
```

```bash
./Build/Client
```