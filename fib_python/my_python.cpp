#include <Python.h>

int fib_from_python(int a); 

int main(int argc, char *argv[]) {
    Py_Initialize();
    printf("%d\n",fib_from_python(2));
    Py_Finalize();
	system("pause");
	return 0;
}

int fib_from_python(int a) {
    int res;
    PyObject *pModule,*pFunc;
    PyObject *pArgs, *pValue;
    
    /* import */
	pModule = PyImport_Import(PyUnicode_FromString("fib_module"));

    /* great_module.great_function */
    pFunc = PyObject_GetAttrString(pModule, "fib"); 
    
    /* build args */
    pArgs = PyTuple_New(1);
	PyTuple_SetItem(pArgs, 0,PyLong_FromLong(a));
      
    /* call */
    pValue = PyObject_CallObject(pFunc, pArgs);
    
    res = PyLong_AsLong(pValue);
    return res;
}
