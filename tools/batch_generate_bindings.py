import gen_nonblock_bindings
import os
import argparse

import warnings
with warnings.catch_warnings():
    warnings.filterwarnings("ignore",category=DeprecationWarning)
    import time


include_path = '/share/gnuradio/grnext/src/gnuradio/gnuradio-runtime/include/gnuradio'
output_dir = '/share/tmp/blocktool_pybind'
namespace = ['gr']

def get_file_list(include_path):
    file_list = []
    for root, dirs, files in os.walk(include_path):
        path = root.split(os.sep)
        print((len(path) - 1) * '---', os.path.basename(root))
        for file in files:
            print(len(path) * '---', file)
            _, file_extension = os.path.splitext(file)
            if (file_extension == '.h'):
                pathname = os.path.join(root,file)
                print(pathname)
                file_list.append(pathname)
    return file_list
                    
                                        
file_list = get_file_list(include_path)
for fn in file_list:
    args = argparse.Namespace(filename=fn, output=output_dir, 
        prefix='/share/gnuradio/grnext',namespace=namespace)
    gen_nonblock_bindings.process_file(args)