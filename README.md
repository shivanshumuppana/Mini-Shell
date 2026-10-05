# Mini Shell
A small unix-like shell written in C, built from scratch.

The goal of this project is to understand the unix process model and the system calls that make a shell work.

## Current Status
The shell can currently:
- Read commands from standard input
- Tokenize commands into arguements
- Create child processes using `fork()`
- Execute programs using `execvp()`
- Run commands with arguements
- Handle the `exit` built-in
- Handle the `cd` built-in
- Change the shell's working directory using `chdir()`
- Report errors when `chdir()` or `execvp()` fails

## Output
<img width="1116" height="530" alt="image" src="https://github.com/user-attachments/assets/31117a30-cbb0-4d24-b96d-7bab754f7e98" />

## How it works
The shell uses `fork()` to create a child process.

The child then calls `execvp()` to replace its process image with the request program.

The parent waits for the child using `wait()` before displaying the next prompt.

`cd` & `exit` however, are handled differently, executing in the parent process.

## Error handling
If `execvp()` fails, the child reports the error and termintes instead of continuing into the shell loop.

## Concepts learned so far (Theory)
This project is being developed alongside my study of unix/linux systems and OSTEP.

Current concepts include:
- Processes
- Process creation
- fork()
- exec()/execvp()
- wait()
- Parent and child processes
- Process state
- System calls
- User mode vs kernel mode
- Traps
- Context switching

## Planned features
The following will be implemented incrementally:
- Input/Output redirection
- Append redirection
- Pipes
- Environment variables
- Improved command parsing
- signals
- background processes
- job control
