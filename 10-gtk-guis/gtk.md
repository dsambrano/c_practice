# Working with GTK

In order to use the GTK library, you need to install all the appropriate packages.
On RaspberryOS, you should be fine with `sudo apt install libgtk3.0-dev` according to the book.
However, Fedora recommends you install several packages as well as their docs ([source][fedora-gtk]).

```bash
# Libs
sudo dnf install gtk3-devel gstreamer1-devel clutter-devel webkit2gtk3-devel libgda-devel gobject-introspection-devel
# Docs
sudo dnf install devhelp gtk3-devel-docs gstreamer1-devel-docs clutter-doc
```

Once, you install the appropriate packages, you are not done.
You will still need to tell the compiler where to find them. 
This is done with the `pkg-config` command.

```bash
pkg-config --cflags --libs gtk+-3.0
```

will output all the locations (`-I/`) and names (`-l`) for the relevant libs.
Add this to the compiler with backticks (`` ` ``)

```bash
gcc `pkg-config --cflags --libs gtk+-3.0` main.c -o main
```
this will create a main executable to use to open your app.


## Known Bugs

[UPDATE]
The previous bug was fixed, I was able to solve this by using `cmake` to automate the `compile_commands.json` file.
I needed a few sources to solve it (linked [here][so-find-pkg], [here][cmake-include-link], and [here][so-include-link-better]).
This should replace the
```
`pkg-config --cflags --libs gtk+-3.0`
```
section in the gcc/clang compiler (see [cmake docs][cmake-docs] for more information).
Finally, you also need to include `set(CMAKE_EXPORT_COMPILE_COMMANDS ON)` to actually create the `compile_commands.json` file ([source][so-set]).

You will need to copy (according to docs, you should symlink it [source][clangd-docs]) that `compile_commands.json` file to either the src or the root directory for the project for it clang to accept it.
You can also name the project something based on the title in the project section. 
There is a working sample is at the `CMakeLists.txt` file.

To use the file make and cd into a build dir and run `cmake` build ([source][cmake-tutorial] and [source][so-cmake]):

```bash
mkdir build; cd build
cmake ..
cmake --build .
```

> When using cmake, you can also use wildcards e.g., `fil(GLOB SOURCES "src/*.c)` to include a bunch of files, then `add_executable(project_name ${SOURCES}) [source][cmake-glob].

---

The above code will let you compile the project without any errors, Yay!
However, your LSP will still complain about not having access to `gtk/gtk.h`.
This is a huge annoyance, for one, you just have a bunch of unhelpful errors, and two you do not have access to the LSP niceties.
It looks like `clangd` (the C/C++ LSP) solves this by using either a `compile_commands.json` or `compile_flags.txt` file ([source][clangd]).
Unfortunately, I have not been able to successfully get this working. 
Currently, I am trying to use [cmake][] to automate this process, but have been unsuccessful.
For info on basic cmake setup I am using this [SO post][so-cmake].



[fedora-gtk]: https://developer.fedoraproject.org/tech/languages/c/gtk.html 
[clangd]: https://clangd.llvm.org/installation.html#project-setup
[cmake]: https://cmake.org/cmake/help/latest/guide/tutorial/A%20Basic%20Starting%20Point.html
[so-cmake]: https://stackoverflow.com/a/18099975
[so-find-pkg]: https://stackoverflow.com/q/32507252
[cmake-include-link]: https://forums.raspberrypi.com/viewtopic.php?t=191117#p1200001
[so-include-link-better]: https://stackoverflow.com/a/57224542
[so-include-link]: https://stackoverflow.com/a/29316084
[cmake-docs]: https://cmake.org/cmake/help/latest/module/FindPkgConfig.html
[so-set]: https://stackoverflow.com/a/66560758
[cmake-tutorial]: https://cmake.org/cmake/help/latest/guide/tutorial/A%20Basic%20Starting%20Point.html#id5
[cmake-glob]: http://derekmolloy.ie/hello-world-introductions-to-cmake/#Example_2_A_Project_with_Directories
[clangd-docs]: https://clangd.llvm.org/installation#project-setup
