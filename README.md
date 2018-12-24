# Qt5 Notepad project convert to CLion project.

## Qt GUI开发的两种方式
- Qt Widgets Application->c++
- Qt Quick->qml（qml语言编程，局限性和性能不如传统c++方式，不做介绍）

## CLion+Qt Creator开发Workflow
CLion负责c++编程，Qt Creator负责界面设计（.ui文件）。新建一个项目时，基本步骤：

- 1.Qt Creator创建设计师文件.ui文件，同时生成对应.h和.cpp文件（自动关联）
- 2.在CLion CMakeLists.txt中配置好Qt Lib和Resources引用
- 3.External Tools | uic 生成ui_foo.h文件，引用即可。


## Qt Designer面板介绍

- 主工作面板（预览和编辑）
- 控件面板（展示所有可选空间，可拖拽添加到主工作区）
- 对象面板（展示界面组件对象及关系，对象名必须唯一）
- 属性面板（当选中某个对象、组件时，属性面板会对应显示其属性；同时类的继承关系）
- 工具面板

### 继承关系
QObject->QWidget->QMainWindow等

其中任何可见的组件均继承自QWidget