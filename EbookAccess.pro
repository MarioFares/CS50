QT += core gui sql printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

SOURCES += \
    source/addbookdialog.cpp \
    source/addbooksdialog.cpp \
    source/bulkdetailsdialog.cpp \
    source/cleanebooksdialog.cpp \
    source/common.cpp \
    source/extselectiondialog.cpp \
    source/main.cpp \
    source/mainwindow.cpp \
    source/queries.cpp \
    source/searchnamedialog.cpp \
    source/yesnodialog.cpp


HEADERS += \
    headers/addbookdialog.h \
    headers/addbooksdialog.h \
    headers/bulkdetailsdialog.h \
    headers/cleanebooksdialog.h \
    headers/common.h \
    headers/extselectiondialog.h \
    headers/mainwindow.h \
    headers/queries.h \
    headers/searchnamedialog.h \
    headers/yesnodialog.h


FORMS += \
    forms/addbookdialog.ui \
    forms/addbooksdialog.ui \
    forms/bulkdetailsdialog.ui \
    forms/cleanebooksdialog.ui \
    forms/extselectiondialog.ui \
    forms/mainwindow.ui \
    forms/searchnamedialog.ui \
    forms/yesnodialog.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    resources/icons/add_book_icon.png \
    resources/icons/add_books_icon.png \
    resources/icons/add_collection_icon.png \
    resources/icons/add_folder_icon.png \
    resources/icons/add_new_icon.png \
    resources/icons/add_user_icon.png \
    resources/icons/arrow.png \
    resources/icons/books_icon.png \
    resources/icons/clean_icon.png \
    resources/icons/clear_icon.png \
    resources/icons/clear_search_white_icon.png \
    resources/icons/database_icon.png \
    resources/icons/exit_fullscreen.png \
    resources/icons/feedback_icon.png \
    resources/icons/fullscreen_icon.png \
    resources/icons/github_icon.png \
    resources/icons/gmail_icon.png \
    resources/icons/icon.ico \
    resources/icons/info_icon.png \
    resources/icons/link_icon.png \
    resources/icons/minimize_icon.png \
    resources/icons/puzzle_icon.png \
    resources/icons/reset_database_icon.png \
    resources/icons/save_icon.png \
    resources/icons/search_icon.png \
    resources/icons/searchbar_icon.png \
    resources/icons/settings_icon.png \
    resources/icons/sort_icon.png \
    resources/icons/tags_icon.png \
    resources/icons/up-arrow.png \
    resources/icons/upload_icon.png \
    resources/styles/style.qss \
    resources/styles/summarystyle.qss \
    resources/styles/textEditorStyle.qss


RESOURCES += \
    resources/images.qrc \
    resources/style.qrc


RC_ICONS = ./resources/icons/icon.ico


