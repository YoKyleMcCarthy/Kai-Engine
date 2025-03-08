#pragma once
#include <iostream>
#include "Component.hpp"
#include <Pybind11/embed.h>
#include <unordered_map>
#include <cmath>
namespace py = pybind11;

class Script : public Component {
    public:
        py::object script;  // Python module object
        py::object script_instance;  // Instance of the Enemy class
        static std::unordered_map<std::string, py::object> scriptCache;
    public:
            Script(std::string name) {
                py::module::import("sys").attr("path").cast<py::list>().append("Assets/Scripts");  // Add path to 'Assets/Scripts'
            try {
                // Check if the script is already cached
                if (scriptCache.find(name) == scriptCache.end()) {
                    // If not cached, import and cache it

                    py::object module = py::module::import(name.c_str());
                    scriptCache[name] = module;
                }
                // Use the cached module
                script = scriptCache[name];
                script_instance = script.attr("_create")();  // Create the Enemy instance
                } 
            catch (const py::error_already_set &e) {
                std::cout << "Python error: " << e.what() << std::endl;
            }
        }

        void Update(float deltaTime) override {
            try {
                script_instance.attr("_update")(deltaTime);
            } catch (const py::error_already_set &e) {
                PyErr_Print();  // This will print the Python traceback
                std::cout << "Python error during _update: " << e.what() << std::endl;
            }
    }
};

std::unordered_map<std::string, py::object> Script::scriptCache;