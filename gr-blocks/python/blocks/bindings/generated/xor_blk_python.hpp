

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

#ifndef INCLUDED_GR_BLOCKS_XOR_BLK_PYTHON_HPP
#define INCLUDED_GR_BLOCKS_XOR_BLK_PYTHON_HPP

#include <gnuradio/blocks/xor_blk.h>

template<typename T>
void bind_xor_blk_template(py::module& m, const char *classname)
{
    using xor_blk      = gr::blocks::xor_blk<T>;

    py::class_<xor_blk, gr::sync_block, std::shared_ptr<xor_blk>>(m, classname)
        .def(py::init(&gr::blocks::xor_blk<T>::make),
            py::arg("vlen") = 1
        )

        .def("to_basic_block",[](std::shared_ptr<xor_blk> p){
            return p->to_basic_block();
        })
        ;
} 

void bind_xor_blk(py::module& m)
{
    bind_xor_blk_template<std::uint8_t>(m,"xor_bb");
    bind_xor_blk_template<std::int16_t>(m,"xor_ss");
    bind_xor_blk_template<std::int32_t>(m,"xor_ii");
} 

#endif /* INCLUDED_GR_BLOCKS_XOR_BLK_PYTHON_HPP */
