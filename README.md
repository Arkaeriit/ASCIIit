# ASCIIit

This program let you transform any file into a file made only of readable ASCII characters and then convert them back. This can be useful if you need to put some binary file to some pastebin site.

![Alt text](https://i.imgur.com/UqwzB1x.png "ASCIIit used on a picture")

## User manual
### Usage
```
asciiit <option> <input file> <output file>
```
Available options : 
* ASCII : transform any file into a ASCII only char 
* deASCII : transform back a file into it's original form.

If you want to use this command with piping you can use /dev/stdin and /dev/stdout as input or output file.

### Installation
To install this program simply do
```bash
make && sudo make install
```
in this program directory.

It only depends on gcc and the C standard library.

