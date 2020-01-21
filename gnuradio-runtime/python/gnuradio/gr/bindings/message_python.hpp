

/* Copyright 2020 Free Software Foundation, Inc.
 *
 * This file is part of GNU Radio
 *
 * GNU Radio is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * GNU Radio is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GNU Radio; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */


/* This file is automatically generated using the gen_nonblock_bindings.py tool */

#ifndef INCLUDED_GR_MESSAGE_PYTHON_HPP
#define INCLUDED_GR_MESSAGE_PYTHON_HPP

#include <gnuradio/message.h>

void bind_message(py::module& m)
{
    using message    = gr::message;


    py::class_<message, std::shared_ptr<message>>(m, "message")
        .def(py::init<gr::message const &>(),
           py::arg("arg0") 
        )
        .def("make_from_string",&message::make_from_string)
        // .def("make_from_string",&message::make_from_string,
        //     py::arg("s"), 
        //     py::arg("type") = 0, 
        //     py::arg("arg1") = 0, 
        //     py::arg("arg2") = 0 
        // )
        .def("type",&message::type)
        .def("arg1",&message::arg1)
        .def("arg2",&message::arg2)
        .def("set_type",&message::set_type,
            py::arg("type") 
        )
        .def("set_arg1",&message::set_arg1,
            py::arg("arg1") 
        )
        .def("set_arg2",&message::set_arg2,
            py::arg("arg2") 
        )
        .def("msg",&message::msg)
        .def("to_string",&message::to_string)
        ;

    m.def("message_ncurrently_allocated",&gr::message_ncurrently_allocated);
} 

#endif /* INCLUDED_GR_MESSAGE_PYTHON_HPP */
