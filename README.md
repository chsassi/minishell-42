# Minishell (42 School)

🇬🇧🇺🇸

Minishell is a project in the 42 School curriculum that challenges students to build a basic shell environment. 
Inspired by Unix-like systems, Minishell allows users to execute commands, handle input/output redirection, and manage processes. 
This project provides a foundation in system programming and process management, deepening your understanding of how a shell works and how to interact with the operating system at a lower level.

🇮🇹

Minishell è un progetto del curriculum della Scuola 42 che sfida gli studenti a costruire un ambiente shell di base. 
Ispirato ai sistemi simili a Unix, Minishell consente di eseguire comandi, gestire i processi e i segnali, offrendo una comprensione approfondita dell'interazione con il sistema operativo.

Evaluation: 95/100
<img width="1282" alt="Screenshot 2024-11-07 at 17 35 00" src="https://github.com/user-attachments/assets/8cc50007-bb7f-4058-a8b1-a6e69283f696">

### Execution:

```bash
./minishell
```

This command starts your Minishell, ready to interpret user commands in a manner similar to Bash or Zsh.

Features:

Built-in Commands: Implement basic commands like cd, echo, pwd, export, unset, env, and exit.
Redirections: Handle redirections such as >, <, >>, and << (heredoc).
Pipes: Enable piping between commands to allow for complex command chaining.
Environment Variables: Support environment variable expansion within commands.
Signal Handling: Manage signals like CTRL+C, CTRL+D, and CTRL+\ gracefully, ensuring a responsive user experience.

Example Usage
Running a basic command
```bash
$ echo "Hello, world!"
Hello, world!
```

Using pipes and redirection
```bash
$ ls -l | grep ".c" > c_files.txt
```
Environment variable expansion
```bash
$ export NAME=Minishell
$ echo "Welcome to $NAME!"
```
