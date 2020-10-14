# lab1实验报告
**周庆----PB18111786**

##  实验要求

本次实验需要根据`cminux-f`的词法补全[lexical_analyer.l](./src/lexer/lexical_analyzer.l)文件，完成词法分析器，能够输出识别出的`token`，`type` ,`line(刚出现的行数)`，`pos_start(该行开始位置)`，`pos_end(结束的位置,不包含)`。如：

文本输入：

```c
int a
```

则识别结果应为：

```shell
int   280   1    2    5
a    284   1    6    7
;    270   1    7    8
```

具体的需识别token参考[lexical_analyzer.h](./include/lexical_analyzer.h)



**特别说明对于部分token，我们只需要进行过滤，即只需被识别，但是不应该被输出到分析结果中。因为这些token对程序运行不起到任何作用。**



*>* 注意，所需修改的文件应仅有[lexical_analyer.l](./src/lexer/lexical_analyzer.l)。关于`FLEX`用法上文已经进行简短的介绍，更高阶的用法请参考百度、谷歌和官方说明。



**1.1 目录结构**


整个`repo`的结构如下

```shell

.

├── CMakeLists.txt

├── Documentations

│  └── lab1

│    └── README.md <- lab1实验文档说明

├── READMD.md

├── Reports

│  └── lab1

│    └── report.md <- lab1所需提交的实验报告（你需要在此提交实验报告）

├── include <- 实验所需的头文件

│  └── lexical_analyzer.h 

├── src <- 源代码

│  └── lexer

│    ├── CMakeLists.txt

│    └── lexical_analyzer.l  <- flex文件，lab1所需完善的文件

└── tests <- 测试文件

  └── lab1

​    ├── CMakeLists.txt

​    ├── main.c  <- lab1的main文件

​    ├── test_lexer.py

​    ├── testcase <- 助教提供的测试样例

​    └── TA_token <- 助教提供的关于测试样例的词法分析结果

```



**1.2 编译、运行和验证**



`lab1`的代表大部分由`C`和`python`构成，使用`cmake`进行编译。



**编译**

```shell
 #进入workspace
 $ cd 2020fall-Compiler_CMinus
 #创建build文件夹，配置编译环境
 $ mkdir build 
 $ cd build
 $ cmake ../
 #开始编译
 $ make
```



 编译成功将在`${WORKSPACE}/build/`下生成`lexer`命令


 **运行**



 ```shell
 $ cd 2020fall-Compiler_CMinus
 # 运行lexer命令
 $ ./build/lexer
 usage: lexer input_file output_file
 # 我们可以简单运行下 lexer命令，但是由于此时未完成实验，当然输出错误结果
 $ ./build/lexer ./tests/lab1/testcase/1.cminus out
 [START]: Read from: ./tests/lab1/testcase/1.cminus
 [ERR]: unable to analysize i at 1 line, from 1 to 1
 ......
 ......
 ......
 ......
 $ head -n 5 out
 [ERR]: unable to analysize i at 1 line, from 1 to 1   258   1    1    1
 [ERR]: unable to analysize n at 1 line, from 1 to 1   258   1    1    1
 [ERR]: unable to analysize t at 1 line, from 1 to 1   258   1    1    1
 [ERR]: unable to analysize   at 1 line, from 1 to 1   258   1    1    1
 [ERR]: unable to analysize g at 1 line, from 1 to 1   258   1    1    1
 ```
 助教们提供了`./tests/lab1/test_lexer.py` python脚本用于调用`lexer`批量完成分析任务。


 ```shell
 # test_lexer.py脚本将自动分析./tests/lab1/testcase下所有文件后缀为.cminus的文件，并将输出结果保存在./tests/lab1/token文件下下
 $ python3 ./tests/lab1/test_lexer.py

  ···

  ···

  ···
 #上诉指令将在./tests/lab1/token文件夹下产生对应的分析结果
 $ ls ./tests/lab1/token
 1.tokens 2.tokens 3.tokens 4.tokens 5.tokens 6.tokens
 ```


**验证**
 使用`diff`指令进行验证。将自己的生成结果和助教提供的`TA_token`进行比较。


 ```shell
 $ diff ./tests/lab1/token ./tests/lab1/TA_token
 # 如果结果完全正确，则没有任何输出结果
 # 如果有不一致，则会汇报具体哪个文件哪部分不一致
 ```


 **请注意助教提供的`testcase`并不能涵盖全部的测试情况，完成此部分仅能拿到基础分。还需要设计自己的`testcase`进行测试。**

**1.3 提交要求和评分标准**


* **提交要求**

  本实验的提交要求分为两部分：实验部分的文件和报告，git提交的规范性。
  * **实验部分**:
    * 需要完善`./src/lab1/lexical_analyer.l`文件;
    * 需要在`./Report/lab1/report.md`撰写实验报告。
      * 实验报告内容包括:
      * 实验要求、实验难点、实验设计、实验结果验证、实验反馈(具体参考[report.md](./Reports/lab1/report.md));
      * 实验报告不参与评分标准，但是必须完成并提交.

  * **git提交规范**：
    * 不破坏目录结构;
    * 不上传临时文件(凡是自动生成的文件和临时文件请不要上传，包括`lex.yy.c`文件以及自己生成的`tokens`文件);
    * git log言之有物(不强制, 请不要git commit -m 'commit 1', git commit -m 'sdfsdf'，每次commit请提交有用的comment信息)


* **评分标准**
  
  * git提交规范(20分);
  * 实现词法分析器并通过给出的6个测试样例(一个10分，共60分);
  * 提交后通过助教进阶的多个测试用例(20分)。


* **迟交规定**
  
  * `Soft Deadline` : 2020.10.12 23:59 
  * `Hard Deadline` : before 2020.10.19 23:59


* **关于抄袭和雷同**
  * 经过助教和老师判定属于作业抄袭或雷同情况，所有参与方一律零分，不接受任何解释和反驳。
## 实验难点
  * 首次使用flex工具而对完善`./src/lab1/lexical_analyer.l`文件较为困惑
  * virtualbox虚拟机与本地的数据的共享有点麻烦，代码的编辑较为麻烦
  * 完善代码的时候需要理解好已有的代码和库
  * 对有关注释的正则表达式还存在一定的疑问
## 实验设计
  * 根据[lexical_analyzer.h](../../include/lexical_analyzer.h)中所给到的符号表来书写规则
    * 符号表中的运算符，逻辑运算符，关键字都可以直接进行匹配，如下：
    ``` lex
    "int" {return INT;} 
    ```
    这样就能将词法单元名返回到语法分析器
    * 符号表中的ID和数字的正则定义在[README.md](../../Documentations/lab1/README.md)中已经给出，注释的正则定义在作业中已经完成，其他内容可以直接进行匹配
    如下是规则的编写
    ``` lex
    letter [A-Za-z]
    digit [0-9]
    id {letter}({letter}|{digit})* 
    integer {digit}+
    float ({digit}+\.|{digit}*\.{digit}+)
    other [^*]
    other1 [^*/]
    comment [/]\*{other}*(\*\**{other1}{other}*)*\**\*[/] 
    ```
  * 根据已经提供的部分代码完善接下来的内容
    * [lexical_analyzer.h](../../include/lexical_analyzer.h)中已经定义了行数lines, pos_start, pos_end。这些是本次实验所需要的另一部分的内容，即记录词素的所在行数，词素开始和结束的位置。
    * [lexical_analyzer.l](../../src/lexer/lexical_analyzer.l)中，`strcpy(token_stream[index].text, yytext);`会将除注释，换行符，空格及制表符，错误外的词素的词法单元打印到所给定的输出文件中来，这之中会包括行数，词素的起始与结束的位置，这样就还需要补齐返回的内容如
    ``` lex
    "int" {pos_start = pos_end; pos_end = pos_start + yyleng; return INT;}
    ...
    "\n" {lines++; pos_start = 1; pos_end = 1; return EOL;}
    ```
    * yyleng是存放刚找到的词素的长度
    * 由于pos_end是词素的结束位置，不包括词素的最后一个，这样它也是下一个词素的起始位置，再加上下一个词素的长度，这就是下一个词素的结束位置
    * 只有遇到换行符的时候才会使得行数加一，同时还要对pos_start，pos_end进行重置
  * 由于考虑到注释当中也会有换行符，以及需要考虑到的其他的内容也会改变pos_start，pos_end。所以对注释要进行完善
    * 在完善的lex程序([lexical_analyzer.l](../../src/lexer/lexical_analyzer.l))当中，直接遍历了注释的内容，并据其而修改lines， pos_start, pos_end
    ``` lex
    while(yytext[i]) {
      if(yytext[i] == '\n') {
        lines++;
        pos_start = 1;
        pos_end = 1;
        i++;
        continue;
      }
      i++;
      pos_end++;	
    }
    ``` 
## 实验结果验证
* 编译
![avatar](./P1.png)
* 运行
![avatar](./P2.png)
* 自己所给的样例(test_me.cminus)
``` cminus
void sort(int a[], int l) /* 'a' is the address of array, and 
the 'l' is the length of array*/
{
    int i, j;
    int v;
    /*   the main of the sort*/
    i = 0;
    while (i < l - 1) {
        j = i + 1;
        while (j < l) {
            if(a[i] > a[j])
            /*if a[i] > a[j],the they will exchange*/
            {
                v = a[i];
                a[i] = a[j];
                a[j] = v;
            }
        j = j + 1;
        }
    i = i + 1;
    }
}
```
* 输出得到的结果--部分(test_me.tokens)
``` tokens
void	283	1	1	5
sort	285	1	6	10
(	272	1	10	11
int	280	1	11	14
a	285	1	15	16
[]	288	1	16	18
,	271	1	18	19
int	280	1	20	23
...
...
...
i	285	20	9	10
+	259	20	11	12
1	286	20	13	14
;	270	20	14	15
}	277	21	5	6
}	277	22	1	2
```
**具体查看[test_me.tokens](./test_me.tokens)**
* 批量运行所给的助教的样例
![avatar](./P3.png)
* 将自己得到的结果和助教提供的结果进行对比验证
![avatar](./P4.png)
  * 结果显示自己的结果和提供的结果是一致的
## 实验反馈
* virtualbox虚拟机的使用有着一定的麻烦