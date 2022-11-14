# WallpapperManager
## 实现：
基本实现如下
1.建立了寻找文件夹内.jpg格式图片文件名的函数
2.存储寻找到的图片文件路径的函数
3.有一个输入函数用以作为参考
问题：
1.针对上面第二点，目前没有查重后不用存储的方案。（因为C++打开文件可以选择文件模式为截断模式，但如果是截断模式就会导致文件每一次打开都被变成0）
2.根据存储的路径进行壁纸切换。
## 需求分析
### 1.可以选定多个目录，在多个目录内能搜集图片（软件可以识别出图片的尺寸）。
1-1 选定多个目录
1-2 每次增删新的图片，不能用全文件夹扫描，只需了解增加的和删除的。（需要解决）每扫描到一张图片，存储路径。
1-3 通过1-2存储的路径自动进行壁纸更换。
1-4 每一次运行程序可以通过控制台进行重新扫描文件夹。
1-5 可以设定壁纸更换时间间隔。
1-6 识别图片尺寸、码率、文件大小。对文件码率较小的文件，予以抛弃。
1-7 控制台提供选项，对更换壁纸方式进行控制。
### 2.针对每一张图片，可以有不同的tag用来进行分类，一张图片可以有很多个tag。（交并补功能）
### 3.可以通过多种方式选中一批图片进行播放：通过选中不同的tag、手动选择图片、建立收藏夹。
### 4.播放问题：播放顺序：顺序、乱序、循环。时间差选择。
## GUI：
1.并且图片可以在GUI内进行演示。（需要有缩略图、缩略图概览的放大和缩小）
2.通过选择不同的标签，展示不同的图片。
3.分组栏：选中之后展示不同组的图片。