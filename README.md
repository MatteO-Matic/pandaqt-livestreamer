#PandaTv QT livestreamer GUI
PandaTvQt is a graphical user interface for managing your favorite streams on panda.tv and play them in VLC through Chrippa's Livestreamer.
(img)

##Dependencies
You need to install livestreamer and add the PandaTv plugin.

[Livestreamer (by Chrippa)](http://docs.livestreamer.io/install.html)
[Livestreamer PandaTv plugin (by fatdeer)](https://raw.githubusercontent.com/fatdeer/livestreamer/add-pandatv-plugin/src/livestreamer/plugins/pandatv.py)
Save the file as pandatv.py in your livestreamer plugins folder.
Unix-like (POSIX)
```
$XDG_CONFIG_HOME/livestreamer/plugins
```
Windows
```
%APPDATA%\livestreamer\plugins
```
If the plugins folder doesn't exist, just create a new one.

##Features
* Browse streams
* Bookmark channels
* Get notifications when bookmarked streamer comes online

[Check out unofficial PandaTv API](https://github.com/MatteO-Matic/pandatvAPI)
