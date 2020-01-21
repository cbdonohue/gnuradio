<%
    namespace = header_info['namespace']
    modname = header_info['module_name']
    classes=header_info['classes']
    free_functions=header_info['free_functions']
    free_enums = header_info['enums']
%>

${license}

/* This file is automatically generated using the gen_nonblock_bindings.py tool */

#ifndef INCLUDED_${'_'.join(namespace).upper()}_${basename.upper()}_PYTHON_HPP
#define INCLUDED_${'_'.join(namespace).upper()}_${basename.upper()}_PYTHON_HPP

#include <${prefix_include_root}/${basename}.h>

void bind_${basename}(py::module& m)
{
% for cls in classes:
% if classes:
    using ${cls['name']}    = ${"::".join(namespace)}::${cls['name']};
% endif ##classes
% endfor ##classes
% for cls in classes:

<%
try:
        member_functions = cls['member_functions']
except:
        member_functions = []
try:
        constructors = cls['constructors']
except:
        constructors = []
try:
        class_enums = cls['enums']
except: 
        class_enums = []
try:
        class_variables = cls['variables']
except:
        class_variables = []

try:
        def find_make_function(member_fcns):
            for mf in member_fcns:
                if mf['name'] == 'make':
                    return mf
            return None

        make_function = find_make_function(member_functions)
except:
        make_function = None
%>
    py::class_<${cls['name']}, \
% if cls['bases']:
 ${cls['bases'][-1]},
% endif\
 
        std::shared_ptr<${cls['name']}>>(m, "${cls['name']}")

% if make_function: ## override constructors with make function
<%
fcn = make_function
fcn_args = fcn['arguments']
%>\
        .def(py::init(&${cls['name']}::${make_function['name']})${',' if fcn_args else ''}
% for arg in fcn_args:
           py::arg("${arg['name']}")${" = " + arg['default'] if arg['default'] else ''}${'' if loop.index == len(fcn['arguments'])-1 else ',' } 
% endfor
        )
        
% else:
% for fcn in constructors:
<%
fcn_args = fcn['arguments']
%>\
\
% if len(fcn_args) == 0:
        .def(py::init<>())
%else:
        .def(py::init<\
% for arg in fcn_args:
${arg['dtype']}${'>(),' if loop.index == len(fcn['arguments'])-1 else ',' }\
% endfor ## args
\
% for arg in fcn_args:
           py::arg("${arg['name']}")${" = " + arg['default'] if arg['default'] else ''}${'' if loop.index == len(fcn['arguments'])-1 else ',' } 
% endfor
        )
% endif
% endfor ## constructors
% endif ## make

% for fcn in member_functions:
<%
fcn_args = fcn['arguments']
%>\
% if fcn['name'] != 'make':
% if len(fcn_args) == 0:
        .def("${fcn['name']}",&${cls['name']}::${fcn['name']})
%else:
        .def("${fcn['name']}",&${cls['name']}::${fcn['name']},
% for arg in fcn_args:
            py::arg("${arg['name']}")${" = " + arg['default'] if arg['default'] else ''}${'' if loop.index == len(fcn['arguments'])-1 else ',' } 
% endfor ## args
        )
% endif
% endif ## Not a make function
% endfor ## member_functions

        ;
% endfor ## classes

% if free_enums:
% for en in free_enums:
<%
values = en['values']
%>\
    py::enum_<${en['name']}>(m,"${en["name"]}"))
% for val in values:
        .value("${val[0]}", ${"::".join(namespace)}::${val[0]}) // ${val[1]}
% endfor \
        .export_values()
    ;
% endfor
% endif

% if free_functions:
% for fcn in free_functions:
<%
fcn_args = fcn['arguments']
fcn_name = fcn['name']
matcher = lambda x,name: x['name'] == name
overloaded = sum([matcher(f,fcn_name) for f in free_functions]) > 1
## if overloaded:
## void (block_detail::*)(std::vector<gr::tag_t>&,
##                                      unsigned int,
##                                      uint64_t,
##                                      uint64_t,
##                                      const pmt::pmt_t&,
##                                      long))
##     overloaded_str = 'void (block_detail::*)(std::vector<gr::tag_t>&,
##                                      unsigned int,
##                                      uint64_t,
##                                      uint64_t,
##                                      const pmt::pmt_t&,
##                                      long))
## Need to put the return type in the json
%>\
% if len(fcn_args) == 0:
    m.def("${fcn['name']}",&${'::'.join(namespace)}::${fcn['name']});
%else:
    m.def("${fcn['name']}",&${'::'.join(namespace)}::${fcn['name']},
% for arg in fcn_args:
        py::arg("${arg['name']}")${" = " + arg['default'] if arg['default'] else ''}${'' if loop.index == len(fcn['arguments'])-1 else ',' } 
% endfor
    );
% endif
% endfor
% endif ## free_functions
} 

#endif /* INCLUDED_${'_'.join(namespace).upper()}_${basename.upper()}_PYTHON_HPP */
