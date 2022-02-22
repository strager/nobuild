# nobuild

Header only library for writing build recipes in an opinionated way in C, with an additional testing framework included.
Using the nobuild portion with the test framework, the tool becomes noframework.

The original code started as a fork from [nobuild](https://github.com/tsoding/nobuild.git).

## Main idea

The idea is that you should not need anything but a C compiler to build a C project. No make, no cmake, no shell, no cmd, no PowerShell etc. Only C compiler. So with the C compiler you bootstrap your build system and then you use the build system to build everything else, and run through all tests.

The framework should be able to make most of the decisions for you.

## Begin
Try it out right here:

```console
$ gcc ./nobuild.c -o ./nobuild
$ ./nobuild
```

Explore [nobuild.c](./nobuild.c) file.

After running the example, and getting an idea of [feature](#Feature_based_development) based development. See the [I would like to know more](#I_would_like_to_know_more) section.
 
## Advantages of noframework

- Reducing the amount of dependencies.
- You end up using the same language for developing and building your project. Which may enable some interesting code reusage strategies. The build system can use the code of the project itself directly and the project can use the code of the build system also directly.
- You get to use C more.
- Built in test framework to go with your built in no build.

## Disadvantages of noframework

- Highly opinionated.
- Doesn't work outside of C/C++ projects.
- You get to use C more.

## How to use the library in your own project

Keep in mind that [nobuild.h](./nobuild.h) is an [stb-style](https://github.com/nothings/stb/blob/master/docs/stb_howto.txt) header-only library. That means that just including it does not include the implementations of the functions. You have to `#define NOBUILD_IMPLEMENTATION` before the include. See our [nobuild.c](./nobuild.c) for an example.

1. Copy [nobuild.h](./nobuild.h) to your project
2. Create `nobuild.c` in your project with the build recipe. See our [nobuild.c](./nobuild.c) for an example.
3. Bootstrap the `nobuild` executable:
   - `$ gcc -O3 ./nobuild.c -o ./nobuild` on POSIX systems
4. Run the build: `$ ./nobuild`

# Feature based development
nobuild uses feature based development.

add a new feature to your project.
```c
./nobuild --add math
```
this will automatically create an include file in the include directory, create a directory and file at `math/lib.c`, create a new test file named `tests/math.c`.

See this in action [add](./demo/add.md)

Some features could require additional Includes or other linked libraries. Edit the `nobuild.c` file, and add the new feature, along with any dependencies.

```c
  ADD_FEATURE("math","-lpthread");
```

If `math` has any dependencies within your project, include them, and nobuild will automatically link them when building tests, and dynamic and static libraries.
```c
  DEPS("math", "add", "mul", div");
```

After making any change to your projects `nobuild.c` file do not forget to run


Now, when running an incremental build, and changing the `div` feature, just run `./nobuild --incremental ./div/lib.c`

The `div` feature will be rebuilt and tested, as well as `math` being rebuilt and tested!

See this in action [incremental](./demo/incremental.md)

You will notice in this repository, the `stuff` feature has multiple files. This is called a fat feature. Build times could degrade if you use too many fat features with too many dependencies on other fat features. It is recommended to create many light small single file features for maximum efficiency.

# I would like to know more
