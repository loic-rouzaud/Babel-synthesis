# How to install opus on linux

 1 - Go to the Opus website at https://opus-codec.org/ and click on the "Downloads" link at the top of the page.

 2 - Download the latest stable release of the library for your platform (e.g., opus-1.3.1.tar.gz for Linux).

3 - extract files using : 

```bash
     tar -xvzf /path/to/filename.tar.gz 
```
 4 - Navigate to the extracted directory.
 
 5 - Then, run the following commands : 

 ``` bash
    ./configure
    make
    sudo make install
```

## Now you are able to Compile opus. 

# How to compil Opus 

## Running...


```bash
  g++ -o test test.cpp -lopus
```
It's a first try. The next updates will be better than this...
