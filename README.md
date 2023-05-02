<p align=center>
  <a href="https://os.huang2.cn">
    <img alt="ReactOS" src="https://dl3.img.timecdn.cn/2023/04/29/logo.png">
  </a>
</p>

---


# ROSBE安装：
<img src="https://dl3.img.timecdn.cn/2023/04/21/SVR9NAGVKBA9_U7V.png">

### （注:图片中此位置为源码目录，下载后源码解压位置应相符）

# ROSBE应用：

安装完后会在桌面生成几个快捷图标。选择ReactOS Build Environment 

```configure.cmd

cd output-MinGW-i386

make

ninja bootcd或ninja livecd或ninja hybridcd
```
# 编译：

## 安装界面          
```
第一部分安装界面         boot目录下bootcd,bcd,bgfx
第二部分安装界面         reactos\dll\win32\syssetup\          
第二部分安装界面         base\setup\       
```

## 蜘蛛纸牌          
```
reactos\dll\win32\cards\res
```

## 主题UI           
```
reactos\media
```
## 系统自带壁纸         
```
modules\wallpapers           须全部由UI部修改
```

## base\目录下的系统自带软件：ico文件替换需保持原尺寸大小，否则在编译后进入系统图标会无法显示

## //所有bmp,png.ico文件替换必须保持原尺寸大小，否则在编译后进入系统图标会无法显示或异常
