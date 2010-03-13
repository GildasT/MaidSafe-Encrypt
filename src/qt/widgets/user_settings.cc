/*
 * copyright maidsafe.net limited 2009
 * The following source code is property of maidsafe.net limited and
 * is not meant for external use. The use of this code is governed
 * by the license file LICENSE.TXT found in the root of this directory and also
 * on www.maidsafe.net.
 *
 * You are not free to copy, amend or otherwise use this source code without
 * explicit written permission of the board of directors of maidsafe.net
 *
 *  Created on: Jan 23, 2010
 *      Author: Stephen Alexander
 */
#include "qt/widgets/user_settings.h"

#include <QMessageBox>
#include <QDebug>

#include "qt/client/client_controller.h"

UserSettings::UserSettings(QWidget* parent) {
  ui_.setupUi(this);

  createSettingsMenu();

  personal_     = new PersonalSettings;
  vault_        = new VaultInfo;
  fileTransfer_ = new FileTransferSettings;
  security_     = new SecuritySettings;
  connection_   = new ConnectionSettings;
  profile_      = new ProfileSettings;

  ui_.stackedWidget->addWidget(personal_);
  ui_.stackedWidget->addWidget(vault_);
  ui_.stackedWidget->addWidget(fileTransfer_);
  ui_.stackedWidget->addWidget(security_);
  ui_.stackedWidget->addWidget(connection_);
  ui_.stackedWidget->addWidget(profile_);

  ui_.stackedWidget->setCurrentWidget(personal_);

  connect(ui_.settingsMenuList, SIGNAL(currentRowChanged(int)),
          this,           SLOT(onCurrentRowChanged(int)));
  QPushButton* OkButton = ui_.buttonBox->button(QDialogButtonBox::Ok);
  connect(OkButton, SIGNAL(clicked()), this, SLOT(HandleOK()));

  QPushButton* CancelButton = ui_.buttonBox->button(QDialogButtonBox::Cancel);
  connect(CancelButton, SIGNAL(clicked()), this, SLOT(HandleCancel()));

  QPushButton* applyButton = ui_.buttonBox->button(QDialogButtonBox::Apply);
  connect(applyButton, SIGNAL(clicked()), this, SLOT(HandleApply()));
}

UserSettings::~UserSettings() {}

void UserSettings::onCurrentRowChanged(int index) {
  switch (index) {
    case 0:
      setState(PERSONAL);
      break;
    case 1:
      setState(CONNECTION);
      break;
    case 2:
      setState(FILE_TRANSFER);
      break;
    case 3:
      setState(SECURITY);
      break;
    case 4:
      setState(VAULT_INFO);
      break;
    case 5:
      setState(PROFILE);
      break;
  }
}

void UserSettings::createSettingsMenu() {
  ui_.settingsMenuList->addItem("Personal");
  ui_.settingsMenuList->addItem("Connection");
  ui_.settingsMenuList->addItem("File Transfer");
  ui_.settingsMenuList->addItem("Security");
  ui_.settingsMenuList->addItem("Vault Info");
  ui_.settingsMenuList->addItem("Profile");
}

void UserSettings::setState(State state) {
  state_ = state;

  switch (state_) {
    case PERSONAL:
    {
      ui_.stackedWidget->setCurrentWidget(personal_);
      personal_->setActive(true);
      break;
    }
    case CONNECTION:
    {
      ui_.stackedWidget->setCurrentWidget(connection_);
      break;
    }
    case FILE_TRANSFER:
    {
      ui_.stackedWidget->setCurrentWidget(fileTransfer_);
      break;
    }
    case SECURITY:
    {
      ui_.stackedWidget->setCurrentWidget(security_);
      break;
    }
    case VAULT_INFO:
    {
      ui_.stackedWidget->setCurrentWidget(vault_);
      vault_->setActive(true);
      break;
    }
    case PROFILE:
    {
      ui_.stackedWidget->setCurrentWidget(profile_);
      profile_->setActive(true);
      break;
    }
    default:
    {
      break;
    }
  }
}

void UserSettings::HandleOK() {
  bool applied;
  if (!personal_->changedValues_.isEmpty()) {
    QHash<QString, QString> theHash = personal_->changedValues_;

    if (theHash.contains("username")) {
      applied = ClientController::instance()->ChangeUsername(
                theHash.value("username").toStdString());
    }
    if (theHash.contains("message")) {
    }
    if (theHash.contains("changedpic")) {
    }
  }
  if (!fileTransfer_->changedValues_.isEmpty()) {
  }
  if (!connection_->changedValues_.isEmpty()) {
  }
  if (!security_->changedValues_.isEmpty()) {
  }
  if (!profile_->changedValues_.isEmpty()) {
    QHash<QString, QString> theHash = profile_->changedValues_;

    std::vector<std::string> profileInfo;

    //QDebug(*theHash.value("PubName"));
    profileInfo.push_back(theHash["FullName"].toStdString());
    profileInfo.push_back(theHash["Phone"].toStdString());
    profileInfo.push_back(theHash["BirthDay"].toStdString());
    profileInfo.push_back(theHash["Gender"].toStdString());
    profileInfo.push_back(theHash["Language"].toStdString());
    profileInfo.push_back(theHash["City"].toStdString());
    profileInfo.push_back(theHash["Country"].toStdString());

    int n = ClientController::instance()->SetInfo(profileInfo);

    QMessageBox::warning(this, tr("Set Info Warning"),
                        QString(tr("Result. %1").arg(n)));
  }
}

void UserSettings::HandleApply() { }

void UserSettings::HandleCancel() { }