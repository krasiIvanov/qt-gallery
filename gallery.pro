TEMPLATE = subdirs

SUBDIRS += \
    gallery-lib \
    gallery-ui

!build_pass:message(cm project dir: $${PWD})
