#pragma once

#include "Vec2.hpp"
#include <Pybind11/pybind11.h>

#include <Pybind11/embed.h>

namespace py = pybind11;

PYBIND11_EMBEDDED_MODULE(Vector, module) {  // ✅ Stays at global scope
    module.doc() = "Math Module";

    py::class_<Vec2<float>>(module, "Vec2f")
        .def(py::init<float, float>())
        .def_readwrite("x", &Vec2<float>::x)
        .def_readwrite("y", &Vec2<float>::y)
        .def("length", &Vec2<float>::length);

    py::class_<Vec2<int>>(module, "Vec2i")
        .def(py::init<int, int>())
        .def_readwrite("x", &Vec2<int>::x)
        .def_readwrite("y", &Vec2<int>::y)
        .def("length", &Vec2<int>::length);

    py::class_<Vec2<double>>(module, "Vec2d")
        .def(py::init<double, double>())
        .def_readwrite("x", &Vec2<double>::x)
        .def_readwrite("y", &Vec2<double>::y)
        .def("length", &Vec2<double>::length);

    py::class_<Vec2<long>>(module, "Vec2l")
        .def(py::init<long, long>())
        .def_readwrite("x", &Vec2<long>::x)
        .def_readwrite("y", &Vec2<long>::y)
        .def("length", &Vec2<long>::length);
}

class Math {
public:
    static void InitVec2();
};

void Math::InitVec2()  {
    // Import the embedded module
    py::module_ vector_module = py::module_::import("Vector");

    // Get Python's built-in modules (`sys.modules["builtins"]`)
    py::module_ builtins = py::module_::import("builtins");

    // Register Vec2 types into Python's built-in namespace
    builtins.attr("Vec2f") = vector_module.attr("Vec2f");
    builtins.attr("Vec2i") = vector_module.attr("Vec2i");
    builtins.attr("Vec2d") = vector_module.attr("Vec2d");
}