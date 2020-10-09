# music_stampede
---
qt_2020夏季团队课设
成员：**程一浩**  ， **傅沐晖** ， **况宇**

## 2020-09-11 上传第一个demo

完成功能：

* 方块随计时器落下
* 根据按键按下的时机输出结果
* 读取写好的txt文件控制方块的生成

## 2020-9-16 更新  demo 2.0

实现功能：

* 添加音乐，播放音乐
* 增加砖块掉落的不同类型，闪烁，长条等。
* 添加主界面和游戏界面的素材

修改：

* 创建musicown类，对应音乐播放，txt读取的功能
* 创建mylabel类，对应掉落的方块的颜色，掉落类型等。
* 调整界面布局

## 2020-09-21 更新 demo 3.0

修改：

* 添加砖块消除的动画
* 添加评分动画
* 优化界面布局
* 调整砖块掉落顺序与时机

## 2020-09-26 更新 demo 4.0

修改：

* 添加素材
* 调整界面布局
* 优化读取txt的方法，使得方块可以在非整数秒时落下。

debug：

问题：

方块在消除的时候，有时候会因为没有判断位置是否合适而导致消除动画一直播放下去。 影响其他方块的下落

解决办法：

在每次消除方块的时候判断是否在消除范围之内。

## 2020-10-2  更新 demo 5.0

修改：

* 更新连击功能
* 在连击数超过一定数量的时候，方块不会稳定的下落，给玩家造成轻微的干扰。


## 2020-10-7  更新 demo 6.0

修改：

* 区分normal模式和hard模式
* 新添加连击素材的显示
* 新编第一首歌曲的txt文件
