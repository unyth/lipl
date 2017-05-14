# lipl
## What is it?

I am trying to follow Building Your Own Lisp by Daniel Holden as a means to learn to implement programming language and to improve my ability to program in C.

You can find Daniel Holden's book at http://www.buildyourownlisp.com/.

## Required packages in addition to a C compiler

You'll need the Editline library.

On Debian family of OS with apt:
```
sudo apt-get install libedit-dev
```

On Fedora family of OS with yum:
```
su -c "yum install libedit-dev"
```

You also need mpc library made my the author. You just need mpc.h and mpc.c file from the following git repo:

https://github.com/orangeduck/mpc
