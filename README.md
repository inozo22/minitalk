<h1>
	minitalk (Finished)
</h1>  


<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/inozo22/minitalk?color=lightblue" />
	<img alt="Number of lines of code" src="https://img.shields.io/tokei/lines/github/inozo22/minitalk?color=critical" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/inozo22/minitalk?color=yellow" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/inozo22/minitalk?color=blue" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/inozo22/minitalk?color=green" />
</p>

<p>
	<b>The purpose of this project is to code a small data exchange program using UNIX signals. This program only works on macOS(´･ω･｀)</b><br>
</p>

## Error control
- Number of argument is not 3 (ac != 3)
- Server's PID is more than 1.
- No error after get server's PID.

## Making programs

Cloning the repo
```bash
git clone --recursive https://github.com/inozo22/minitalk.git
```
To compile client & server

```bash
$ make
```

## How to use

1. Execute Server

```bash
$ ./server
```

2. Execute client with the Server PID and a string to send

```bash
$ ./client server_PID "whatever you want to send"
```
