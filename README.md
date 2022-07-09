# Тестовый проект для проверки платы STC8H1K08-TSSOP20 и инструкция по началу работы с семейством данных МК.  
На плате присутствует отладочный светодиод на P1.2. Данный код циклично зажигает и гасит его (реализация blink).  

## Подготовка среды и первое `firmware`. 
1. Установить `keil` (4 или 5 версии, обе проверены и отлично работают) и компилятор `C51`.  
2. Загрузить и распаковать библиотеки и примеры `STC8G-STC8H-LIB-DEMO-CODE-20220509.zip` ([из этого репозитория](https://github.com/AlexanderChad/blink_STC8G-STC8H/blob/main/Files/STC8G-STC8H-LIB-DEMO-CODE-20220509.zip) или [с официального сайта](http://www.stcmcudata.com/STC8F-DATASHEET/STC8G-STC8H-LIB-DEMO-CODE-20220509.zip)).  
3. Загрузить и распаковать средство программирования `stc-isp-15xx-v6.90.zip` ([из этого репозитория](https://github.com/AlexanderChad/blink_STC8G-STC8H/blob/main/Files/stc-isp-15xx-v6.90.zip) или [с официального сайта](http://www.stcmcudata.com/STCISP/stc-isp-15xx-v6.90.zip)).  
4. Добавить поддержку МК в keil:
    <details><summary>Перейти во вкладку <b><i>Keil ICE Settings</b></i></summary>
    
    ![Keil ICE Settings](https://github.com/AlexanderChad/blink_STC8G-STC8H/blob/main/Files/stc-isp_to_keil.png "stc-isp-15xx-v6.90")</details>  
    <details><summary>Нажать на кнопку <b><i>Add MCU type to Keil Add STC ICE driver to Keil</b></i> и указать папку с <b><i>Keil</b></i></summary>
    
    ![Keil ICE Settings](https://github.com/AlexanderChad/blink_STC8G-STC8H/blob/main/Files/stc-isp_to_keil_dialog.png "stc-isp-15xx-v6.90")</details>  
    <details><summary>Готово!</summary>
    
    ![Keil ICE Settings](https://github.com/AlexanderChad/blink_STC8G-STC8H/blob/main/Files/stc-isp_to_keil_add_ok.png "stc-isp-15xx-v6.90")</details>  
5. Создать новый проект:  
    <details><summary>Выбрать <b><i>STC MCU Database</b></i></summary>
    
    ![Step new project](https://github.com/AlexanderChad/blink_STC8G-STC8H/blob/main/Files/keil_stc_sel.png "keil")</details>  
    <details><summary>Из появившегося списка выбрать необходимый МК</summary>
    
    ![Step new project](https://github.com/AlexanderChad/blink_STC8G-STC8H/blob/main/Files/keil_stc_sel_mcu.png "keil")</details>  
    <details><summary>Согласится с копированием в новый проект стандартного кода запуска 8051</summary>
    
    ![Step new project](https://github.com/AlexanderChad/blink_STC8G-STC8H/blob/main/Files/keil_stc_ssc.png "keil")</details>  
    <details><summary>Добавить библиотеки из папки <b><i>¬т¦п¦¤</b></i> архива <b><i>STC8G-STC8H-LIB-DEMO-CODE-20220509.zip</b></i> в папку с проектом</summary>
    
    ![Step new project](https://github.com/AlexanderChad/blink_STC8G-STC8H/blob/main/Files/keil_stc_add_lib.png "keil")</details>  
    <details><summary>Включить вывод в <b><i>hex</b></i></summary>
    
    * Открыть настройки компиляции `Options for Target 'Target 1'...` из вкладки `Project` или комбинацией `Alt+F7`  
    ![Step new project](https://github.com/AlexanderChad/blink_STC8G-STC8H/blob/main/Files/keil_stc_set_t.png "keil")  
    * Во вкладке `Output` установить галочку на пункте `Create HEX File` (HEX Format: HEX-80)  
    ![Step new project](https://github.com/AlexanderChad/blink_STC8G-STC8H/blob/main/Files/keil_stc_set_hex.png "keil")  
    </details>  
    
6. Запустить компиляцию кнопкой `Build target` из вкладки `Project` или клавишей `F7`
7. Загрузить firmware в МК:  
    * Открыть `STC-ISP` и загрузить файл кнопкой `Open Code File`   
        * Дополнительно можно установить галочки `Auto reload the target file` и `Reload and download when target file is modified`, 
        благодаря которым открывать и загружать новую версию firmware каждый раз после компиляции не потребуется. 
        Программа сама обнаружит изменения и перейдет в режим загрузки.  
    * Подключить USB-UART переходник и выбрать его в выпадающем меню сверху (при необходимости обновить список кнопкой `Scan Port`)</details>  
    * Нажать `Download/Program`  
    * Подключить к USB-UART переходнику МК, после чего произойдет проверка и загрузка.  
    

**Firmware обновлено!**  
А с данным кодом на плате начнет кратко мигать с частотой около 1Гц светодиод.  
<p align="center" width="100%">
    <img width="100%" src="https://github.com/AlexanderChad/blink_STC8G-STC8H/blob/main/Files/blink-stc8h1k08.gif" alt="blink" title="STC8H1K08-TSSOP20">
</p>
