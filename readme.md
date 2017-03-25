### fib_python
在Windows平台下，打开Visual Studio命令提示符
打开Visual Studio命令提示符,`cd`到当前目录
通过指定 python的include 和libs目录进行`cl` 即可生成.exe 

```
cl my_python.cpp -ID:\Python34\include D:\Python34\libs\python34.lib
```



在Linux下编译命令为
```
gcc my_python.c -o my_python -I/usr/include/python2.7/ -lpython2.7
```

**非python3.X注意**
如果使用的是python2.X则需要修改my_python.c：

因为在Python3.X之后 
`PyString_` functions were renamed to `PyBytes_`.
`PyInt_` functions are gone, `PyLong_` should be used instead.

所以

`PyString_FromString`(2.X)  -->  `PyBytes_FromString`(3.X)
`PyInt_FromLong`(2.X) -->  `PyLong_FromLong`(3.X)


in python3.6, it's using `PyUnicode_` instead of `PyString_/PyBytes_`.  
 In many places where Python 2.x used byte strings, Python 3.x uses unicode strings.

---

### fib_Cython

安装Cython。
由于安装的过程需要编译Cython的源代码,如果python是3.X,在Windows环境下需要在Visual Studio命令提示符下完成。一会儿使用Cython的时候，也需要在Visual Studio命令提示符下进行操作。

```
easy_install -U cython
```


.pyx是属于Cython定义的文件，里面`cdef`、`public`都是其关键字,由于需要在C中使用编译好的Python代码,所以使得`great_function`从外变得可见，所以用`public`修饰

之后用Cython编译`xxx.pyx`
```
cython xxx.pyx
```

生成`xxx.c`和`xxx.h`文件。

用VS新建项目添加`xxx.h`、`xxx.c`和`main.c`文件即可编译生成`.exe`