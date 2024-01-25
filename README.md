# Minishell

Minishell is a small-scale Unix shell created as part of 42Firenze's core curriculum. This project focuses on implementing a basic command-line interpreter, providing users with a simplified shell experience.

## Features

- **Command Execution:** Execute basic shell commands.
- **Built-in Commands:** Support for built-in commands such as `cd`, `echo`, and `exit`.
- **Redirection and Pipes:** Handle input/output redirection and command piping.
- **Signal Handling:** Manage signals like Ctrl+C and Ctrl+D gracefully.
- **Environment Variables:** Full support for managing, creating and deleting environment variables.

## Technologies

- **Programming Language:** the project was fully written in C.
- **Operating System:** Unix-based systems.

## Project Structure

- `source/`: Contains the source code for the minishell's built-ins and variable managment.
- `source_parse/`: Contains the source code for the minishell's interpreter.
- `source_processes/`: Contains the source code for the minishell's pipe and redirection managment.

## How to Use

Run the Makefile, launch the shell executable and have fun!
