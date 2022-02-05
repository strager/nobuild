# nobuild

Header only library for writing build recipes in an opinionated way in C, with an additional testing framework.
Using the nobuild portion with the test framework, the tool becomes noframework.

The original code started as a fork from [nobuild](https://github.com/tsoding/nobuild.git).
All original creator comments/license is left as is.

## Main idea

The idea is that you should not need anything but a C compiler to build a C project. No make, no cmake, no shell, no cmd, no PowerShell etc. Only C compiler. So with the C compiler you bootstrap your build system and then you use the build system to build everything else. (and test everything).

The framework should be able to make most of the decisions for you. Just follow the [feature](#Feature_based_development) style of development.

## Begin
Try it out right here:

```console
$ gcc ./build/nobuild.c -o ./build/nobuild
$ ./build/nobuild
```

Explore [nobuild.c](./build/nobuild.c) file.

After running the example, and getting an idea of [feature](#Feature_based_development) based development. See the [I would like to know more](#I_would_like_to_know_more) section.
 
## Advantages of noframework

- Reducing the amount of dependencies.
- You end up using the same language for developing and building your project. Which may enable some interesting code reusage strategies. The build system can use the code of the project itself directly and the project can use the code of the build system also directly.
- You get to use C more.
- Built in test framework to go with your built in no build.

## Disadvantages of noframework

- Highly opinionated.
- It probably does not make any sense outside of C/C++ projects.
- You get to use C more.

## How to use the library in your own project

Keep in mind that [nobuild.h](./nobuild.h) is an [stb-style](https://github.com/nothings/stb/blob/master/docs/stb_howto.txt) header-only library. That means that just including it does not include the implementations of the functions. You have to `#define NOBUILD_IMPLEMENTATION` before the include. See our [nobuild.c](./nobuild.c) for an example.

1. Copy [nobuild.h](./build/nobuild.h) to your project
2. Create `build/nobuild.c` in your project with the build recipe. See our [nobuild.c](./build/nobuild.c) for an example.
3. Bootstrap the `nobuild` executable:
   - `$ gcc ./build/nobuild.c -o ./build/nobuild` on POSIX systems
4. Run the build: `$ ./build/nobuild`

## Go Rebuild Urself™

TODO:: Still need to incorporate Go Rebuild Urself™ into the dependency tracking and test framework.
If you enable the [Go Rebuild Urself™](https://github.com/tsoding/nobuild/blob/d2bd711f0e2bcff0651850cd795509ab104ad9d4/nobuild.h#L218-L239) Technology the `nobuild` executable will try to rebootstrap itself every time you modify its source code.

# feature


# I would like to know more
