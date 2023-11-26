# hori

### What is hori?
`hori` is a programming language made in my free time. It can't do much now but I want to continue working on it. I don't need it to be as big as e.g. C but I like coding so I made this.

### How to install?
#### Windows
You can't.

#### Linux
1. Download this repository into a desired folder: \

###### Install by git
```sh
git clone https://github.com/leanderlombardi/hori.git && \
  cd hori && \
  sudo make install
```
###### Install by hand
- Click on `Code`
- Click on `Download ZIP`
- Extract .zip
- `cd` into extracted folder

2. Install `gcc` and `make` by running GCC-MAKE.sh:
```bash
chmod +x ./GCC-MAKE.sh && \
  ./GCC-MAKE.sh
```
3. Install `hori` by running:
```bash
sudo make install
```
### How to run?
##### Auto Compile
1. Write your code to a file with `.hori` extension
2. `cd` to the folder with hori file
3. Execute:
```bash
hori ac
```
4. Then, to run:
```bash
./output
```
##### Manual Compile
1. Write your code to a file
2. Execute:
```bash
hori [-o <output>] [-Werror] [-autoinclude] [-v=<version>] <file>
```
`-o <output>`: moves output file to desired location\
`-Werror`: treats warnings as errors, can be useful if used on a bigger scale to prevent massive errors\
`-autoinclude`: automatically includes all headers [BETA]\
`-v=<version>`: uses specified version instead of newest (newest: 01a)\
3. Then, to run:
```bash
./output
```
or
```bash
./<output>
```
