# requirements
- conan
- cmake

# rules
- [Conventional Commits](https://www.conventionalcommits.org/en/v1.0.0/)
- [Semantic Versioning 2.0.0 | Semantic Versioning](https://semver.org/)
- [C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines)

# stack
- package manager: conan, but other methods could be used in the future.
- compiler: clang. *gcc compilers are not backward compatible.
- format: clang-format
- cicd: github actions
- static analysis: clang tidy
- code coverage: codecov
- documentation: doxygen
- some libraries as below are included because they are essential:
  - logging: spdlog
  - test: doctest
  - cli: clipp

# structure
...

# known issues
- the generator of Conan was "cmake" at first, but cmake can't detect some libraries as dependencies so it is switched to "cmake_find_package"

# references
- android abis: [Android ABIs](https://developer.android.com/ndk/guides/abis)
- platform preprocessor macros: [abseil.github.io/macros.md at master · abseil/abseil.github.io](https://github.com/abseil/abseil.github.io/blob/master/docs/cpp/platforms/macros.md)
- [Setup Android NDK · Actions · GitHub Marketplace](https://github.com/marketplace/actions/setup-android-ndk)