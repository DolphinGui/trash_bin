import os
from conans import ConanFile, tools, CMake


class trash_bin(ConanFile):
    name = "trash_bin"
    version = "1.0.0"
    description = "A deferred destruction library"
    license = "Unlicense"
    topics = ("conan", "flag")
    exports_sources = "include/*"
    no_copy_source = True
    # No settings/options are necessary, this is header only
    generators = "cmake_find_package"
    build_policy = "missing"
    exports_sources = "include/*", "CMakeLists.txt", "tests/*.cpp"

    def package(self):
        self.copy("*.hpp")

    def package_id(self):
        self.info.header_only()

    # just tests
    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()
        cmake.test()
