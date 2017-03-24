#include <Python.h>
#include "fib_cdef_module.h"

int main(int argc, char *argv[]) {
    Py_Initialize();
	printf("%d\n", PyLong_AsLong(
                fib(PyLong_FromLong(2))
				)
			);
    Py_Finalize();
	system("pause");
	return 0;
}
