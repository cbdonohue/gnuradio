

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

#ifndef INCLUDED_GR_BLOCKS_ADD_BLK_PYTHON_HPP
#define INCLUDED_GR_BLOCKS_ADD_BLK_PYTHON_HPP

#include <gnuradio/blocks/add_blk.h>

template<typename T>
void bind_add_template(py::module& m, const char *classname)
{
    using add_blk      = gr::blocks::add_blk<T>;

    py::class_<add_blk, gr::sync_block, std::shared_ptr<add_blk>>(m, classname)
        .def(py::init(&gr::blocks::add_blk<T>::make),
            py::arg("vlen") = 1
        )

        .def("to_basic_block",[](std::shared_ptr<add_blk> p){
            return p->to_basic_block();
        })
        ;
} 

void bind_add_blk(py::module& m)
{
    bind_add_template<std::int16_t>(m,"add_ss");
    bind_add_template<std::int32_t>(m,"add_ii");
    bind_add_template<float>(m,"add_ff");
    bind_add_template<gr_complex>(m,"add_cc");
} 

#endif /* INCLUDED_GR_BLOCKS_ADD_BLK_PYTHON_HPP */
