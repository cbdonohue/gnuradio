

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

#ifndef INCLUDED_GR_BLOCKS_MULTIPLY_MATRIX_PYTHON_HPP
#define INCLUDED_GR_BLOCKS_MULTIPLY_MATRIX_PYTHON_HPP

#include <gnuradio/blocks/multiply_matrix.h>

template<typename T>
void bind_multiply_matrix_template(py::module& m, const char *classname)
{
    using multiply_matrix      = gr::blocks::multiply_matrix<T>;

    py::class_<multiply_matrix, gr::sync_block, std::shared_ptr<multiply_matrix>>(m, classname)
        .def(py::init(&gr::blocks::multiply_matrix<T>::make),
            py::arg("A"),
            py::arg("tag_propagation_policy") = gr::block::TPP_ALL_TO_ALL
        )
        .def("get_A",&multiply_matrix::get_A)
        .def("get_A",&multiply_matrix::set_A,
            py::arg("new_A")
        )
        .def_readwrite("MSG_PORT_NAME_SET_A",&multiply_matrix::MSG_PORT_NAME_SET_A)

        .def("to_basic_block",[](std::shared_ptr<multiply_matrix> p){
            return p->to_basic_block();
        })
        ;
} 

void bind_multiply_matrix(py::module& m)
{
    bind_multiply_matrix_template<float>(m,"multiply_matrix_ff");
    bind_multiply_matrix_template<gr_complex>(m,"multiply_matrix_cc");
} 

#endif /* INCLUDED_GR_BLOCKS_MULTIPLY_MATRIX_PYTHON_HPP */
