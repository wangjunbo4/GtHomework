# GtHomework

一个可能没有什么用的各种管理系统大作业库，致力于30行完成一个大作业   
如果想使用全部功能请使用支持C++17或以上版本的编译器

## 模块

### sys
#### Opt - 界面选项类
+ void setCallback(callback func) 设置回调函数
+ void exec() 执行回调函数
#### Sys - 界面类
+ void menu() 显示主界面
+ void usersAccountCtrl(bool isAble) 是否启用账号登录功能
+ login() 登录，返回成功/失败
+ void setTitle(std::string title) 设置系统标题
+ void addOptions(Opt option) 添加菜单选项
+ void addOptions(std::string text, callback func) 添加菜单选项
+ void waitOption() 等待和捕获键盘输入
+ void cls() 清屏
### list - 可变参链表模板类
### Util
+ tuple_index(const std::tuple<T...> &tpl, size_t i) 访问元组tpl中的第i个元素
### Node
+ Node() 无参数构造
+ Node(Ts... args) 接受数据的构造
+ Node(Node *next, Ts... args) 初始化next成员的构造
+ inline void setNext(Node *next) 设置next节点
+ void print() 打印当前对象数据
+ static void printAll(Node *head) 从head打印之后的所有数据
+ static inline void setSeperator(std::string s) 设置打印分隔符（默认"\t\t\t"）
+ static void push_back(Node *head, Node *data) 
+ static void push_here(Node *node, Node *data) 
+ static Node<Ts...>* push_front(Node *head, Node *data) 头插，返回新头

// TODO:

+ static void sort(Node *head) 排序
+ static void modify(Node *node) 修改
+ static void del(Node *node) 删除
+ static void search(Ts..., int index) 查找


### file - 模板化文件读写
