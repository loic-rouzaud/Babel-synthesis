
# Babel

***CMAKE version 3.10***

***Compilation on Linux via VCPKG***

**Goal of the project**

The project is to create an OS-independent Voice Over IP (VOIP) protocol similar to SIP, which can be used over the internet. The protocol must be a client/server binary protocol with voice transport being client-to-client. The project must use specified libraries, including PortAudio for sound, Opus for compression codec, and Qt for the client's graphical user interface. Conan must be used for dependency management and CMake for building. The project must include a documentation of the binary protocol, a UML compliant class diagram, network abstraction using Asio or custom-made server-side and Qt Network or custom-made client-side, a Qt GUI client-side, a C++ abstraction of PortAudio and Opus, a contact list, the ability to make a call, and the ability to hang up. The project must be object-oriented, and any not explicitly authorized library is explicitly forbidden. Code must be readable, maintainable, and performant.

## UML

[Babel UML](./Doc/UML/UML.md)

## Use VCPKG ?

[VCPKG Doc](./Doc/Vcpkg/Vcpkg.md)

## Use Opus and PortAudio

[Opus and PortAudio](audioPoc/README.md)

## Documentation of the code

[Code doc](Doc/CodeDoc.md)