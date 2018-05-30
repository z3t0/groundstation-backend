from cffi import FFI
ffibuilder = FFI()

with open('implementation.c', 'r') as f:
    implementation = f.read()

with open('definition.c', 'r') as f:
    definition = f.read()

ffibuilder.set_source("api", implementation, 
        libraries=[])

ffibuilder.cdef(definition)

ffibuilder.compile(verbose=True)

# ffi.cdef(src)
# C = ffi.dlopen(None)
# arg = ffi.new("char *", data)

# C.parse_frame(arg)
