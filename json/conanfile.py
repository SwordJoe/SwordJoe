# -*- coding: utf-8 -*-

from conans import ConanFile, CMake, tools
import os

class KDCamAppConan(ConanFile):
    generators = "cmake", "cmake_find_package"


    def config_options(self):
        pass

    def configure(self):
        # We can control the options of our dependencies based on current options
        pass

    def requirements(self):        
        self.requires.add("jsoncpp/1.9.5")

