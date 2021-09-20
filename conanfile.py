from conans import ConanFile
from conan.tools.cmake import CMakeToolchain, CMake
from conan.tools.layout import cmake_layout


class LibXBitsetConan(ConanFile):
    name = "libxbitset"
    version = "0.0.1"
    license = "Apache License Version 2.0"
    author = "Khalil Estell"
    url = "https://github.com/SJSU-Dev2/libxbitset"
    description = "Extension of std::bitset that includes multi-bit insertion and extraction and more"
    topics = ("bit manipulation", "bits", "hardware", "registers")
    exports_sources = "CMakeLists.txt", "libxbitset/*"
    no_copy_source = True
    generators = "cmake_find_package"

    def config_options(self):
        pass

    def generate(self):
        tc = CMakeToolchain(self)
        tc.generate()

    def package(self):
        self.copy("*.hpp")

    def package_id(self):
        self.info.header_only()

    def package_info(self):
        self.cpp_info.includedirs = ["."]
