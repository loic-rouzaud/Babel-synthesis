# VCPKG USAGE

# ON LINUX IN THE BABEL DIRECTORY

**Clone the Vcpkg repository**

```bash
git clone https://github.com/Microsoft/vcpkg.git
```

**Run the bootstrap script to build vcpkg**

```bash
./vcpkg/bootstrap-vcpkg.sh
```

```bash
cd vcpkg
```

**DEPENDENCIES TO INSTALL**

```bash
sudo dnf install bison
```

```bash
sudo dnf install autoconf-archive
```

**QT INSTALLATION**

```bash
/vcpkg install qtbase
```

**RUN THE PROJECT**

```bash
cd ..
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
cmake --build Build && ./Server
```

***AND IN ANOTHER TERMINAL***

```bash
cd src/client
```

```bash
cmake -B Build -S . **PAST THE -DCMAKE YOU COPY BEFORE**
```

```bash
cmake --build Build && ./Client
```