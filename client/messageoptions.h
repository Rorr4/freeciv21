/**************************************************************************
 Copyright (c) 1996-2020 Freeciv21 and Freeciv contributors. This file is
 part of Freeciv21. Freeciv21 is free software: you can redistribute it
 and/or modify it under the terms of the GNU  General Public License  as
 published by the Free Software Foundation, either version 3 of the
 License,  or (at your option) any later version. You should have received
 a copy of the GNU General Public License along with Freeciv21. If not,
 see https://www.gnu.org/licenses/.
**************************************************************************/
#pragma once

// Qt
#include <QWidget>

class QTableWidget;
class QGridLayout;

/**************************************************************************
  Widget for displaying messages options
**************************************************************************/
class message_dlg : public QWidget {
  Q_OBJECT
  QTableWidget *msgtab;
  QGridLayout *layout;

public:
  message_dlg();
  ~message_dlg() override;
  void fill_data();
private slots:
  void apply_changes();
  void cancel_changes();
};

void popup_messageopt_dialog(void);
