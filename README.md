# whq-assignments
课程作业仓库

ex01:
1.  v1：基础HelloWorld，控制台输出
2.  v2：新增scanf键盘输入，读取用户姓名并输出

---

## lab01: ESP32 点灯实验

### 实验环境
- 开发工具：VSCode + PlatformIO IDE
- 开发框架：Arduino（for ESP32）
- 开发板：ESP32 Dev Module
- 核心功能：控制板载LED周期性闪烁，同时通过串口输出调试信息。

### 实现说明
1.  核心代码文件：`blink_Arduino/src/main.cpp`
2.  功能描述：
    - 初始化串口通信（波特率115200）
    - 将GPIO2配置为输出模式
    - 通过循环实现LED亮灭交替（亮1秒、灭1秒）
    - 每次状态切换时，通过串口打印提示信息
