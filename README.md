#Среда разработки с транслятором

Для трансляции необходимо иметь исходные файлы *flex* и *bison*
Также нужно, чтобы компиляторы flex, byzon и gcc были добавлены в переменные среды
Необходимо, чтобы bison файл производился вывод в ##Стандартный поток вывода
Программа в режиме реального времени производит трансляцию 

Возможные проблемы:
1) Ввод(вывод) происходят не из stdin (не в stdout)
2) Изменено имя у подлючаемого в *.l bison заголовочный файла (default: parser.tab.h). Следовательно, в *.l файле, нужно поменять 
    #include "<name>.tab.h" --> #include "parser.tab.h"
