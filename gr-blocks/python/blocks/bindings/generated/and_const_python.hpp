

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

#ifndef INCLUDED_GR_BLOCKS_AND_CONST_PYTHON_HPP
#define INCLUDED_GR_BLOCKS_AND_CONST_PYTHON_HPP

#include <gnuradio/blocks/and_const.h>

template<typename T>
void bind_and_const_template(py::module& m, const char *classname)
{
    using and_const      = gr::blocks::and_const<T>;

    py::class_<and_const, gr::sync_block, std::shared_ptr<and_const>>(m, classname)
        .def(py::init(&gr::blocks::and_const<T>::make),
            py::arg("k")
        )
        .def("k",&and_const::k)
        .def("set_k",&and_const::set_k)

        .def("to_basic_block",[](std::shared_ptr<and_const> p){
            return p->to_basic_block();
        })
        ;
} 

void bind_and_const(py::module& m)
{
    bind_and_const_template<std::uint8_t>(m,"and_const_bb");
    bind_and_const_template<std::int16_t>(m,"and_const_ss");
    bind_and_const_template<std::int32_t>(m,"and_const_ii");
} 

#endif /* INCLUDED_GR_BLOCKS_AND_CONST_PYTHON_HPP */
