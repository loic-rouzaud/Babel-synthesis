# VCPKG USAGE

**Clone the Vcpkg repository**

```bash
git clone https://github.com/Microsoft/vcpkg.git
```

**Run the bootstrap script to build vcpkg**

```bash
./vcpkg/bootstrap-vcpkg.sh
```

**Get your VCPKG path to build it later**

```bash
sudo ./vcpkg/vcpkg integrate install
```

```bash
cd server
```

***AND***

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
cd [build directory] &&
./Server
```

```bash
cd [build directory] &&
./Client
```

## Compilation librairies with VCPKG

```bash
vcpkg install [packages to install]
```

**Opus and PortAudio**

```bash
vcpkg install opus
vcpkg install portaudio
````

## Install Qt6 via VCPKG

```bash
./vcpkg install qtbase --keep-going
````

If depencies are missing, install them.