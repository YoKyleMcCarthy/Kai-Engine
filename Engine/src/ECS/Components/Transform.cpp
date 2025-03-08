#include "Transform.hpp"
#include <pybind11/pybind11.h>
namespace py = pybind11;


PYBIND11_MODULE(Component, m) {
    py::class_<Transform>(m, "Transform")
        .def(py::init<>())
        .def(py::init<Vec2<float>, Vec2<float>, float>())
        .def_readwrite("position", &Transform::position)
        .def_readwrite("scale", &Transform::scale)
        .def_readwrite("rotation", &Transform::rotation);
}