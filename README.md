<h1 align="center">
	🔗 pipex
</h1>

<p align="center">
	<b><i>Recreating shell pipelines in C</i></b><br>
</p>

<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/TiagoDev88/pipex?color=lightblue" />
	<img alt="Number of lines of code" src="https://img.shields.io/tokei/lines/github/TiagoDev88/pipex?color=critical" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/TiagoDev88/pipex?color=yellow" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/TiagoDev88/pipex?color=blue" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/TiagoDev88/pipex?color=green" />
</p>

<h3 align="center">
	<a href="#️-about">About</a>
	<span> · </span>
	<a href="#️-usage">Usage</a>
	<span> · </span>
	<a href="#️-example">Example</a>
</h3>

---

## 💡 About

> _pipex is a 42 project that replicates the behavior of shell pipelines (`|`) by executing commands with redirection between them using `pipe()`, `fork()`, and `execve()`._

It helped me learn more about:
- UNIX processes and forking
- Pipes and inter-process communication
- File descriptor manipulation
- Error handling and path resolution
- Executing external commands with `execve`

---

## 🛠️ Usage

### Requirements

- GCC compiler
- Make

### Instructions

**1. Clone the repository**

```bash
git clone https://github.com/TiagoDev88/pipex.git
cd pipex
```

**2. Compile the project**

```bash
make
```
This will generate the pipex executable.

## **⚙️ How it works**
``` bash
< infile cmd1 | cmd2 > outfile
```
Your program should be executed as:
``` bash
./pipex infile "cmd1" "cmd2" outfile
```

## **🧪 Example**
If you run:
``` bash
./pipex input.txt "grep a" "wc -l" output.txt
```
It will execute the equivalent of:
``` bash
< input.txt grep a | wc -l > output.txt
```

## **📁 Bonus**

If implemented, bonus features may include:

Support for multiple pipes (more than 2 commands)

Support for here_doc functionality

Usage:
``` bash
./pipex here_doc LIMITER "cmd1" "cmd2" outfile
```
Equivalent to:
``` bash
cmd1 << LIMITER | cmd2 >> outfile
```

## **📄 Files**
pipex.c – main logic

command.c – helper functions

get_cmd_path.c.c – handle command/path parsing

pipex.h – header with prototypes and includes

Makefile

## **❗ Notes**
Uses only allowed system calls: open, close, read, write, malloc, free, access, dup, dup2, execve, exit, fork, pipe, unlink, wait, waitpid, perror, strerror

Handles errors gracefully

Includes path resolution using PATH environment variable

## **👤 Author**
42 login: tfilipe-

GitHub: @TiagoDev88
