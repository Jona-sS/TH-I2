TEMPLATE = subdirs

CONFIG += silent

SUBDIRS += app lib

app.depends = lib
