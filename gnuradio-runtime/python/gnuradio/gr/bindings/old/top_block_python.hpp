//
// Copyright 2017-2018 Ettus Research, a National Instruments Company
// Copyright 2019 Ettus Research, a National Instruments Brand
//
// SPDX-License-Identifier: GPL-3.0-or-later
//

#ifndef INCLUDED_GR_TOP_BLOCK_PYTHON_HPP
#define INCLUDED_GR_TOP_BLOCK_PYTHON_HPP

// #pragma once

#include <gnuradio/top_block.h>
#include <gnuradio/runtime_types.h>

#define GR_PYTHON_BLOCKING_CODE(code) {                                 \
    PyThreadState *_save;                                               \
    _save = PyEval_SaveThread();                                        \
    try{code}                                                           \
    catch(...){PyEval_RestoreThread(_save); throw;}                     \
    PyEval_RestoreThread(_save);                                        \
}


void top_block_run_unlocked(gr::top_block_sptr r) noexcept(false)
{
    GR_PYTHON_BLOCKING_CODE
    (
        r->run();
    )
}

void top_block_start_unlocked(gr::top_block_sptr r, int max_noutput_items) noexcept(false)
{
    GR_PYTHON_BLOCKING_CODE
    (
        r->start(max_noutput_items);
    )
}

void top_block_wait_unlocked(gr::top_block_sptr r) noexcept(false)
{
    GR_PYTHON_BLOCKING_CODE
    (
        r->wait();
    )
}

void top_block_stop_unlocked(gr::top_block_sptr r) noexcept(false)
{
    GR_PYTHON_BLOCKING_CODE
    (
        r->stop();
    )
}

void top_block_unlock_unlocked(gr::top_block_sptr r) noexcept(false)
{
    GR_PYTHON_BLOCKING_CODE
    (
        r->unlock();
    )
}

void bind_top_block(py::module& m)
{
    using top_block      = gr::top_block;

    py::class_<top_block, gr::hier_block2, std::shared_ptr<top_block>>(m, "top_block_pb")
        // .def(py::init())
        .def(py::init(&gr::make_top_block), py::arg("name"), py::arg("catch_exceptions") = false)
        .def("run",&top_block::run,
            py::arg("max_noutput_items") = 100000000 
        )
        .def("start",&top_block::start,
            py::arg("max_noutput_items") = 100000000 
        )
        .def("stop", &top_block::stop)
        .def("wait", &top_block::wait)
        .def("lock", &top_block::lock)
        .def("unlock", &top_block::unlock)
        .def("edge_list",&top_block::edge_list)
        .def("msg_edge_list",&top_block::msg_edge_list)
        .def("dump",&top_block::dump)
        .def("max_noutput_items",&top_block::max_noutput_items)
        .def("set_max_noutput_items",&top_block::set_max_noutput_items,
            py::arg("nmax") 
        )
        .def("to_top_block",&top_block::to_top_block)
        .def("setup_rpc",&top_block::setup_rpc)
        ;

    m.def("make_top_block", &gr::make_top_block);
    m.def("cast_to_top_block_sptr",&gr::cast_to_top_block_sptr,
        py::arg("block") 
    );

    m.def("top_block_run_unlocked", &top_block_run_unlocked);
    m.def("top_block_start_unlocked", &top_block_start_unlocked);
    m.def("top_block_wait_unlocked", &top_block_wait_unlocked);
    m.def("top_block_stop_unlocked", &top_block_stop_unlocked);
    m.def("top_block_unlock_unlocked", &top_block_unlock_unlocked);
} 

#endif /* INCLUDED_UHD_USRP_MULTI_USRP_PYTHON_HPP */
