/*************
 WordCount 
 Lan-xiaobo
 2019.10.21
************/

项目简介：命令行文本计数统计程序，能正确统计导入的纯英文txt文本中的字符数，单词数，句子数。

用法：命令模式： wc.exe [参数] [文件名]
          例：WC.exe -c file.txt 统计字符数
                 WC.exe -w file.txt 统计单词数
                 WC.exe -L file.txt 统计行数

代码源文件在code文件夹下，测试文件在test文件夹下

测试结果:
   文件测试：
      test1——纯英文txt文本：结果正确
      test2——在test1的基础上每行最后多加一个空格一个数字：数字会被计为1个字符，空格不计。但都不计入单词数
      test3——在test1的基础上每行最后多加一个空格一个汉字：汉字会被计为2个字符，但都不计入单词数
      test4——在test1的基础上每行最后多加一个空格一个英文符号：英文符号会被计为1个字符，只有_被计入单词数
      test5——在test1的基础上同一行每个单词之间多加若干个空格：结果与test1一样
      test6——有连续多个空行：空行会被正确计入行数
      test7——无内容的文本：字符数1，单词数0，行数1
      
   输入测试：
       WC.exe -wc test1.txt	正常统计单词数
       WC.exe -cwdf test1.txt	正常统计字符数
       WC.exe -a test1.txt	报错：Type input error
       WC.exe -c [不正确的文件名]：程序报错：Assertion failed: file != NULL,
